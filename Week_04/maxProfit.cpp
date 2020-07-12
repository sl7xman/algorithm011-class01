class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int siz = prices.size();
        int total = 0;
        for ( auto i = 1; i < siz; ++i ) {
            int tmp = prices[i] - prices[i-1];
            if ( tmp > 0 ){
                total += tmp;
            }
        }
        return total;
    }
};
