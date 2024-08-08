class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int> freqP(26, 0); // frequency of character in p
        for (char c : p){
            freqP[c - 'a']++;
        }
        
        int left = 0, right = 0;
        int count = 0;// Number of characters of P found in the current window
        int minLen = INT_MAX;
        int startIdx = -1; // Starting index of the minimum window
        
        while(right < s.size()){
            freqP[s[right] - 'a']--;
            if(freqP[s[right] - 'a'] >= 0){
                count++;
            }
            
            while(count == p.size()){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    startIdx = left;
                }
                
                freqP[s[left] - 'a']++;
                if(freqP[s[left] - 'a'] > 0){
                    count--;
                }
                left++;
            }
            right++;
        }
        if(startIdx == -1){
            return "-1";
        }
        return s.substr(startIdx, minLen);
    }
};