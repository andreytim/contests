package phil;

import java.util.Random;
import java.util.concurrent.TimeUnit;

import fork.Fork;

/**
 *
 * @author atimoshpolsky
 * @since Jul 19, 2012
 */
public abstract class Philosopher<T extends Fork> implements Runnable
{
    protected final int position;
    protected final T left;
    protected final T right;
    protected final Random rand = new Random();
    
    protected int eatCount = 0;
    protected long waitTime = 0;
    protected long startWait;
    
    public Philosopher(int position, T left, T right) {
        this.position = position;
        this.left = left;
        this.right = right;
    }
    
    public final void think() {
        log("is thinking.");  //$NON-NLS-1$
        try {
            TimeUnit.MILLISECONDS.sleep(rand.nextInt(100));
        } catch (InterruptedException e) { throw new RuntimeException(e); }
        log("is hungry.");  //$NON-NLS-1$
        startWait = System.nanoTime();
    }
    
    public final void eat() {
        waitTime += System.nanoTime() - startWait;
        log("is eating.");  //$NON-NLS-1$
        try {
            TimeUnit.MILLISECONDS.sleep(rand.nextInt(100));
        } catch (InterruptedException e) { throw new RuntimeException(e); }
        eatCount++;
        log("finished eating.");  //$NON-NLS-1$
    }
    
    public abstract void stop();
    
    @Override
    public String toString() {
        return "[Philosopher " + position + "]";  //$NON-NLS-1$//$NON-NLS-2$
    }
    
    public void log(String msg) {
        System.out.println(this.toString() + " " + msg); //$NON-NLS-1$
    }
    
    public int getEatCount() {
        return eatCount;
    }
    
    public long getWaitTime(TimeUnit tu) {
        return tu.convert(waitTime, TimeUnit.NANOSECONDS);
    }
}
