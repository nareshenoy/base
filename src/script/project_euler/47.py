import math
def get_num_factors(n):
    factors = set()
    sq = n / 2 + 1
    for i in range(2, sq + 1):
        if n == 1: break
        while n % i == 0:
            factors.add(i)
            n = n / i

            #print i
    return len(factors)

def main():


    n_1 = get_num_factors(1)
    n_2 = get_num_factors(2)
    n_3 = get_num_factors(3)
    n_4 = get_num_factors(4)
    n = 4
    while (1):
        if n_1 == 4 and n_2 == 4 and n_3 == 4 and n_4 == 4:
            print n - 3
            exit()
        elif n_4 != 4:
            n = n + 4
            while get_num_factors(n) != 4:
                n = n + 4
            n_1 = get_num_factors(n - 3)
            n_2 = get_num_factors(n - 2)
            n_3 = get_num_factors(n - 1)
            n_4 = 4
        else:
            n = n + 1
            n_1 = n_2
            n_2 = n_3
            n_3 = n_4
            n_4 = get_num_factors(n)
            if n_4 != 4:
                n = n + 4
                while get_num_factors(n) != 4:
                    n = n + 4
                n_1 = get_num_factors(n - 3)
                n_2 = get_num_factors(n - 2)
                n_3 = get_num_factors(n - 1)
                n_4 = 4
                

    #print get_num_factors(553)
    #print get_num_factors(4)
    #print get_num_factors(13)

    #print get_num_factors(238202)

if __name__ == "__main__":
    main()
    
