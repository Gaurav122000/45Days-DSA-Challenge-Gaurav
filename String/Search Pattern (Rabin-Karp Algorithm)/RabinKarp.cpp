class Solution {
public:
    vector<int> search(string pattern, string text) {
        int d = 256;
        int mod = 101; // handle overflow - choose preferably prime
        
        int n = text.length();
        int m = pattern.length();
        vector<int> al;
        
        long h = 1;
        for (int i = 1; i <= m - 1; i++)
            h = (h * d) % mod;
        
        long p = 0, t = 0;
        for (int i = 0; i < m; i++) {
            p = (p * d + pattern[i]) % mod;
            t = (t * d + text[i]) % mod;
        }
        
        for (int i = 0; i <= n - m; i++) {
            if (p == t) {
                bool flag = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    al.push_back(i + 1);
            }
            if (i < n - m) {
                t = (d * (t - text[i] * h) + text[i + m]) % mod;
                if (t < 0)
                    t += mod;
            }
        }
        return al;
    }
};
