class Solution {
public:
    int maximumBeauty(vector<int>& a, int k) {
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=0;
        // map<int,int>mp;
        int st=-1;
        int st_int=INT_MIN;
        int end_int=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(a[i]-k>end_int){
                st+=1;
                st_int=a[st]-k;
                end_int=a[st]+k;
            }
            ans=max(ans,i-st+1);
        }
        
        return ans;
    }
};