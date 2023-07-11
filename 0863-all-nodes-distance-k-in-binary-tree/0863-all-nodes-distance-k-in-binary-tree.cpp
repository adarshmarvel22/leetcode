/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*>mp;
    
    void dfs(TreeNode*root, TreeNode*par){
        if(!root)  return;
        if(!par)  par=root;
        
        mp[root]=par;
        dfs(root->left,root);
        dfs(root->right, root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         dfs root to parent mapping
        dfs(root, NULL);
//         bfs to traverse level wise from the target node
        queue<TreeNode*>q;
        set<TreeNode*>st;
        
//         to keep count of the levels
        int cnt=0;
        
//         to store the kth level nodes(the kth dist nodes from the target)
        vector<int>res;
        
//         starting bfs from the target node to kth lvl
        q.push(target);
        
        while(!q.empty()){
           int sz=q.size();
            
            if(cnt>k)  break;
            
            while(sz--){
                TreeNode*curr=q.front();
                q.pop();
                
                if(curr->left!=NULL and !st.count(curr->left)){
                    q.push(curr->left);
                    st.insert(curr->left);
                }
                if(curr->right!=NULL and !st.count(curr->right)){
                    q.push(curr->right);
                    st.insert(curr->right);
                }
                
                if(mp.count(curr) and !st.count(mp[curr])){
                    q.push(mp[curr]);
                    st.insert(mp[curr]);
                    
                }
                st.insert(curr);
                if(cnt==k){
                    res.push_back(curr->val);
                }
                
            }
            cnt+=1;
        }
        
        return res;
    }
};