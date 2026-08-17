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
    TreeNode* deletehelp(TreeNode* &root,unordered_set<int> &s,vector<TreeNode*>&result)
    {
        if(root==NULL) return NULL;

        root->left=deletehelp(root->left,s,result);
        root->right=deletehelp(root->right,s,result);

        if(s.find(root->val)!=s.end())
        {
            if(root->left!=NULL)
                result.push_back(root->left);
            if(root->right!=NULL)
                result.push_back(root->right);
            return NULL;
        }
        else 
            return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>result;

        unordered_set<int>s;
        for(int &nums : to_delete)
            s.insert(nums);
        
        deletehelp(root,s,result);
        if(s.find(root->val)==s.end())
            result.push_back(root);
        return result;
    }
};