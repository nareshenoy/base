class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    def wordBreak(self, s, dict):
        if not hasattr(self, 'cache'):
            self.cache = {}
        
        #print s
        if s in self.cache: return self.cache[s]
        soln = []
        if s in dict:
            soln.append(s)
        
        for idx in range(1, len(s)):
            #print 'Running for index', idx
            if s[:idx] in dict:
                sol = self.wordBreak(s[idx:], dict)
                if sol:
                    for sol_ex in sol:
                        #print 'Found solution', sol, 'for index', idx
                        l = [s[:idx]] + [sol_ex]
                        #print s, s[:idx], s[idx:], sol, l
                        soln.append(' '.join(l))
        self.cache[s] = soln
        return soln
 
if __name__ == '__main__':
    #a = Solution()
    #print a.wordBreak("catsanddog", ["cat","cats","and","sand","dog"])
    c = Solution()
    print c.wordBreak("a", ["aaaa","aa","a"])
    d = Solution()
    print d.wordBreak("aa", ["aaaa","aa","a"])
    e = Solution()
    print e.wordBreak("aaa", ["aaaa","aa","a"])
    b = Solution()
    print b.wordBreak("aaaaaaa", ["aaaa","aa","a"])
    f = Solution()
    print f.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"])
