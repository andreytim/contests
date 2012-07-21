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
	private Fork[] lefts = new Fork[DEFAULT_SIZE];
	private Fork[] rights = new Fork[DEFAULT_SIZE];
	
	private WaiterService() {}
	
	public synchronized void clearingResize(int size) {
		latches = new CountDownLatch[size];
		lefts = new Fork[size];
		rights = new Fork[size];
	}
	
	public synchronized void registerMe(int id, Fork left, Fork right) {
		CountDownLatch latch = new CountDownLatch(2);
		latches[id] = latch;
		lefts[id] = left;
		rights[id] = right;
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
			return new Fork[]{ lefts[id], rights[id] };
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
