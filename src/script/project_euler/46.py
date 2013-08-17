import math
odd_primes = []
def issquare(n):
    sqrt_n = math.sqrt(n)
    if sqrt_n == sqrt_n.__int__():
        return True
    return False

def isgoldbach(n):
    if n == 1:
        return True
    for prime in odd_primes:
        temp = (n - prime) / 2
        if issquare(temp):
            return True
    return False

def isprime(n):
    a    = math.sqrt(n)
    rt_n = a.__int__()
    for i in range(2, rt_n + 1):
        if n % i == 0:
            return False
    return True
        
def main():
    
    n = 1
    while 1:
        if not isprime(n):
            if not isgoldbach(n):
                print n
                exit()
        else:
            # Add this to the list of primes
            odd_primes.append(n)
        n = n + 2
if __name__ == "__main__":
    main()
