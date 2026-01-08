// This code is very fast. It's runtime is about 0ms
// Also, this code has beats 100%. But memory usage is high (95.80MB Beats 28.78%)
 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i=0, j=0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]<=nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(j<nums2.size()){
            arr.push_back(nums2[j]);
            j++;
        }
        while(i<nums1.size()){
            arr.push_back(nums1[i]);
            i++;
        }
        i = arr.size();
        j = i/2;
        if(i%2==0){
            double output = (arr[j]+arr[j-1])/2.0;
            return output;
        } else {
            double output = arr[j];
            return output;
        }
    }
};



// This code was created to reduce memory waste
// Also, this code has beats 60.89% by using 95.18MB memory space
// Run time of this code is 1ms (beats 37.42%)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int t = n1+n2;
        int mid = t/2;
        int i = 0, j = 0;
        int prev = 0, curr = 0;

        for(int count=0; count<=mid; count++){
            prev=curr;

            if(j<n2 && (i>=n1 || nums1[i]>nums2[j])){
                curr = nums2[j];
                j++;
            } else {
                curr = nums1[i];
                i++;
            }
        }
        if(t%2==0){
            double output = (prev+curr)/2.0;
            return output;
        } else {
            double output = curr;
            return output;
        }
    }
};

