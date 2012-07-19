package app;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

import phil.Philosopher;
import phil.SimpleSynchronizedPhilosopher;
import fork.Fork;

/**
 * $Id$
 */

/**
 *
 * @author atimoshpolsky
 * @since Jul 19, 2012
 */
public class Main
{
    private static final int RUN_TIME = 60000;
    private static final int PHILS_NUMBER = 5;
    private static final List<Philosopher> phils = new ArrayList<Philosopher>(PHILS_NUMBER);
    
    public static void main(String ... args) throws Exception
    {
        Fork first = new Fork();
        Fork left = first;
        for (int i = 0; i < PHILS_NUMBER; i++) {
            Fork right = (i == PHILS_NUMBER-1) ? first : new Fork();
            phils.add(new SimpleSynchronizedPhilosopher(i, left, right));
            left = right;
        }
        
        Thread[] threads = new Thread[PHILS_NUMBER];
        for (int i = 0; i < PHILS_NUMBER; i++) {
            threads[i] = new Thread(phils.get(i));
            threads[i].start();
        }
        
        TimeUnit.MILLISECONDS.sleep(RUN_TIME);
        
        for (Philosopher phil : phils) {
            phil.stop();
        }
        
        for (Thread thread : threads) {
            thread.join();
        }
        
        for (Philosopher phil : phils) {
            phil.log("ate " + phil.getEatCount()  //$NON-NLS-1$
                    + " times and waited " + phil.getWaitTime(TimeUnit.MILLISECONDS) + " ms."); //$NON-NLS-1$ //$NON-NLS-2$
        }
    }
}
