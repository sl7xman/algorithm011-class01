class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //terminator
        if( root == nullptr ){
            return root;
        }

        if ( root->left ){
            //drill down
            invertTree( root->left );
        }
        if ( root->right ) {
            //drill down
            invertTree( root->right );
        }
        //process current logic

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        //restore current status
        return root;
    }
};
