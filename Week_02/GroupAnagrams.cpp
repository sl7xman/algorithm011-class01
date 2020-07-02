class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> same_str;

        for ( auto it : strs ) {
            string tmp = it;
            sort(tmp.begin(), tmp.end());
            same_str[tmp].push_back(it);
        }

        vector<vector<string>> ans;
        for ( auto it : same_str ) {
            ans.push_back(it.second);
        }
        return std::move(ans);
    }
};
