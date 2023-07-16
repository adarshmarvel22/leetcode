class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int startIndex = -1, i = 0, n = v.size(), ans = 0;
        int startInterval = -1e7, endInterval = -1e7;
        for(i = 0; i < n; i += 1) {
            while(v[i] - k > endInterval) {
                startIndex += 1;
                startInterval = v[startIndex] - k;
                endInterval = v[startIndex] + k;
            }
            ans = max(ans, i - startIndex + 1);
        }
        return ans;
    }
};