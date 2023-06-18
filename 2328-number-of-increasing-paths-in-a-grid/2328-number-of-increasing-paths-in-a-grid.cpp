class Solution {
public:
    int mod=1e9+7;
    int f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp,int parent){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]<=parent){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int up=f(grid,i-1,j,dp,grid[i][j]);
        int dn=f(grid,i+1,j,dp,grid[i][j]);
        int lt=f(grid,i,j-1,dp,grid[i][j]);
        int rt=f(grid,i,j+1,dp,grid[i][j]);
       
        
        return dp[i][j]=(up%mod+dn%mod+lt%mod+rt%mod+1)%mod;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(dp[i][j]==-1){
                    f(grid,i,j,dp,-1);
                }
            }
        }
        
        long long ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=(ans+dp[i][j])%mod;
            }
        }
        return ans;
        
    }
};