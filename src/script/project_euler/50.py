primes = [ 0 ] * 1000000
def longest_sum(n):
    sum_primes = 0
    num_primes = 0
    const_primes = set()
    for i in range(2, n / 50 + 1):
        if primes[i] == 1:
            sum_primes = sum_primes + i
            num_primes = num_primes + 1
            const_primes.add(i)
            if sum_primes == n:
                return num_primes
            elif sum_primes > n:
                while sum_primes > n:
                    sum_primes = sum_primes - const_primes.pop()
                    num_primes = num_primes - 1
                if sum_primes == n:
                    return num_primes

    return num_primes
def main():
    max_length = 0
    for n in range(2, 1000000):
        num = n
        while num < 1000000:
            primes[num] = primes[num] + 1
            num = num + n
    print "Finished creating sieve"
    """
    sum_primes = 0
    set_of_primes = set()
    for n in range(2, 1000000):
        if primes[n] == 1:
            sum_primes = sum_primes + n
            set_of_primes.append(n)
            if sum_primes > 1000000:
                break
    sum_primes = sum_primes - n
    set_of_primes.remove(n)
    """
    
    for n in range(2, 1000000):
        if n % 10000 == 0:
            print n, max_length, max_prime
        if primes[n] == 1:
            ls = longest_sum(n)
            if ls > max_length:
                max_length = ls
                max_prime = n
    print max_length, max_prime

if __name__ == '__main__':
    main()
