class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverseString(a);
        reverseString(b);
        int carry = 0;
        int lena = a.length();
        int lenb = b.length();
        int maxlen = 0;
        if ( lena > lenb ){
            maxlen = lena;
            appendZero( b, lena - lenb );
        } else {
            maxlen = lenb;
            appendZero( a, lenb - lena );
        }
        for( auto i = 0; i < maxlen; ++i ) {
            int tmp = int( a[i] - '0' ) + int( b[i] - '0' ) + carry;
            res += to_string(tmp%2);
            carry = tmp/2;
        }
        if ( carry != 0) {
            res += '1';
        }
        reverseString(res);
        return res;
    }
private:
    void reverseString( string& s ) { 
        reverse(s.begin(), s.end()); 
    }
    void appendZero( string& s, int nums ) { 
        for(auto i = 0; i < nums; ++i) { s += '0'; }
    } 
};
