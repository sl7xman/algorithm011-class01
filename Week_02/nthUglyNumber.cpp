class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0;
        int b = 0;
        int c = 0;
        int dp[ n ] ;
        dp[0] = 1;
        for ( auto i = 1; i < n; ++i ) {
            int xa = dp[a] * 2;
            int xb = dp[b] * 3;
            int xc = dp[c] * 5;
            dp[ i ] = min3( xa, xb, xc );

            if ( dp[ i ] == xa ) {
                ++a;
            } 
            if( dp[ i ] == xb ) {
                ++b;
            } 
            if ( dp[ i ] == xc) {
                ++c;
            }
        }
        return dp[ n-1 ];
    }

private:
    int min3( int x1, int x2, int x3  ) {
        int res;

        res = x1 > x2 ? x2 : x1;
        res = res > x3 ? x3 : res;

        return res;
    }
};
