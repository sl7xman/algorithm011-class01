class Solution {
public:
    int climbStairs(int n) {

        int midval[n+1];
        midval[0] = 1;
        midval[1] = 1;

        for ( int i = 2; i <= n; i++ ){
            midval[i] = midval[i-1] + midval[i-2];
        }

        return midval[n];
    }
};
