class Solution{
    
  public:
    int largestRectangleArea(vector <int>& histo){// time compalexity of this function is O(n)
        stack <int> st;
        int maxA = 0;
        int n = histo.size();
        
        for(int i = 0; i<=n; i++){
            while(!st.empty() && (i == n || histo[st.top()] >= histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int maxArea = 0;
        vector<int> height(m, 0); 
        for(int i = 0; i<n; i++){//O(n)
            for(int j = 0; j<m; j++){//O(m)
                if(M[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }// time complexity of this function is O(n x m);
};