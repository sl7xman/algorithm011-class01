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
private:
    void preorderTraversalval(TreeNode* root, vector<int>& res) {
        //mid
        res.push_back(root->val);
        //left
        if( root->left ) {
            preorderTraversalval( root->left, res );
        }
        //right
        if( root->right ){
            preorderTraversalval( root->right, res );
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if( root != nullptr ) {
            preorderTraversalval(root, ans);
        }

        return std::move(ans);
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if( root == nullptr ){
            return ans;
        }

        stack<TreeNode*> s;
        s.push(root);
        while( !s.empty() ) {

            TreeNode* tmp = s.top();
            s.pop();
            ans.push_back(tmp->val);
            if( tmp->right ){
                s.push(tmp->right);
            }
            if ( tmp->left ) {
                s.push(tmp->left);
            }
        }

        return std::move(ans);
    }
};
