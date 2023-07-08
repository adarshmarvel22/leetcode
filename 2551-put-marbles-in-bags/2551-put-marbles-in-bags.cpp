class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        vector<long long>tmp;
        int n=w.size();
        
        long long mx=w[0]+w[n-1];
        long long mi=w[0]+w[n-1];
        
        if(n==1||k==1)  return 0;
        
        for(int i=0;i<n-1;i++){
            if(i==n)  tmp.push_back(1ll*w[i]);
            else
            tmp.push_back(1ll*w[i]+1ll*w[i+1]);
        }
        
        sort(tmp.begin(),tmp.end());
        
        for(int i=0;i<k-1;i++){
            mi+=tmp[i];
            mx+=tmp[n-2-i];
        }
        
        return mx-mi;
    }
};