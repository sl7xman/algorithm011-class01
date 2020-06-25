class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if ( size == 0 ) {
            return digits;
        }
        
        for ( auto i = size-1; i >= 0; --i ) {
            int val_sum = ++digits[i] ;
            digits[i] = val_sum%10;
            if( digits[i] != 0 ) {
                return std::move(digits);
            }
        }

        if ( digits[0] == 0 ) {
            digits.push_back( 0 );
            for ( auto i = size; i > 0; --i ) {
                digits[i] = digits[i-1];
            }
            digits[0] = 1;
        }

        return std::move(digits);    
    }
};
