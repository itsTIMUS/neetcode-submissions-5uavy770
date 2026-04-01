class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l= 0;
        int r= n-1;
        int val= 0;
        while(l<r){
            val= max(val,min(heights[l],heights[r])*(r-l));
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return val;
    }
};
