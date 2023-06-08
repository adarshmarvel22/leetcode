class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]<0)  cnt++;
            }
        }
        
        return cnt;
    }
};