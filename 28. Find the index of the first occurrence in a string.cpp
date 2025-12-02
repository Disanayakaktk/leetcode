class Solution {
public:
    int strStr(string haystack, string needle) {
        int n_hs = haystack.size();  // length of haystack
        int n_nd = needle.size();    // length of needle
        // check whether haystack >= needle for continue
        if(n_hs<n_nd){return -1;}    
        // check whether both are same
        if(needle==haystack){return 0;}
        // Do the operation for the condition haystack >= needle
        int i = 0;
        while(i<=n_hs-n_nd){
            // Initially check 1st char with haystack
            if(needle[0]==haystack[i]){
                // check others if needle has more than 1 chars
                if(n_nd>1){
                    for(int k=1;k<n_nd;k++){
                        if(needle[k]!=haystack[i+k]){
                            break;
                        }
                        else if(n_nd-1==k){return i;}
                    }
                }
                else{return i;} // check if needle has only 1 char
            }
            i++;  // skip to the next char of haystack 
        }
        return -1;
    }
};
