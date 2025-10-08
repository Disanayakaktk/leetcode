class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        size = len(strs)
        lcp = []
        size_0 = len(strs[0])
        for j in range(size_0):
            count=1
            for k in range(1,size):
                '''if(strs[0][j] in strs[k]):
                    count += 1
                else:break'''
                if j < len(strs[k]) and strs[0][j] == strs[k][j]:
                    count += 1
                else:
                    return "".join(lcp) 
            if(count==size):
                lcp.append(strs[0][j])
                '''for k in range(1,size):
                    strs[k].replace(strs[0][j],"",1)'''
        return "".join(lcp)
