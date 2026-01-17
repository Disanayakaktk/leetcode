class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        vector<int> output = {-1, -1};
        if(n==0 || nums[start]>target || nums[end]<target) {
            return output;
        }
        bool start_found = false;
        bool end_found = false;
        while(start<=end) {
            if(nums[start]==target && !start_found) {
                output[0]=start;
                start_found=true;
                if(end_found){
                    break;
                }
            }
            if(nums[end]==target && !end_found) {
                output[1]=end;
                end_found=true;
                if(start_found){
                    break;
                }
            }
            int mid = (start+end)/2;
            if(nums[mid]<target){
                start = mid+1;
                if(!end_found){
                    end--;
                }
            }
            else if(nums[mid]>target){
                end = mid-1;
                if(!start_found){
                    start++;
                }
            } else {
                if(!start_found){
                    start++;
                }
                if(!end_found){
                    end--;
                }
            }
        }
        return output;
    }
};
