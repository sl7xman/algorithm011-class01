class Solution {
private:
    void preorder_loop( Node* root, vector<int>& res ) {
        res.push_back(root->val);
        for ( auto cit = root->children.begin(); cit != root->children.end(); ++cit ) {
            preorder_loop( *cit, res);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if ( root == nullptr ){
            return ans;
        }
        preorder_loop( root, ans );
        return std::move(ans);
    }
};
