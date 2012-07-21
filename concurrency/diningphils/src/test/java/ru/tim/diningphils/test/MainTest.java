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
import ru.tim.dinphils.fork.BlockingQueueFork;
import ru.tim.dinphils.fork.Fork;
import ru.tim.dinphils.fork.WaiterService;
import ru.tim.dinphils.fork.WithIdFork;
import ru.tim.dinphils.phil.BlockingQueueForkPhilosopher;
import ru.tim.dinphils.phil.Philosopher;
import ru.tim.dinphils.phil.SynchronizedForkPhilosopher;
import ru.tim.dinphils.phil.WithIdForkPhilosopher;
import ru.tim.dinphils.phil.WithWaiterPhilosopher;

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
        testPhilosophers(new PhilFactory(SynchronizedForkPhilosopher.class, Fork.class));
    }
    
    @Test
    public void testWithId() throws Exception {
        testPhilosophers(new PhilFactory(WithIdForkPhilosopher.class, WithIdFork.class));
    }
    
    @Test
    public void testBlockingQueue() throws Exception {
        testPhilosophers(new PhilFactory(BlockingQueueForkPhilosopher.class, BlockingQueueFork.class));
    }
    
    @Test
    public void testWithWaiter() throws Exception {
        WaiterService.get().clearingResize(PHILS_NUMBER);
    	testPhilosophers(new PhilFactory(WithWaiterPhilosopher.class, Fork.class));
    }
    
    private static void testPhilosophers(PhilFactory philFactory) throws InterruptedException
    {
        logger.info("Testing {}.", philFactory.getPhilClass().getSimpleName());
        
        List<Philosopher<?>> phils = new ArrayList<Philosopher<?>>(PHILS_NUMBER);
        Fork left = philFactory.createFork();
        Fork first = left;
        for (int i = 0; i < PHILS_NUMBER; i++) {
        	Fork right = philFactory.createFork();
        	if (i == PHILS_NUMBER-1) {
        		right = first;
            }
        	Philosopher<? extends Fork> p = philFactory.createPhilosopher(i, left, right);
            phils.add(p);
            left = right;
        }
        
        Thread[] threads = new Thread[phils.size()];
        for (int i = 0; i < phils.size(); i++) {
            threads[i] = new Thread(phils.get(i));
            threads[i].start();
        }
        
        TimeUnit.MILLISECONDS.sleep(RUN_TIME);
        
        for (Philosopher<?> phil : phils) {
            phil.stop();
        }
        
        for (Thread thread : threads) {
            thread.join();
        }
        
        long sumTime = 0, sumEatCount = 0;
        for (Philosopher<?> phil : phils) {
        	sumTime += phil.getWaitTime(TimeUnit.MILLISECONDS);
        	sumEatCount += phil.getEatCount();
        	logger.info("{} ate {} times and waited {} ms.", new String[]{ 
        			phil.toString(), String.valueOf(phil.getEatCount()), String.valueOf(phil.getWaitTime(TimeUnit.MILLISECONDS)) });
        }
        logger.info("Average times ate: {}.", sumEatCount / phils.size());
        logger.info("Average wait time: {} ms.", sumTime / phils.size());
    }
}
