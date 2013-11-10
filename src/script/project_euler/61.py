from copy import deepcopy

def p3(n):
    return n * (n + 1) / 2

def p4(n):
    return n * n

def p5(n):
    return n * (3 * n - 1) / 2

def p6(n):
    return n * (2 * n - 1)
    
def p7(n):
    return n * (5 * n - 3) / 2

def p8(n):
    return n * (3 * n - 2)

def is_cyclic(a, b):
    return str(a)[-2:] == str(b)[:2]

def main():

    p3_done, p4_done, p5_done, p6_done, p7_done, p8_done = [False] * 6
    p3_list, p4_list, p5_list, p6_list, p7_list, p8_list = [],[],[],[],[],[]

    
    for i in xrange(0, 300):
        if not p3_done:
            num = p3(i)
            if num >= 1000 and num < 10000: p3_list.append(num)
            if num >= 10000: p3_done = True

        if not p4_done:
            num = p4(i)
            if num / 1000.0 >= 1 and num / 1000.0 < 10: p4_list.append(num)
            if num / 1000.0 >= 10: p4_done = True

        if not p5_done:
            num = p5(i)
            if num / 1000.0 >= 1 and num / 1000.0 < 10: p5_list.append(num)
            if num / 1000.0 >= 10: p5_done = True

        if not p6_done:
            num = p6(i)
            if num / 1000.0 >= 1 and num / 1000.0 < 10: p6_list.append(num)
            if num / 1000.0 >= 10: p6_done = True

        if not p7_done:
            num = p7(i)
            if num / 1000.0 >= 1 and num / 1000.0 < 10: p7_list.append(num)
            if num / 1000.0 >= 10: p7_done = True

        if not p8_done:
            num = p8(i)
            if num / 1000.0 >= 1 and num / 1000.0 < 10: p8_list.append(num)
            if num / 1000.0 >= 10: p8_done = True

    figurates =   {
                    3 : p3_list,
                    4 : p4_list,
                    5 : p5_list,
                    6 : p6_list,
                    7 : p7_list,
                    8 : p8_list
                  }
    numbers = [(key, value) for key in figurates.keys() for value in figurates[key]]
    print len(p3_list), len(p4_list), len(p5_list), len(p6_list), len(p7_list), len(p8_list)
    #for num1, vals1 in num_to_list.items():
    #    for val1 in vals1:
    #        tmp_list = [val1]
    #        for num2, vals2 in num_to_list.items():
    for k1, v1 in numbers:
        for k2, v2 in [(k, v) for k, v in numbers if k not in [k1] and is_cyclic(v1, v)]:
            for k3, v3 in [(k, v) for k, v in numbers if k not in [k1, k2] and is_cyclic(v2, v)]:
                for k4, v4 in [(k, v) for k, v in numbers if k not in [k1, k2, k3] and is_cyclic(v3, v)]:
                    for k5, v5 in [(k, v) for k, v in numbers if k not in [k1, k2, k3, k4] and is_cyclic(v4, v)]:
                        for k6, v6 in [(k, v) for k, v in numbers if k not in [k1, k2, k3, k4, k5] and is_cyclic(v5, v)]:
                            if is_cyclic(v6, v1):
                                print sum([v1, v2, v3, v4, v5, v6])
                                return
if __name__ == '__main__':
    main()

