from math import sqrt
from datetime import datetime
prime_data = {}
def isprime(n):
    """
    Returns True if n is prime, False otherwise
    Caches its return value in prime_data

    """
    global prime_data
    if n in prime_data: return prime_data[n]
    if n == 1:
        prime_data[n] = False
        return False

    if n == 2:
        prime_data[n] = True
        return True

    sqrt_n = sqrt(n)
    i = 2
    while i <= sqrt_n:
        if not isprime(i):
            i = i + 1
            continue
        if n % i == 0:
            prime_data[n] = False
            return False
        i = i + 1
    prime_data[n] = True
    return True

prop_satis = {}

def is_property_satisfied(s):
    """
    Given a set s, returns True if it satisfies the property
    that all possible concatenations of its elements also
    yield a prime number.

    """
    global prop_satis
    if tuple(s) in prop_satis: return prop_satis[tuple(s)]
    for x in s:
        for y in s:
            if x == y: continue
            if not isprime(int(str(x) + str(y))):
                prop_satis[tuple(s)] = False
                return False
            if not isprime(int(str(y) + str(x))):
                prop_satis[tuple(s)] = False
                return False

    prop_satis[tuple(s)] = True
    return True

def main():

    list_of_primes = [3]

    for i in xrange(6, 10000):
        if isprime(i): list_of_primes.append(i)

    print list_of_primes, len(list_of_primes)

    go_till_n = 5

    for x in range(1, go_till_n + 1):
        print 'Processing for x:', x
        if x == 1:
            lists_of_primes = map(lambda y: [y], list_of_primes)
            continue
        temp_lists_of_primes = []
        for y in list_of_primes:
            print 'Processing prime:', y
           
            # Try adding y to each set in sets_of_primes
            for prime_list in lists_of_primes:
                if y in prime_list: continue
                if y < prime_list[-1]: continue
                t = prime_list + [y]
                t.sort()
                
                if is_property_satisfied(t):
                    temp_lists_of_primes.append(t)
        lists_of_primes = temp_lists_of_primes
        for a in lists_of_primes:
            print a, sum(a)
        print 'Done'

if __name__ == '__main__':
    main()

