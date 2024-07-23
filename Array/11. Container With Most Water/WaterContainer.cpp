#include<cmath>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxArea = 0;
        while(l<r){
            int lh = height[l];
            int rh = height[r];
            int minH = min(lh, rh);
            maxArea = max(maxArea, minH*(r-l)); //height*lenght
            if(lh<rh){
                l++;
            }
            else{
                r--;
            }
        }
        return maxArea;
    }
};
//Time Complexcity = O(n);