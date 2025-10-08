class Solution:
    def romanToInt(self, s: str) -> int:
        Rom_num = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        Rom_Char=list(s)
        count=0
        i=0
        while(i<len(Rom_Char)):
            if(i<len(Rom_Char)-1 and Rom_num[Rom_Char[i]]<Rom_num[Rom_Char[i+1]]):
                count += Rom_num[Rom_Char[i+1]]-Rom_num[Rom_Char[i]]
                i += 2
            else:   
                count += Rom_num[Rom_Char[i]]
                i += 1
            
        return count
        
