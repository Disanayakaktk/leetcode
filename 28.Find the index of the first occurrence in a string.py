class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n_hs = len(haystack)
        n_nd = len(needle)
        if (n_hs<n_nd):return -1
        if (needle==haystack): return 0
        i=0
        while (i<=n_hs-n_nd):
            if(needle[0]==haystack[i]):
                if(n_nd>1):
                    for k in range(1,n_nd):
                        if (needle[k]!=haystack[i+k]):
                            break
                        elif (n_nd-1==k):return i
                else:return i
            i+=1
        return -1
        
