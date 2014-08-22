"""
https://oj.leetcode.com/problems/word-break/
"""
class Solution():
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        if not hasattr(self, 'resultSet'):
            self.resultSet = {}
            
        if s in self.resultSet:
            return self.resultSet[s]
        
        if s in dict:
            self.resultSet[s] = True
            return True
        if len(s) == 1:
            self.resultSet[s] = False
            return False
        
        for idx in xrange(len(s)):
            if idx == 0 :
                continue
            if self.wordBreak(s[:idx], dict):
                self.resultSet[s[:idx]] = True
                if self.wordBreak(s[idx:], dict):
                    self.resultSet[s[idx:]] = True
                    self.resultSet[s] = True
                    return True
                else:
                    self.resultSet[s[idx:]] = False
            else:
                self.resultSet[s[:idx]] = False
        
        self.resultSet[s] = False
        return False
if __name__ == '__main__':
    s = Solution()
    print s.wordBreak('a', ['a'])

