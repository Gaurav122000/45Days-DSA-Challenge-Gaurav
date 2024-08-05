class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        //now check if the character is word or symbol
        for(char c:S){
            if(isdigit(c)){//if digit
                st.push(c-'0');
            }else{//if not digit than pop 2 elements
                int y = st.top();
                st.pop();
                
                int x = st.top();
                st.pop();
                
                switch(c){
                    case'+':
                    st.push(x+y);
                    break;
                    
                    case'-':
                    st.push(x-y);
                    break;
                    
                    case'*':
                    st.push(x*y);
                    break;
                    
                    case'/':
                    st.push(x/y);
                    break;
                }
            }
        }
        return st.top();
    }
};