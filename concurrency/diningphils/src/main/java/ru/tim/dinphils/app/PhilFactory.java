/**
 * $Id$
 */
package ru.tim.dinphils.app;

import java.lang.reflect.Constructor;

import ru.tim.dinphils.fork.Fork;
import ru.tim.dinphils.phil.Philosopher;

/**
 *
 * @author atimoshpolsky
 * @since Jul 20, 2012
 */
public class PhilFactory<P extends Philosopher<F>, F extends Fork>
{
    private Class<P> philClass;
    private Class<F> forkClass;
    
    public PhilFactory(Class<P> philClass, Class<F> forkClass) {
        this.philClass = philClass;
        this.forkClass = forkClass;
    }
    
    public P createPhilosopher(int pos, F left, F right)
    {
        try {
            Constructor<P> constructor = philClass.getConstructor(new Class[]{ int.class, forkClass, forkClass });
            return constructor.newInstance(new Object[]{ pos, left, right });
        } catch (Exception e) {
            return null;
        }
    }
    
    public F createFork() {
        try {
            return forkClass.newInstance();
        } catch (Exception e) {
            return null;
        }
    }

    public Class<P> getPhilClass()
    {
        return philClass;
    }

    public Class<F> getForkClass()
    {
        return forkClass;
    }
}
