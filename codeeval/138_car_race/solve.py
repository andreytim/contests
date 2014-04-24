#!/usr/bin/python -tt

import sys
from collections import namedtuple

def calc_time(race, car):
    acceleration = car.speed / car.start_t
    slowdown = -car.speed / car.stop_t
    #print 'Car %d: max_speed: %.4f, acceleration: %.4f, slowdown: %.4f' % \
    #       (car.id, car.speed, acceleration, slowdown)
    start_speed = 0
    total_time = 0
    for i in range(0, len(race), 2):
        end_speed = race[i+1] * car.speed
        time_to_accelerate = (car.speed - start_speed) / acceleration
        time_to_slowdown = -(car.speed - end_speed) / slowdown
        accelerate_way = (car.speed**2 - start_speed**2) / (2 * acceleration)
        slowdown_way = (end_speed**2 - car.speed**2) / (2 * slowdown)
        time_max_speed = (race[i] - accelerate_way - slowdown_way) / car.speed
        total_time += time_to_accelerate + time_max_speed + time_to_slowdown
        #print 'section_length: %.4f, angle: %.4f, start_speed: %.4f, end_speed: %.4f' % \
        #       (race[i], race[i+1], start_speed, end_speed)
        #print ' --- accelerate_way: %.4f, time_to_accelerate: %.4f' % (accelerate_way, time_to_accelerate)
        #print ' --- slowdown_way: %.4f, time_to_slowdown: %.4f' % (slowdown_way, time_to_slowdown)
        start_speed = end_speed 
    return total_time

def main():
    f = open(sys.argv[1], 'r')
    race = [ float(s) for s in f.readline().strip().split(' ') ]
    for i in range(1, len(race), 2):
        race[i] = (180.0 - race[i]) / 180.0 
    cars = []
    Car = namedtuple('Car', 'id speed start_t stop_t')
    for l in f.readlines():
        carraw = l.strip().split(' ')
        cars.append(Car(int(carraw[0]), float(carraw[1])/3600, 
                     float(carraw[2]), float(carraw[3])))
    f.close()
    times = [(car.id, calc_time(race, car)) for car in cars]
    for c in sorted(times, key=lambda t: t[1]):
        print '%d %.2f' % (c[0], c[1])

if __name__ == '__main__':
    main()
