def rev(n):
    rev_n = 0
    while n != 0:
        units_place_digit = n % 10
        rev_n = rev_n * 10 + units_place_digit
        n = n / 10
    return rev_n

def ispalindrome(n):
    if rev(n) == n:
        return True
    else:
        return False

def islychrel(n):
    i = 0
    while i < 50:
        b = n + rev(n)
        if ispalindrome(b):
            return False
        n = b
        i = i + 1
    return True

def main():
    count = 0
    for n in range(1, 10000):
        if islychrel(n):
            count = count + 1
    print count

if __name__ == '__main__':
    main()
