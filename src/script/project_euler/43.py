from copy import deepcopy

global sum_nums

def digitize(n):
    digits = []
    for i in range (0, 10):
        digits.append(n % 10)
        n = n / 10
    digits.reverse()
    return digits

def check_property(n):
    digits = digitize(n)
    if digits[3] % 2 != 0:
        return False
    if (digits[2] + digits[3] + digits[4]) % 3 != 0:
        return False
    if digits[5] % 5 != 0:
        return False
    if (digits[4] * 100 + digits[5] * 10 + digits[6]) % 7 != 0:
        return False
    if (digits[5] * 100 + digits[6] * 10 + digits[7]) % 11 != 0:
        return False
    if (digits[6] * 100 + digits[7] * 10 + digits[8]) % 13 != 0:
        return False
    if (digits[7] * 100 + digits[8] * 10 + digits[9]) % 17 != 0:
        return False
    
    return True
def generate_permutations(n, rem_digits, sum_nums):
    #print "Called with n: ", n , " and rem_digits: ", rem_digits
    perms = []
    if len(rem_digits) == 0:
        if check_property(n):
            sum_nums = sum_nums + n
        return sum_nums
    for digit in rem_digits:
        if len(rem_digits) == 7 and digit % 2 == 1:
            #print digit, rem_digits
            continue
        if len(rem_digits) == 5 and digit % 5 != 0:
            #print digit, rem_digits            
            continue
        
        new_list = deepcopy(rem_digits)
        new_list.remove(digit)
        sum_nums = generate_permutations(n * 10 + digit, new_list, sum_nums)

    #print "Returning: ", perms
    return sum_nums

def main():
    sum_nums = 0
    for num in range (1, 10):
        all_nums = []
        digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        digits.remove(num)
        sum_nums = generate_permutations(num, digits, sum_nums)
        print sum_nums

if __name__ == '__main__':
    main()
