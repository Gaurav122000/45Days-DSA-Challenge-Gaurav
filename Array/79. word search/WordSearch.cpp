class Solution {
public:

    bool helper(vector<vector<char>>& board, string word, int i, int j, int n, int m, int k){
        if(k>=word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='.') return false;
        if(word.size() == 1 && word[k] == board[i][j]) return true;//if we left with only 1 word and that present in the i j then return true
        if(word[k]!=board[i][j]) return false;//if the first letter is not present in the grid then we don't need to check the others
        board[i][j] = '.';
        bool temp = false;
        int x[4] = {0, 0, -1, 1};
        int y[4] = {-1, 1, 0, 0};
        for(int index=0; index<4; index++){
            temp = temp || helper(board, word, i+x[index], j+y[index], n, m, k+1);
        }
        board[i][j] = word[k];
        return temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();//row
        if(n==0) return false;//if their is no row present in the array then no need to check
        int m=board[0].size();//column
        if(word.size()==0) return false;//if no word is given then no need to check
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){//if we got the first element match then we start the recurssion
                    if(helper(board,word,i,j,n,m,0)) return true;
                }
            }
        }
        return false;
    }
};