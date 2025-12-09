class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();   // length of the string  
        if(n<=1){return s;}  // If s is empty or a character
        // Initialize require variables 
        int i=0, j=0, k, l;
        int length, longest=0;
        int start;

        // loop from start index=0 to n-1
        while(i<n-1){
            k=i, l=j;  //initialize k&l for substring operations
            while(k<=l){
                if(s[k]==s[l]){ // continue the substring checking process
                    k++;
                    l--;
                }
                else{break;}  // stop current process
            }
            if(k>l){  
                // If it's a palindromic check whether it's the longest than previous
                length = j-i+1;
                if(length>longest){
                    longest=length;
                    start=i;
                }
            }
            // trun to another sub string
            if(j<n-1){j++;}
            else{
                
                i++;
                j=i+longest;
                if(j>=n){break;}
            }
        }
        // Get the longest and first found Palindromic substring
        string substring = s.substr(start,longest);
        return substring;  
    }
};
