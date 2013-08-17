def digitize(a):
    digits = []
    while a != 0:
        digits.append(a % 10)
        a = a / 10
    digits.sort()
    return digits

def isperm(a, b):
    d_a = digitize(a)
    d_b = digitize(b)
    if d_a == d_b:
        return True
    else:
        return False
def isprime(n):
    for i in range(2, n / 2 + 1):
        if n % i == 0:
            return False
    return True

def main():
    for n in range(1001, 10000):
        if isprime(n):
            for d in range(1, (10000 - n) / 2):
                if d % 2 == 0:
                    if isprime(n + d) and isprime(n + 2 * d):
                        if isperm(n, n + d) and isperm(n, n + 2 * d):
                            print n, n + d, n + 2 * d

if __name__ == '__main__':
    main()
