class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int nsiz = nums.size();
        return getcurlevel( nums, nsiz );
    }
private:
    vector<vector<int>> getcurlevel( vector<int>& child_nums, int nsiz) {
        vector<vector<int>> child_res;

        //terminator
        if( nsiz == 1 ){
            child_res.push_back( { child_nums[0] } );
            return std::move ( child_res );
        }

        //process current logic
        for ( auto i = nsiz -1 ; i >=0 ; --i ){
            //drill down
            vector<vector<int>> cur_res =  getcurlevel( child_nums, i );
            int append_val = child_nums[i];
            for ( auto cit = cur_res.begin(); cit != cur_res.end(); ++cit ){
                vector<int> c_v = *cit;
                c_v.push_back(append_val);
                int csiz = c_v.size();
                for ( auto j = 0; j < csiz; ++j ){
                    c_v[csiz -1] = c_v[j];
                    c_v[j] = append_val;

                    child_res.push_back(c_v);
                    c_v[j] = c_v[csiz -1];
                    c_v[csiz-1] = append_val;                    
                }
            }
        }

        //restore current status
        return std::move(child_res);
    }
};
