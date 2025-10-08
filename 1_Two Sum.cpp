class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        map<int,int> map;
        for(int i=0;i<length;i++){
            int needed = target-nums[i];
            if(map.find(needed) != map.end()){
                return {map[needed],i};
            }
            map[nums[i]] = i;
        }
        return {-1,-1};
    }
};
