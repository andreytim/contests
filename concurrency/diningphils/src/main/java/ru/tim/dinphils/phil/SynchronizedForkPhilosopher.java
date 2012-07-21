/**
 * $Id$
 */
package ru.tim.dinphils.phil;

import ru.tim.dinphils.fork.Fork;

/**
 *
 * @author atimoshpolsky
 * @since Jul 19, 2012
 */
public class SynchronizedForkPhilosopher extends Philosopher<Fork>
{
    protected final Object firstLock;
    protected final Object secondLock;
    
    public <F extends Fork> SynchronizedForkPhilosopher(int position, F left, F right)
    {
        super(position, left, right);
        this.firstLock = position == 0 ? right : left;
        this.secondLock = position == 0 ? left : right;
    }

    @Override
    public void act()
    {
		think();
		synchronized (firstLock) {
			log("took left fork."); //$NON-NLS-1$
			synchronized (secondLock) {
				log("took right fork."); //$NON-NLS-1$
				eat();
			}
		}
    }
}
