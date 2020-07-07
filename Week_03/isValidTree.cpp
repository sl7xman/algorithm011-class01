class Solution {
private:
    void midall( TreeNode* root, vector<int>& res ){
        //terminator
        if ( root == nullptr ){
            return;
        }

        //drill down
        if ( root->left ){
            midall( root->left, res );
        }
        //process current logic
        res.push_back(root->val);
        //dirll down
        if ( root -> right ) {
            midall( root->right , res);
        }
        
        //restore current status
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        midall( root, res );
        for ( auto i = 1; i < res.size(); ++i ) {
            
            if ( res[i] <= res[i-1]){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack< TreeNode* > s;
        long long inorder = (long long)INT_MIN -1 ;
        while( root || !s.empty() ){//terminator
            while( root ){// drill down
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            if ( inorder >= root->val ){// process current logic
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};
