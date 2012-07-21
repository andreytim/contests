/**
 * $Id$
 */
package ru.tim.dinphils.phil;

import ru.tim.dinphils.fork.WithIdFork;

/**
 *
 * @author atimoshpolsky
 * @since Jul 19, 2012
 */
public class WithIdForkPhilosopher extends Philosopher<WithIdFork>
{
    protected final WithIdFork first;
    protected final WithIdFork second;
    
    public WithIdForkPhilosopher(int position, WithIdFork left, WithIdFork right)
    {
        super(position, left, right);
        this.first = (position & 1) == 0 ? right : left;
        this.second = (position & 1) == 0 ? left : right;
    }

    @Override
    public void act()
    {
		think();
		synchronized (first) {
			while (this.position == first.eaterID) {
				try {
					first.wait();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			first.eaterID = this.position;
			synchronized (second) {
				while (this.position == second.eaterID) {
					try {
						second.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				second.eaterID = this.position;
				eat();
				second.notify();
			}
			first.notify();
		}
    }
}
