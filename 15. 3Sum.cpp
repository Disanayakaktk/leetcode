class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arr_2D;  // Output
        int length = nums.size();    // size of the nums array
        sort(nums.begin(), nums.end());  // sort nums array
        
        // Initialize the first element and use it to initialize other 2 pointers 
        for(int i=0;i<length-2;i++){
            if(i>0 && nums[i]==nums[i-1]){  // skip duplicates
                continue;
            }
            if(nums[i]>0){  // Impossible to get sum as 0
                break;
            }
            // Other 2 points
            int left = i+1;
            int right = length-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0){ // found a triplet
                    // put triplet into 2D array
                    arr_2D.push_back({nums[i], nums[left], nums[right]});

                    // skip duplicates for left pointer
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    // skip duplicates for right pointer
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    // move both
                    left++;
                    right--;
                } else if(sum>0){ // since sum too large reduce the large number
                    right--;
                } else {left++;}  // sincr sum too small increase the small number
            }
        }
        return arr_2D;  // return 2D array
    }
};
