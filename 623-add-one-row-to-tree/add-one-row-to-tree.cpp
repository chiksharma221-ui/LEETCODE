class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth == 1) {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;

        while(!q.empty()) {

            int size = q.size();

            if(level == depth - 1) {

                while(size--) {

                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* leftemp = node->left;
                    TreeNode* rightemp = node->right;

                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);

                    node->left->left = leftemp;
                    node->right->right = rightemp;
                }

                break;
            }

            while(size--) {

                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            level++;
        }

        return root;
    }
};