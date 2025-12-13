class Solution {
public:
    int reverse(int x) {
        // Initialize reverse intiger
        int rev = 0;
        while(x!=0){
            int ls_digit = x%10;
            // Return 0 if reversing x would cause overflow/underflow
            if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
                return 0; 
            }
            x /= 10;
            rev = rev*10 + ls_digit;
        }
        return rev;
    }
};
