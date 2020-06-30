class Solution {
private:
    void levelOrder_loop( vector<Node*>& layer, vector<vector<int>>& res ) {
        if( layer.size() == 0 ){
            return;
        }

        vector<int> layer_res;
        vector<Node*> layer_child;
        for ( auto cit = layer.begin(); cit != layer.end(); ++cit ) {
            Node* tmp_node = *cit;
            layer_res.push_back( tmp_node->val);
            for( auto clit = tmp_node->children.begin(); clit != tmp_node->children.end(); ++clit ) {
                layer_child.push_back(*clit);
            }
        }
        res.push_back(layer_res);
        levelOrder_loop(layer_child, res);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if( root == nullptr ) {
            return ans;
        }
        vector<Node*> layer;
        layer.push_back(root);
        levelOrder_loop(layer, ans);
        return std::move(ans);
    }
};
