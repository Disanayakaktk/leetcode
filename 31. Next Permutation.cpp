class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n>1) {
            int i = n-1;
            int j = n-2;
            while( true ) {
                if(nums[j]<nums[i]) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    if( i != n-1 || j != n-2 ) {
                        sort(nums.begin()+j+1,nums.end());
                    }
                    break;
                } else {
                    if(j==0 && i==1) {
                        return sort(nums.begin(),nums.end());
                        break;
                    }
                    if( i-j>1 ) {
                        i--;
                    } else {
                        j--;
                        i=n-1;
                    }
                }
            }
        }
    }
};
