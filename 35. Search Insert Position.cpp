class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        int n = nums.size();
        while(i<n && target>=nums[i]){   
            if(target==nums[i]){return i;}
            i++;
        }
        return i;
    }
};
