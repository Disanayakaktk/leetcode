class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_side = 0;     // left side of the container (Initialized)
        int n = height.size(); 
        int right_side = n-1;  // right side of the container (Initialized)
        int max_Area = 0;      // maximum Area
        int current_Area, x;   // current area, x is the moving variable

        // check all possible area  
        while(left_side < right_side){
            if( height[left_side] <= height[right_side] ) {
                // calculate the current area
                current_Area = height[left_side]*(right_side-left_side);
                // update the max area
                if( max_Area < current_Area ) {
                    max_Area = current_Area;
                }
                // get a right movement
                x = left_side + 1;
                // continue the right movement until find a higher line than current left side
                while( x<right_side && height[x] <= height[left_side] ) {
                    x++;
                }
                // Update the left side to x
                left_side = x;
            } else {
                // calculate the current area
                current_Area = height[right_side]*(right_side-left_side);
                // update the max area
                if( max_Area < current_Area ) {
                    max_Area = current_Area;
                }
                // get a left movement
                x = right_side - 1;
                // continue the left movement until find a higher line than current right side
                while(left_side<x && height[x]<=height[right_side]) {
                    x--;
                }
                // Update the right side to x
                right_side = x;
            }
        }
        // return maximum area
        return max_Area;
    }
};
