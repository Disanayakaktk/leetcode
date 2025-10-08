


class Solution {
public:
    
    long long nCr(int n,int r){
        
        long long result = 1;
        if(r>n-r){
            for(int i=0;i<(n-r);i++){
                result*=(n-i);
                result/=i+1;
            }
        }
        else{
            for(int i=0;i<r;i++){
                result*=(n-i);
                result/=i+1;
            }
        }
        return result;
    }
    int climbStairs(int n) {
        int sum=0;
        int s=n/2;
        int r=0;
        while(r<=s){
            sum+=nCr(n,r);
            n--;
            r++;
        }
        return sum;
    }
};
