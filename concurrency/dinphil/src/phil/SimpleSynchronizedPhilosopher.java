/**
 * $Id$
 */
package phil;

import fork.Fork;

/**
 *
 * @author atimoshpolsky
 * @since Jul 19, 2012
 */
public class SimpleSynchronizedPhilosopher<T extends Fork> extends Philosopher<T>
{
    protected volatile boolean stopFlag = false;
    
    protected final Object firstLock;
    protected final Object secondLock;
    
    public SimpleSynchronizedPhilosopher(int position, T left, T right)
    {
        super(position, left, right);
        this.firstLock = position == 0 ? right : left;
        this.secondLock = position == 0 ? left : right;
    }

    @Override
    public void run()
    {
        while (!stopFlag) {
            think();
            synchronized (firstLock) {
                log("took left fork."); //$NON-NLS-1$
                synchronized (secondLock) {
                    log("took right fork."); //$NON-NLS-1$
                    eat();
                }
            }
        }
        log("stopped."); //$NON-NLS-1$
    }

    @Override
    public void stop()
    {
        stopFlag = true;
    }
}
