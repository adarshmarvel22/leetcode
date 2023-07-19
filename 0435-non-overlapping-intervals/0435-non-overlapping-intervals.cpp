bool cmp(const vector<int>&a,const vector<int>&b){
    if(a[1]<b[1])   return true;
    
    return false;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), cmp);
        int ans = 0;
        int k = INT_MIN;
        
        for (int i = 0; i < a.size(); i++) {
            int x = a[i][0];
            int y = a[i][1];
            
            if (x >= k) {
                // Case 1
                k = y;
            } else {
                // Case 2
                ans++;
            }
        }
        
        return ans;
    }
};