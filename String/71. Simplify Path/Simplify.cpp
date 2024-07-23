class Solution {
public:
    string simplifyPath(string path) {
        vector<string> arr;
        istringstream iss(path);
        string token;
        
        while (getline(iss, token, '/')) {
            if (token == "..") {
                if (!arr.empty()) {
                    arr.pop_back();
                }
            } else if (!token.empty() && token != ".") {
                arr.push_back(token);
            }
        }
        
        string result;
        for (const string& dir : arr) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};