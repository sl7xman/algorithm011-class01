class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int snum = s.size();
        int gnum = g.size();
        sort( g.begin(), g.end());
        sort( s.begin(), s.end());

        int ans = 0;
        int cur_child = 0;
        for ( auto i = 0; i < snum && gnum > cur_child; ++i ) {
            if ( s[i] >= g[cur_child] ){
                ++ans;
                ++cur_child;
            }
        }
        return ans;
    }
};
