class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        
        int val=f(0,n-1,nums,0,n,dp);
        return val>=0;
    }
    
    int f(int l,int r,vector<int>&a, int turn,int n,vector<vector<vector<int>>>&dp){
        if(l>=n or r<0)  return 0;
        if(l>r)   return 0;
        if(dp[l][r][turn]!=0)  return dp[l][r][turn];
        
        if(turn == 0){
            return dp[l][r][turn]=max(a[l]+f(l+1,r,a,1,n,dp),
                      a[r]+f(l,r-1,a,1,n,dp)
                      );
        }
        else{
            return dp[l][r][turn]=min(-a[l]+f(l+1,r,a,0,n,dp),
                      -a[r]+f(l,r-1,a,0,n,dp)
                      );
        }
    }
};