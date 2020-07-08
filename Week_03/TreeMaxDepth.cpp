class Solution {
public:

    int maxDepth(TreeNode* root) {
        if ( root == nullptr ){
            return 0;
        }
        int ans = 0;
        vector< TreeNode* > cur_level ;
        cur_level.push_back(root);
        levelOrder( cur_level, ans );
        return ++ans;
    }

    void levelOrder(vector<TreeNode*>& cur_level, int& res ){
        vector<TreeNode*> next_level;
        for ( auto it = cur_level.begin(); it != cur_level.end(); ++it ) {
            TreeNode* tmp = *it;
            if( tmp->left ){
                next_level.push_back(tmp->left);
            }
            if( tmp->right ){
                next_level.push_back(tmp->right);
            }
        }
        if ( next_level.size() ){
            ++res;
            levelOrder( next_level, res);
        }
    }
};
