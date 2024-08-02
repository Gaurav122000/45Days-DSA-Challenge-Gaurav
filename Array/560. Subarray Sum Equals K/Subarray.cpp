class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int i, count = 0, sum = 0;
        mp[0] = 1;

        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];

            if(mp.find(sum-k) != mp.end()){
                count = count + mp[sum-k];// mp[sum+k] means the value that it holds
            }

            if(mp.find(sum) != mp.end()){
                mp[sum]++;
            }else{
                mp[sum] = 1;
            }
        }
        return  count;
    }
};