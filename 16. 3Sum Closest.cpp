//----- Method 1 -----//

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int closest;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int left = i+1;
            int right = n-1;
            while(left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                int gap = sum - target;
                int abs_gap = abs(gap);
                if(diff>abs_gap) {
                    diff=abs_gap;
                    closest=sum;
                }
                if(gap>0) {
                    right--;
                } else if(gap<0) {
                    left++;
                } else {
                    return closest;
                }
            }
        }
        return closest;
    }
};


//----- Method 2 -----//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int closest;
        int n = nums.size();
        sort(nums.begin(),nums.end());
    
        for(int i=0;i<n-2;i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int left = i+1;
            int right = n-1;
            while(left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                int gap = sum - target;
                int abs_gap = abs(gap);
                if(diff>abs_gap) {
                    diff=abs_gap;
                    closest=sum;
                }
                if(gap>0) {
                    right--;
                } else if(gap<0) {
                    left++;
                } else {
                    return closest;
                }
            }
            if(i<0 && nums[i]>target) {
                return closest;
            }
        }
        return closest;
    }
};
