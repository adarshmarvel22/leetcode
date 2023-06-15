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
    int mi=INT_MAX;
    
    void f(TreeNode* root,vector<int>&v){
        if(!root)   return;
        
        // if(!pq.empty()){
        //     int x=pq.top();
        //     mi=min(mi,abs(x-root->val));
        // }
        v.push_back(root->val);
        
        f(root->left,v);
        f(root->right,v);
    }
    
    int getMinimumDifference(TreeNode* root) {
        
        // priority_queue<int>pq;
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>v;
        f(root,v);
        
        sort(v.begin(),v.end());
        
        int n=v.size();
        for(int i=0;i<n-1;i++){
            pq.push(v[i+1]-v[i]);
        }
        
        return pq.top();
    }
};