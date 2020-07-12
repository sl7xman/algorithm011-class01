class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int money_5 = 0;
        int money_10 = 0;
        int siz = bills.size();

        for ( auto i = 0; i < siz ; ++i) {
            switch( bills[i] ){
                case 5:
                    ++money_5;
                break;
                case 10:
                    ++money_10;
                    --money_5;
                break;
                default: //20
                    if (money_10 > 0){
                        --money_10;
                        --money_5;
                    }else{
                        money_5 -= 3;
                    }
                break;
            }
            if ( money_5 < 0 ){
                return false;
            }
        }
        return true;
    }
};
