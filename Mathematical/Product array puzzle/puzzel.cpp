class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n = nums.size();
        vector<long long>left(n,1),right(n,1);
        for(int i=1;i<n;i++) {
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--) {
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++) {
            nums[i] = left[i]*right[i];
        }
        return nums;
    }
};
