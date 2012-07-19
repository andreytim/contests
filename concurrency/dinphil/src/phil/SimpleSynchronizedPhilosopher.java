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
public class SimpleSynchronizedPhilosopher extends Philosopher
{
    private volatile boolean stopFlag = false;
    
    private final Object firstLock;
    private final Object secondLock;
    
    public SimpleSynchronizedPhilosopher(int position, Fork left, Fork right)
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
