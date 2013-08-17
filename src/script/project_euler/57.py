

def get_digits(n):
    count = 0

    while n > 0:
        count = count + 1
        n = n / 10

    return count  

def get_num_denom(first_num, first_denom, second_num, second_denom):
    return (first_num * second_denom + second_num * first_denom, first_denom * second_denom)

n_to_num_denom = {}

def get_nth_term(n):

    if n in n_to_num_denom:
        return n_to_num_denom[n]
    if n == 1:
        n_to_num_denom[n] = (2, 1)
        return  (2, 1)
    else:
        second_denom, second_num = get_nth_term(n - 1)
        ret_n, ret_d =  get_num_denom(first_num=2,
                                      first_denom=1,
                                      second_num=second_num,
                                      second_denom=second_denom)
        n_to_num_denom[n] = (ret_n, ret_d)
        return (ret_n, ret_d)

def main():
    count = 0
    for i in xrange(1, 1000):
        denom, num = get_nth_term(i)
        sn, sd     =  get_num_denom(first_num=1,
                                    first_denom=1,
                                    second_num=num,
                                    second_denom=denom)
        #print i, sn, '/', sd
        if get_digits(sn) > get_digits(sd):
            count = count + 1

    #print count
         
if __name__ == '__main__':
    main()                
