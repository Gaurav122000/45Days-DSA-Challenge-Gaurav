class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st; // to store element that have no day hotter then them yet....
        vector<int> result(temperatures.size(), 0); // create a vector of similar size and initialize it with zero

        for(int i = 0; i < temperatures.size(); i++){
            //if current temp > previous then pop, upate and add
            //else move and add
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int idx = st.top(); 
                st.pop();
                result[idx] = i - idx;
            }
            st.push(i);
        }
        return result;
    }
};