class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& preq) {
        
        int n=preq.size();
        vector<vector<int>>adj(num);
        vector<int>indeg(num);
        
        vector<int>vis(num,0);
        
        for(auto &e:preq){
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        
        queue<int>q;
        
for(int i=0;i<indeg.size();i++){
    if(indeg[i]==0)  q.push(i);
}
        
//         bfs for topo sort
        int notvis=0;
        while(!q.empty()){
                int node=q.front();
                q.pop();
            notvis++;
                
                for(auto &x:adj[node]){
                    indeg[x]--;
                    if(indeg[x]==0)
                    q.push(x);
                }
        }
        // cout<<num<<" "<<notvis; 
        return num==notvis;
    }
};