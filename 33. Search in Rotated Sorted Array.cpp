class Solution {

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int j=n-1;
        while(0<j && nums[j-1]<nums[j]){
            j--;
        }
        vector<int> result;
        if(j>0){
            result.insert(result.end(), nums.begin() + j, nums.end()); 
            result.insert(result.end(), nums.begin(), nums.begin() + j);
        } else {
            result=nums;
        }
        if(result[0]<=target && target<=result[n-1]) {
                int left = 0;
                int right = n-1;
                int middle = (left+right)/2;
                while(left<=right) {
                    if(target==result[left]){
                        return (j+left)%n;
                    } else if(target==result[right]) {
                        return (j+right)%n;
                    } else if(target<result[middle]) {
                        right=middle-1;
                        middle = (left+right)/2;
                    } else if(target>result[middle]) {
                        left=middle+1;
                        middle = (left+right)/2;
                    } else {
                        return (j+middle)%n;
                    }
                }
                return -1;
            } else {return -1;}
    }
};
