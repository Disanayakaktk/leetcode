class Solution {
public:
    bool isPalindrome(int x) {
        if(9<x){
            int y=x;
            long reversed = 0;
            while(y>0){
                int z= y%10;
                reversed = reversed*10 + z;
                y=y/10;
            }
            return (x==reversed);
        }
        else if(0<=x){
            return true;
        }
        else{
            return false;
        }
    }
};
