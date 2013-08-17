from math import sqrt
def get_diag_ele(n):
    if n == 1:
        return [1]
    else:
        n_square = n * n
        return [n_square, n_square - (n - 1), n_square - 2 * (n - 1), n_square - 3 * (n - 1)]
ispr = {}
def is_prime(n):
    if n in ispr:
        return ispr[n]
    if n == 1:
        ispr[n] = False
        return False
    if n in (2, 3):
        ispr[n] = True
        return True
    if ((n + 1) % 6) != 0 and ((n - 1) % 6) != 0:
        ispr[n] = False
        return False
    a = range(2, int(sqrt(n)))[1::2]
    for i in a:
        if n % i == 0:
            ispr[n] = False
            return False
    ispr[n] = True
    return True

n = 1
diag_ele = []
count = 0
while True:
    new_entries = get_diag_ele(n)
    #print "[N =", n, "]", diag_ele
    for ele in new_entries[1:]:
        if is_prime(ele):
            count = count + 1
    ratio = float(count) / float(2 * n - 1)
    #print n, count, ratio
    if ratio < 0.1 and n > 1:
        print n, ratio
        break
    n = n + 2
    #if n % 101 == 0:
    #    print n, ratio
    #if n == 11:
    #    break

    
