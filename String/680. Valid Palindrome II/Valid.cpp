class Solution {
public:

    bool check(string s, int i, int j){
         while(j>=i){
            if(s[i]!=s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(j>=i){
            if(s[i]!=s[j]){
                return check(s, i+1, j) || check(s, i, j-1);
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};