class StockSpanner {
public:
    stack<pair<int, int>> stack; // price, ans

    StockSpanner() {}

    int next(int price) {
        int ans = 1;
        // Monotonically decreasing stack
        while (!stack.empty() && stack.top().first <= price) { //if our stack is not empty and stack has first element is smaller 
            ans = ans + stack.top().second; // second means the answer of the last one is here
            stack.pop();
        }
        stack.push({price, ans});
        return ans;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */