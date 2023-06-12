class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int i,j,k,c=0;
        vector<string>v;
        i=0;
        if(a.size()==0)
        return v;
        while(i<a.size()-1){
            if(a[i+1]-a[i]>1){
                v.push_back(to_string(a[i]));
                i++;
            } else{
                j=i+1;
                k=i;
                while(j<a.size() and (a[j])<=1+a[k]){
                    j++;
                    k++;
                }
                string s=to_string(a[i])+"->"+to_string(a[j-1]);
                v.push_back(s);
                i=j;
            }
            
        }
        if(i<a.size()){
            v.push_back(to_string(a[i]));
        }
        return v;
        
    }
};