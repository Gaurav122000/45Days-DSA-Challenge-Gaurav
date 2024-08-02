class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        stack.push(-1);
        int max_area = 0;

        for(int i=0; i < heights.size(); i++){
            while(stack.top() != -1 && heights[i] <= heights[stack.top()]){
                //assign height of top element in the stack
                int height = heights[stack.top()];
                //then pop that index out from stack
                stack.pop();
                int width = i - stack.top() - 1;//current index - latest index
                max_area = max(max_area, height * width);
            }
            //pushing the larger element in the stack
            stack.push(i);
        }

        while(stack.top() != -1){
            int height = heights[stack.top()];
            stack.pop();
            int width = heights.size() - stack.top() - 1;
            max_area = max(max_area, height * width);
        }

        return max_area;
    }
};