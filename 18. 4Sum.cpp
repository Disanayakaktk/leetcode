class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> arr_2D;
        int n = nums.size();
        if(n<4){
            return arr_2D;
        }
        long long sum;
        sort(nums.begin(),nums.end());
        int first = 0;
        int last =n-1;
        while( first<n-3) {
            if((long long)nums[first] + nums[first+1] + nums[first+2] + nums[first+3] > target) break;
            if((long long)nums[first] + nums[n-1] + nums[n-2] + nums[n-3] < target) {
                first++;
                continue;
            }
            int p2 = first+1;
            int p3 = last-1;
            while(p2<p3) {
                sum = (long long)nums[first] + nums[p2] + nums[p3] + nums[last];
                if (target>sum) {
                    p2++;
                    while(p2<p3 && nums[p2]==nums[p2-1]){
                        p2++;
                    }
                } else if (target<sum) {
                    p3--;
                    while(p2<p3 && nums[p3]==nums[p3+1]){
                        p3--;
                    }
                } else {
                    vector<int> arr_1D;
                    arr_1D.push_back(nums[first]);
                    arr_1D.push_back(nums[p2]);
                    arr_1D.push_back(nums[p3]);
                    arr_1D.push_back(nums[last]);
                    arr_2D.push_back(arr_1D);
                    p2++;
                    p3--;
                    while(p2<p3 && nums[p2]==nums[p2-1]){
                        p2++;
                    }
                    while(p2<p3 && nums[p3]==nums[p3+1]){
                        p3--;
                    }
                }
            }
            if (last>first+2){
                last--;
                while((last>first+2) && nums[last]==nums[last+1]){
                    last--;
                }
            } else {
                last = n-1;
                first++;
                while(first<(last-2) && nums[first]==nums[first-1]){
                    first++;
                }
            }
        }
        return arr_2D;
    }
};
