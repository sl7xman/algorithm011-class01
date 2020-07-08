class Solution {
public:
    int minDepth(TreeNode* root) {
        if( root == nullptr ){
            return 0;
        }
        int ans = 0;
        vector<TreeNode*> cur_level ;
        cur_level.push_back(root);
        levelOrder( cur_level, ans);
        return ans;
    }

private:
    void levelOrder( vector<TreeNode*>& cur_level, int& res ){
        if ( cur_level.size() == 0 ){
            return ;
        }
        ++res;
        vector<TreeNode*> next_level;

        for ( auto it = cur_level.begin(); it != cur_level.end();  ++it ){
            TreeNode* tmp = *it;
            if (tmp->left == nullptr && tmp->right == nullptr ){
                next_level.clear();
                break;
            }

            if( tmp->left ){
                next_level.push_back( tmp->left );
            }

            if ( tmp->right ){
                next_level.push_back( tmp->right );
            }
        }
        levelOrder( next_level, res);
    }
};
