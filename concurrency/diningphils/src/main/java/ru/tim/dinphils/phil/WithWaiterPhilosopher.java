package ru.tim.dinphils.phil;

import ru.tim.dinphils.fork.Fork;
import ru.tim.dinphils.fork.WaiterService;

public class WithWaiterPhilosopher extends Philosopher<Fork> {

	public WithWaiterPhilosopher(int position, Fork left, Fork right) {
		super(position, left, right);
		WaiterService.get().registerMe(position, left, right);
	}

	@Override
	protected void act() {
		think();
		WaiterService.get().serveMe(position);
		eat();
		WaiterService.get().leaveMe(position);
	}

}
