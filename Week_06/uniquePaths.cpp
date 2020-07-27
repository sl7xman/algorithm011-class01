class Solution {
public:
    int uniquePaths(int m, int n) {
        if( m <= 0 || n <= 0 ) {
            return 0;
        }
        if( m == 1 || n == 1 ){
            return 1;
        }

        if( tmp[m][n] > 0 ) {
            return tmp[m][n];
        }

        tmp[m-1][n]= uniquePaths( m - 1, n);
        tmp[m][n-1]= uniquePaths( m, n - 1 );
        tmp[m][n] = tmp[m-1][n] + tmp[m][n-1];
        return tmp[m][n];
    }

private:
    int tmp[101][101] ={0};
};
