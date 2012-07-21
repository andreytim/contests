package ru.tim.dinphils.phil;

import ru.tim.dinphils.fork.BlockingQueueFork;

public class BlockingQueueForkPhilosopher extends Philosopher<BlockingQueueFork> 
{
	protected final BlockingQueueFork first;
    protected final BlockingQueueFork second;
	
	public BlockingQueueForkPhilosopher(int position, BlockingQueueFork left, BlockingQueueFork right) {
		super(position, left, right);
		this.first = (position & 1) == 0 ? right : left;
        this.second = (position & 1) == 0 ? left : right;
	}

	@Override
	protected void act() {
		think();
		first.pickUp(this);
		second.pickUp(this);
		eat();
		second.putDown();
		first.putDown();
	}
}
