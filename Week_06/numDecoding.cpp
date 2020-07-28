class Solution {
public:
    int numDecodings(string s) {
        if ( s[0] == '0' ){
            return 0;
        }

        int curr = 1;
        int prev = 1;

        for ( auto i = 1; i < s.size(); ++i ) {
            int tmp = curr;
            if ( s[i] == '0' ){
                if (s[i-1]=='1' || s[i-1] == '2') {
                    curr = prev;
                }else{
                    return 0;
                }
            }else if( s[i-1] == '1' || ( s[i-1] == '2' &&  s[i] >= '1' && (s[i] <='6')) ){
                curr += prev;
            }
            prev = tmp;
        }
        
        return curr;
    }
};
