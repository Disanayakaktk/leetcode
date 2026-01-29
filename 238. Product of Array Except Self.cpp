class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        int minus = 0;
        int Zeros = 0;
        for(int x : nums) {
            Zeros += (x==0);
            if(Zeros>1) {break;}
            minus += (x<0);
        }

        if(Zeros>1) {
            for(int i=0; i<n; i++) {
                output.push_back(0);
            }
        } else if(Zeros==1) {
            for(int i=0; i<n; i++) {
                if(nums[i] != 0) {
                    output.push_back(0);
                } else {
                    int mul = 1;
                    for(int j=0; j<n; j++) {
                        if(nums[j]<-1 || 1<nums[j]) {
                            if(nums[j]<0){
                                if(mul > INT_MAX / -nums[j]) {
                                    mul = INT_MAX;
                                    break;
                                }
                                mul *= -nums[j];
                            } else {
                                if(mul > INT_MAX / nums[j]) {
                                    mul = INT_MAX;
                                    break;
                                }
                                mul *= nums[j];
                            }
                        }
                    }
                    if(minus%2 == 1) {
                        mul = (mul == INT_MAX) ? INT_MIN : -mul;
                    }
                    output.push_back(mul);
                }
            }
        } else {
            bool condition = false;
            int total = 1;
            for(int i=0; i<n; i++) {
                if(nums[i]<-1 || 1<nums[i]) {
                    if(nums[i]<0) {
                        if(total > INT_MAX / -nums[i]) {
                            condition = true;
                            break;
                        }
                        total *= -nums[i];
                    } else {
                        if(total > INT_MAX / nums[i]) {
                            condition = true;
                            break;
                        }
                        total *= nums[i];
                    }
                }
            }
            if(condition) {
                for(int i=0; i<n; i++) {
                    int mul = 1;
                    for(int j=0; j<n; j++) {
                        if(i!=j || nums[j]!=1 || nums[j]!=-1) {
                            if(nums[i]<0) {
                                if(mul > INT_MAX / -nums[i]) {
                                    mul = INT_MAX;
                                    break;
                                }
                                mul *= -nums[j];
                            } else {
                                if(mul > INT_MAX / nums[i]) {
                                    mul = INT_MAX;
                                    break;
                                }
                                mul *= nums[j];
                            }
                        }
                    }
                    if((nums[i]<0 && minus%2==0) || (nums[i]>0 && minus%2==1)) {
                        mul = (mul == INT_MAX) ? INT_MIN : -mul;
                    }
                    output.push_back(mul);
                }
            } else {
                for(int i=0; i<n; i++) {
                    int mul = 1;
                    if((nums[i]<0 && minus%2==0) || (nums[i]>0 && minus%2==0)) {
                        mul = total/nums[i];
                    } else {
                        mul = total/(-nums[i]);
                    }
                    output.push_back(mul);
                }
            }
        }
        return output;
    }
};
