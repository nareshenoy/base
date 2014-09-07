
def permute(string):
    if len(string) == 1: return [string]
    all_perms = []
    for idx, ch in enumerate(string):
        perms_wo_ch = permute(string[:idx] + string[idx + 1:])
        for p in perms_wo_ch:
            for idx in range(len(p)):
                all_perms.append(p[:idx] + ch + p[idx:])
    return set(all_perms)

def main():
    string = raw_input()
    print 'Input is: ', string
    perms = permute(string)
    print 'Total ', len(perms), 'permutations', perms
if __name__ == '__main__':
    main()

