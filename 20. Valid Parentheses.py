class Solution:
    def isValid(self, s: str) -> bool:
        m = {')':'(','}':'{',']':'['}
        a = []
        for i in range(len(s)):
            if(s[i]=='(' or s[i]=='{' or s[i]=='['):
                a.append(s[i])
            else:
                if not a:
                    return False
                top_i = a.pop()
                if(m[s[i]]!=top_i):
                    return False
        return len(a)==0
