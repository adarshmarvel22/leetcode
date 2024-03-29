class Solution {
public:
    map <int,vector<int>> mp;
    int dp[100001];
    int ans = 0;
    int helper(int idx,vector<int>& arr,int& diff){
        if(idx>=arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int res = 1;
        int nxtval = arr[idx]+diff;
        if(mp.find(nxtval)!=mp.end()){
            auto nxtidx = upper_bound(mp[nxtval].begin(),mp[nxtval].end(),idx);
            if(nxtidx!=mp[nxtval].end()){
                res = 1+helper(*nxtidx,arr,diff);
            }
        }
        helper(idx+1,arr,diff);
        ans = max(ans,res);
        return dp[idx] = res;
    }
    int longestSubsequence(vector<int>& arr, int diff) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        helper(0,arr,diff);
        return ans;
    }
};