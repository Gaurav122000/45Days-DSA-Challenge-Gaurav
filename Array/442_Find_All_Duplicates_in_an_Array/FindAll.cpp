#include<cmath>
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            //get the index, the element corresponds to
            int index = abs(nums[i]) - 1;//now it's pointing towards the next element index 
            //eg - if we have element 4 and we -1 then we have 3 which pointing towards the 3rd index

            //if the number is already negative, it means we are
            //encountering it twice
            if(nums[index] < 0){
                result.push_back(index + 1);
            } 

            //flip the number at the index to negative
            nums[index] = nums[index] * -1;

        }
        return result;
    }
};