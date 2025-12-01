
public:
    int removeElement(vector<int>& nums, int val) {
        // Get the initial size of the array
        int n = nums.size();
        int j = 0;    // Track the end 
        int i = 0;    // Current checking point
        while(j<n){
            if(val == nums[i]){
                // Erase he element at the position i
                nums.erase(nums.begin()+i);
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        // count of the remaining elements
        int k = nums.size();
        return k;
    }
};
