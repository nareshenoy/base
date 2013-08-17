import math

pentagonal_numbers = []
def ispenta(p_n):
    k = 2 * p_n
    # Check if the equation 3n^2 - n - k has integral roots
    D      = 1 - 4 * 3 * (-1) * k
    sqrt_D = math.sqrt(D)
    if sqrt_D.__int__() != sqrt_D:
        return False
    # Roots of the equation
    r_1 = (1 + sqrt_D) / 6
    if r_1.__int__() != r_1:
        return False
    return r_1

def get_penta(n):
    p_n = n * (3 * n - 1) / 2
    return p_n

def main():
    p_1 = get_penta(1)
    pentagonal_numbers.append(p_1)
    n = 2
    min_diff = -1
    while 1:
        p_n = get_penta(n)
        for i in pentagonal_numbers:
            if min_diff == -1 or min_diff > abs(p_n - i):            
                a = ispenta(abs(p_n - i))
                b = ispenta(abs(p_n + i))
                if a and b:
                    min_diff = abs(p_n - i)
                    print a, b, min_diff
        pentagonal_numbers.append(p_n)
        n = n + 1

if __name__ == "__main__":
    main()
            
