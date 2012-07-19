/**
 * $Id$
 */
package phil;

import fork.StatedFork;
import fork.StatedFork.ForkState;

/**
 *
 * @author atimoshpolsky
 * @since Jul 19, 2012
 */
public class StatedForkPhilosopher extends SimpleSynchronizedPhilosopher<StatedFork>
{
    public StatedForkPhilosopher(int position, StatedFork left, StatedFork right)
    {
        super(position, left, right);
    }

    @Override
    public void run()
    {
        while (!stopFlag) {
            think();
            while (left.state == ForkState.IN_USE) {}
            left.state = ForkState.IN_USE;
            while (right.state == ForkState.IN_USE) {}
            right.state = ForkState.IN_USE;
            eat();
            right.state = ForkState.FREE;
            left.state = ForkState.FREE;
        }
        log("stopped."); //$NON-NLS-1$
    }
}
