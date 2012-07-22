package ru.tim.dinphils.phil;

import java.util.Random;
import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import ru.tim.dinphils.fork.Fork;

/**
 * Basic abstract philosopher implementation.
 *
 * @author shpolsky
 */
public abstract class Philosopher<T extends Fork> implements Runnable
{
    protected static final Logger logger = LoggerFactory.getLogger(Philosopher.class);
    protected static final boolean LOG = false;
    
    protected final int position;
    protected final T left;
    protected final T right;
    protected final Random rand = new Random();
    
    protected int eatCount = 0;
    protected long waitTime = 0;
    protected long startWait;
    
    protected volatile boolean stopFlag = false;
    
    public Philosopher(int position, T left, T right) {
        this.position = position;
        this.left = left;
        this.right = right;
    }
    
    /**
     * Emulation of think process with waiting for some time and logging.<br>
     * ! We can't change this method in our solution.
     */
    public final void think() {
        log("is thinking.");  //$NON-NLS-1$
        try {
            TimeUnit.MILLISECONDS.sleep(rand.nextInt(100));
        } catch (InterruptedException e) { throw new RuntimeException(e); }
        log("is hungry.");  //$NON-NLS-1$
        startWait = System.nanoTime();
    }
    
    /**
     * Emulation of eat process with waiting for some time and logging.<br>
     * ! We can't change this method in our solution.
     */
    public final void eat() {
        waitTime += System.nanoTime() - startWait;
        log("is eating.");  //$NON-NLS-1$
        try {
            TimeUnit.MILLISECONDS.sleep(rand.nextInt(100));
        } catch (InterruptedException e) { throw new RuntimeException(e); }
        eatCount++;
        log("finished eating.");  //$NON-NLS-1$
    }
    
    public void stop() {
    	stopFlag = true;
    }
    
    public void run() {
    	while (!stopFlag) {
            act();
        }
        log("stopped."); //$NON-NLS-1$
    }

    protected abstract void act();

	@Override
    public String toString() {
        return "[Philosopher " + position + "]";  //$NON-NLS-1$//$NON-NLS-2$
    }
    
    public void log(String msg) {
        if (LOG) {
            logger.info(this.toString() + " " + msg); //$NON-NLS-1$    
        }
    }
    
    public int getEatCount() {
        return eatCount;
    }
    
    public long getWaitTime(TimeUnit tu) {
        return tu.convert(waitTime, TimeUnit.NANOSECONDS);
    }
    
    public int getPosition() {
    	return position;
    }
}
