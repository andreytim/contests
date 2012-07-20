/**
 * $Id$
 */
package ru.tim.diningphils.test;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

import org.junit.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import ru.tim.dinphils.app.PhilFactory;
import ru.tim.dinphils.fork.Fork;
import ru.tim.dinphils.fork.WithIdFork;
import ru.tim.dinphils.phil.Philosopher;
import ru.tim.dinphils.phil.SimpleSynchronizedPhilosopher;
import ru.tim.dinphils.phil.WithIdForkPhilosopher;

/**
 *
 * @author atimoshpolsky
 * @since Jul 20, 2012
 */
public class MainTest
{
    protected static final Logger logger = LoggerFactory.getLogger(MainTest.class);
    
    private static final int RUN_TIME = 60000;
    private static final int PHILS_NUMBER = 5;
    
    @Test
    public void testSimpleSynchronized() throws Exception {
        testPhilosophers(
                new PhilFactory<SimpleSynchronizedPhilosopher, Fork>(SimpleSynchronizedPhilosopher.class, Fork.class));
    }
    
    @Test
    public void testWithIdFork() throws Exception {
        testPhilosophers(
                new PhilFactory<WithIdForkPhilosopher, WithIdFork>(WithIdForkPhilosopher.class, WithIdFork.class));
    }
    
    private static <P extends Philosopher<F>, F extends Fork> void testPhilosophers(
            PhilFactory<P, F> philFactory) throws InterruptedException
    {
        logger.info("Testing " + philFactory.getPhilClass().getSimpleName()); //$NON-NLS-1$
        
        List<P> phils = new ArrayList<P>(PHILS_NUMBER);
        F left = philFactory.createFork();
        F first = left;
        for (int i = 0; i < PHILS_NUMBER; i++) {
            F right = (i == PHILS_NUMBER-1) ? first : philFactory.createFork();
            phils.add(philFactory.createPhilosopher(i, left, right));
            left = right;
        }
        
        Thread[] threads = new Thread[phils.size()];
        for (int i = 0; i < phils.size(); i++) {
            threads[i] = new Thread(phils.get(i));
            threads[i].start();
        }
        
        TimeUnit.MILLISECONDS.sleep(RUN_TIME);
        
        for (P phil : phils) {
            phil.stop();
        }
        
        for (Thread thread : threads) {
            thread.join();
        }
        
        for (P phil : phils) {
            logger.info(phil.toString() + " ate " + phil.getEatCount()  //$NON-NLS-1$
                    + " times and waited " + phil.getWaitTime(TimeUnit.MILLISECONDS) + " ms."); //$NON-NLS-1$ //$NON-NLS-2$
        }
    }
}
