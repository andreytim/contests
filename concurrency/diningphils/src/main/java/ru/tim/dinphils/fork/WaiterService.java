package ru.tim.dinphils.fork;

import java.util.concurrent.CountDownLatch;

public class WaiterService 
{
	private static final int DEFAULT_SIZE = 10;
	private static final WaiterService INSTANCE = new WaiterService();
	public static WaiterService get() {
		return INSTANCE;
	}
	
	private CountDownLatch[] latches = new CountDownLatch[DEFAULT_SIZE];
	private Fork[][] forks = new Fork[DEFAULT_SIZE][2];
	
	private WaiterService() {}
	
	public synchronized void clearingResize(int size) {
		latches = new CountDownLatch[size];
		forks = new Fork[size][2];
	}
	
	public synchronized void registerMe(int id, Fork left, Fork right) {
		CountDownLatch latch = new CountDownLatch(2);
		latches[id] = latch;
		forks[id][0] = left;
		forks[id][1] = right;
		if ((id & 1) == 0) {
			latch.countDown();
			latch.countDown();
		}
	}
	
	public Fork[] serveMe(int id) {
		try {
			CountDownLatch latch = latches[id];
			latch.await();
			latches[id] = new CountDownLatch(2);	
			return forks[id];
		} catch (InterruptedException e) {
			throw new RuntimeException(e);
		}
	}
	
	public void leaveMe(int id) {
		int r = (id + 1) % latches.length,
			l = (id - 1 + latches.length) % latches.length;
		latches[l].countDown();
		latches[r].countDown();	
	}
}
