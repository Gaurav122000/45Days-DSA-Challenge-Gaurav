class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> series;
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int pos = findInsertPosition(series, nums[i]);
            series.insert(series.begin() + pos, nums[i]);
            ans.push_back(pos);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int findInsertPosition(vector<int>& series, int target) {
        int l = 0;
        int h = series.size();
        while (l < h) {
            int mid = (l + h) / 2;
            if (series[mid] >= target) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};