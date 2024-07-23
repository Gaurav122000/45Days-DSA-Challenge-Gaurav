class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    long long ans = LLONG_MAX;
    sort(a.begin(), a.end());
    
    for(int i=0; i<n-m+1; i++){     // i+m-1<n ->. i<n-m+1
        ans=min(ans, a[i+m-1]-a[i]);
    }
    return ans;
    }   
};