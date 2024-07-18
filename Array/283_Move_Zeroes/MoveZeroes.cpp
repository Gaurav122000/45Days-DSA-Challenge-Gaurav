//Brute-force
#include <vector>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }else{
                count++;
            }
        }
        int n=temp.size();
        int m=n;
        n+=count;
        nums.clear();
        for(int i=0; i<n; i++){
            if(0!=m){
                nums.push_back(temp[i]);
                --m;
            }
            else{
                nums.push_back(0);
            }
        }
    }
};
//-----------------------------------------------------------------------------------------------------
//Optimized Solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0, k=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                swap(nums[j], nums[i]);
                j++;
            }
        }
    }
};