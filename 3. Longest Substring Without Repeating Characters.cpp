class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0){return 0;}
        if(n==1){return 1;}
        int i=1, j=1, length=1, longest = 1;
        vector<char> arr = {s[0]};

        while(j<n){
            // Create this array by initializing all elements are false
            bool present[256] = {false};
            // Mark all characters in arr
            for (char c : arr) {
                present[(unsigned char)c] = true;
            }
            bool found = present[(unsigned char)s[j]];  // check the new character

            if(found){   // If found a duplicate character in arr
                arr.clear();
                arr.push_back(s[i]);
                i++;
                length=1;
                j=i;
            }
            else{     // If s[j] not in arr
                arr.push_back(s[j]);
                length++;
                if(longest<length){
                    longest=length;
                }
                j++;
            }
        }
        return longest;   // return longest substring
    }
};
