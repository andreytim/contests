package ru.tim.diningphils.test;

import java.lang.reflect.Constructor;

import ru.tim.dinphils.fork.Fork;
import ru.tim.dinphils.phil.Philosopher;

/**
 * Factory class for creating instances of {@link Philosopher}s and {@link Fork}s.
 *
 * @author shpolsky
 */
public class PhilFactory
{
    private Class<? extends Philosopher<?>> philClass;
    private Class<? extends Fork> forkClass;
    
    public <P extends Philosopher<F>, F extends Fork> PhilFactory(Class<P> philClass, Class<F> forkClass) {
        this.philClass = philClass;
        this.forkClass = forkClass;
    }

	@SuppressWarnings("unchecked")
	public <P,F> P createPhilosopher(int pos, F left, F right) {
        try {
            Constructor<P> constructor = (Constructor<P>) philClass.getConstructor(new Class[]{ int.class, forkClass, forkClass });
            return constructor.newInstance(new Object[]{ pos, left, right });
        } catch (Exception e) {
            return null;
        }
    }
    
    @SuppressWarnings("unchecked")
	public <F> F createFork() {
        try {
            return (F) forkClass.newInstance();
        } catch (Exception e) {
            return null;
        }
    }

    public Class<? extends Philosopher<?>> getPhilClass() {
        return philClass;
    }

    public Class<? extends Fork> getForkClass() {
        return forkClass;
    }
}
