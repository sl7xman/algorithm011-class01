class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool access = false;
        int siz = nums.size();
        int min_step = 0;
        for ( int i = siz -1; i >=0 ; --i){
            if ( nums[i] < min_step){
                ++min_step;
                access = false;
            }else{
                min_step=1;
                access = true;
            }
        }
        return access;
    }
};
