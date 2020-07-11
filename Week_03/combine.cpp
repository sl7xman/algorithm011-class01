class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> valid_ans;
        bactrack( ans, valid_ans, n, k, 1);
        return  ans;
    }
private:

    void bactrack(vector<vector<int>>& ans, vector<int>& valid_ans, int& n, int& k, int idx) {
        if ( valid_ans.size() == k ){
            ans.push_back( valid_ans );
        }else{
            for ( int i = idx; i <= n; ++i ) {
                valid_ans.push_back(i);
                bactrack(ans, valid_ans,n,k, i+1);
                valid_ans.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> valid_ans;
        bactrack( ans, valid_ans, n, k, 0, -1);
        return  ans;
    }
private:

    void bactrack(vector<vector<int>>& ans, vector<int>& valid_ans, int& n, int& k, int idx, int pre) {
        if ( idx == k ){
            ans.push_back( valid_ans );
        }else{
            if( (idx + n - pre) <= k ){
                return;
            }
            for ( int i = pre + 1; i < n; ++i ) {
                valid_ans.push_back(i+1);
                pre = i;
                bactrack(ans, valid_ans,n,k, idx+1, pre);
                valid_ans.pop_back();
            }
        }
    }
};
