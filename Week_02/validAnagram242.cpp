class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() ){
            return false;
        }
        int c[26] = {0};
        for ( auto sit = s.begin(); sit != s.end(); ++sit ) {
            int idx = (*sit -'a');
            c[idx]++;
        }
        for ( auto tit = t.begin(); tit != t.end(); ++tit ) {
            int idx = (*tit - 'a');
            if(c[idx] <=0 ) {
                return false;
            }
            --c[idx];
        }   
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() ) {
            return false;
        }

        map<char,int> m;
        for ( auto sit = s.begin(); sit != s.end(); ++sit ) {
            auto it = m.find(*sit);
            if ( it == m.end() ) {
                m.insert({*sit,1});
            } else {
                it->second++;
            }
        }

        for ( auto tit = t.begin(); tit != t.end(); ++tit ) {
            auto it = m.find(*tit);
            if ( it == m.end() ) {
                return false;
            }else {
                if ( it->second == 1 ){
                    m.erase(it);
                }else{
                    it->second--;
                }
            }
        }

        return true;
    }
};
