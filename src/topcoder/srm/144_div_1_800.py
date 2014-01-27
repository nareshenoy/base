oundabout problem

################################
from copy import deepcopy
from logging import error
################################
N = 'N'
S = 'S'
E = 'E'
W = 'W'

def left(dirn):
    if dirn == N: return E
    if dirn == S: return W
    if dirn == E: return S
    if dirn == W: return N

def right(dirn):
    if dirn == N: return W
    if dirn == S: return E
    if dirn == E: return N
    if dirn == W: return S

def lookup(d, key):
    return d[key]

def cars_waiting_to_get_on(dirn, dir_map):
    #print 'In dirn:', dirn, 'cars waiting', dir_map[dirn]
    if dir_map[dirn] and dir_map[dirn] != '-': return True
    return False

class Roundabout(object):
    def clearUpTime(self, north, east, south, west):
        """
        Returns an integer number of seconds it takes 
        to empty the roundabout.

        """
        total_time = 0
        print north, south, east, west
        r_abt = {N: None, S: None, E: None, W: None } 
        latest_cars = {N : None, S : None, E : None, W : None,}
        first_loop = True
        while first_loop or r_abt.values() != [None, None, None, None]:
            first_loop = False
            total_time = total_time + 1
            print('State of the roundabout: ' + str(r_abt) + ' at time: ' + str(total_time))
            # Exit the roundabout, if that is possible
            for dirn in r_abt:
                if r_abt[dirn] == dirn:
                    r_abt[dirn] = None
                    print 'Car left roundabout at ' + str(dirn)
            print('State of the roundabout after the cars have left: ' + str(r_abt))

            # One rotation
            old_r_abt = deepcopy(r_abt)
            for dirn in r_abt:
                r_abt[dirn] = old_r_abt[left(dirn)]

            #error('Roundabout rotation done')
            print('State of the roundabout after rotation: ' + str(r_abt) + ' at time: ' + str(total_time))

            if latest_cars[N] in (None, '-') and north:
                latest_cars[N] = north[0]
                north = north[1:]
            if latest_cars[S] in (None, '-') and south:
                latest_cars[S] = south[0]
                south = south[1:]
            if latest_cars[E] in (None, '-') and east:
                latest_cars[E] = east[0]
                east = east[1:]
            if latest_cars[W] in (None, '-') and west:
                latest_cars[W] = west[0]
                west = west[1:]

            car_got_on_ra = False
            for dirn in (N, S, E, W):
                print 'Running for direction: ', dirn, ' car ', latest_cars[dirn], ' current r_abt', r_abt[dirn], 'old_r_abt', old_r_abt[left(dirn)], cars_waiting_to_get_on(left(dirn), latest_cars)
                print north, south, east, west
                if r_abt[dirn] is None and\
                   latest_cars[dirn] not in ('-', None) and\
                   old_r_abt[left(dirn)] is None and\
                   not cars_waiting_to_get_on(left(dirn), latest_cars):
                    # Get on the roundabout
                    print('Getting on the roundabout at ' + dirn)
                    r_abt[dirn] = latest_cars[dirn]
                    latest_cars[dirn] = None
                    car_got_on_ra = True
            if not car_got_on_ra and latest_cars[N] not in (None, '-') and r_abt.values() == [None, None, None, None]:
                r_abt[N] = latest_cars[N]
                latest_cars[N] = None
            print('State of the roundabout after the cars have got on:' + str(r_abt) + ' at time ' + str(total_time))
        return total_time

