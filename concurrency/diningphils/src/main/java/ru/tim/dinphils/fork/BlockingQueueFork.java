package ru.tim.dinphils.fork;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import ru.tim.dinphils.phil.Philosopher;

public class BlockingQueueFork extends Fork 
{
	private BlockingQueue<Philosopher<BlockingQueueFork>> queue = new ArrayBlockingQueue<Philosopher<BlockingQueueFork>>(1);
	private Lock lock = new ReentrantLock();
	private Condition idSwitched = lock.newCondition();
	private int lastID = -1;
	
	public void pickUp(Philosopher<BlockingQueueFork> philosopher) {
		lock.lock();
		try {
			while (lastID == philosopher.getPosition()) {
				idSwitched.await();	
			}
			lastID = philosopher.getPosition();
			queue.put(philosopher);
			idSwitched.signal();
		} catch (InterruptedException e) { 
			e.printStackTrace(); 
		} finally {
			lock.unlock();
		}
	}
	
	public void putDown() {
		try {
			queue.take();
		} catch (InterruptedException e) { 
			e.printStackTrace(); 
		}
	}
}
