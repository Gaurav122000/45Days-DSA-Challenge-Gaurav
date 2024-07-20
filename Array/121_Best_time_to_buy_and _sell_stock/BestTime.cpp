#include<cmath>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int maxSoFar = 0;

        for(int i=0; i<prices.size(); i++){
            minSoFar = min(minSoFar, prices[i]);
            int price = prices[i] - minSoFar;
            maxSoFar = max(maxSoFar, price);
        }
        return maxSoFar;
    }
};