/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int>mp;
    int ans=INT_MIN;
    int res=0;
    
    int maxLevelSum(TreeNode* root) {
        dfs(root,0);
        
        for(auto i:mp){
            if(i.second>ans){
                ans=i.second;
                res=i.first+1;
            }
        }
        
        return res;
    }
    void dfs(TreeNode*r, int lvl){
        if(!r)  return;
        
        mp[lvl]+=r->val;
        
        if(r->left)   dfs(r->left,lvl+1);
        if(r->right)   dfs(r->right, lvl+1);
    }
};