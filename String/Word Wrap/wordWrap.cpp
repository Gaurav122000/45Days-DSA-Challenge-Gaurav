class Solution {
public:

    //for eg - nums = {3,2,2,5}, k = 6;

    //create 2D Dp
    int dp[505][2005];
    
    int rec(int i, int rem, vector<int>& nums,int &k){
        
        if(i == nums.size()){// if i have reached the end of the last word
            return 0;
        }
        
        if(dp[i][rem]!=-1){// if it's already calculated 
            return dp[i][rem];
        }
        
        int ans; //for storing 
        //the main logic part off the code
        if(nums[i]>rem){//since our word is bigger than the remaining space
            ans=(rem+1)*(rem+1)+rec(i+1, k-nums[i]-1, nums, k);
        }
        else{  // (6-3)^2 -> 3   *   3 
            int choice1 = (rem+1)*(rem+1)+rec(i+1, k-nums[i]-1, nums, k);//next line
            int choice2 = rec(i+1, rem-nums[i]-1, nums, k); // same line
            
            // we gonna explore both the choice 
            ans = min(choice1, choice2);
        }
        
        dp[i][rem] = ans;
        return dp[i][rem];
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // initiallize the dp to -1
        memset(dp, -1, sizeof(dp));
        rec(0, k, nums, k);
    } 
};