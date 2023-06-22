class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
                int n=a.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
    
        if(n==0) return 0;
        int ans = getAns(a,0,0,n,dp,fee);
        return ans;
    }
    long getAns(vector<int>& Arr, int ind, int buy, int n, vector<vector<int>> &dp ,int fee){

        if(ind==n) return 0; //base case

        if(dp[ind][buy]!=-1)
            return dp[ind][buy];

        long profit;

        if(buy==0){// We can buy the stock
            profit = max(0+getAns(Arr,ind+1,0,n,dp,fee), -Arr[ind] + getAns(Arr,ind+1,1,n,dp,fee));
        }

        if(buy==1){// We can sell the stock
            profit = max(0+getAns(Arr,ind+1,1,n,dp,fee), Arr[ind]-fee + getAns(Arr,ind+1,0,n,dp,fee));
        }

        return dp[ind][buy] = profit;
    }
};