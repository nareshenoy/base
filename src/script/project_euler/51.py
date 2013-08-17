import math
isprime_arr = [True] * 1000001
considered_sequences = []
def considered(n, s):
    digit_list = []
    while n > 0:
        digit_list.append(n % 10)
        n = n / 10
    for d in s:
        digit_list[d - 1] = -1

    str_list = str(digit_list)[1:-1].replace(', ', '')
    if str_list in considered_sequences:
        return True
    else:
        considered_sequences.append(str_list)
        return False

def prime_sieve():
    for i in range (2, 1000001):
        val = 1
        num = val * i
        if isprime_arr[num] == True:
            val = val + 1
            num = val * i
            while num <= 1000000:
                isprime_arr[num] = False
                val = val + 1
                num = val * i
            
def replace_num(n, i, s):
    digit_list = []
    while n > 0:
        digit_list.append(n % 10)
        n = n / 10
    for d in s:
        digit_list[d - 1] = i
    new_num = 0
    for idx, d in enumerate(digit_list):
        new_num = new_num + d * (10 ** idx)
    return new_num

def get_primes(digits_replaced, n):
    prime_list = []
    nd = digits(n)
    #print digits_replaced, n
    for s in digits_replaced:
        if 1 in s:
            continue
        if n % 10 in (2, 4, 6, 8, 0, 5) and 1 not in s:
            #print "Not considering : ", n, s
            continue
        #if considered(n, s):
        #    continue
        prime_list = []
        for i in range(0, 10):
            if nd in s and i == 0:
                continue
            if i in (0, 2, 4, 6, 8, 5) and 1 in s:
                continue
            replaced_num = replace_num(n, i, s)
            #print n, i, s, replaced_num
            if isprime_arr[replaced_num]:
                prime_list.append(replaced_num)
        print s, prime_list
        if len(prime_list) >= 8:
            return prime_list

    return prime_list
def digits(x):
    """ Return amount of digits of x. """
    return int(math.floor(math.log10(x)) + 1)

def get_num_primes(n):
    nd = digits(n)
    digits_replaced = [0] * nd
    list_of_primes  = []
    # Initialize the digits to be replaced
    for idx in range(0, nd):
        digits_replaced[idx] = set([idx + 1])
    
    for num_digits_replaced in range(1, nd):
        print "Getting primes for:", digits_replaced, n
        list_of_primes = get_primes(digits_replaced, n)
        print list_of_primes
        #    print n, len(list_of_primes)
        if len(list_of_primes) >= 8:
            return list_of_primes

        digits_replaced = digits_replaced * nd
        digits_replaced.sort()
        print "After multiplying:", digits_replaced
        for idx, s in enumerate(digits_replaced):
            digits_replaced[idx].add((idx + 1)% nd + 1)
        print "New digits to be replaced:", digits_replaced
        # Remove all sets with length = num_digits_replaced
        to_be_removed = []
        for s in digits_replaced:
            if len(s) == num_digits_replaced:
                to_be_removed.append(s)
        for s in to_be_removed:
            digits_replaced.remove(s)
            
        """
        #print "Before : ", len(digits_replaced)
        digits_replaced.sort()
        last = digits_replaced[-1]
        for i in range(len(digits_replaced)-2, -1, -1):
            if last == digits_replaced[i]:
                del digits_replaced[i]
            else:
                last = digits_replaced[i]
        #print "After : ", len(digits_replaced)
        """
    return list_of_primes

def main():
    n = 121313
    #nd_old = 5
    prime_sieve()
    max_yet = 0
    print "Created prime sieve"
    while True:
        #nd = digits(n)
        if n % 1000 == 0:
            print n, max_yet
        if n % 10 not in (1, 3, 7, 9):
            n = n + 1
            #nd_old = nd
            continue
        if isprime_arr[n] != True:
            n = n + 1
            continue
        #if nd != nd_old:
        #    clear_considered_sequences()
        list_of_primes = get_num_primes(n)
        print list_of_primes
        #print list_of_primes, n
        m = len(list_of_primes)
        if m >= 8:
            print list_of_primes
            break
        if m > max_yet:
            max_yet = m
            print list_of_primes, max_yet
        n = n + 1
        if n == 121314:
            break
        #nd_old = nd

if __name__ == '__main__':
    main()
