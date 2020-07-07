class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> first_val;
        unordered_map<int, int> second_val;

        int counts = nums.size();

        for ( auto i = 0; i < counts; ++i ) {
            int ftmp = nums[i];
            int stmp = target - ftmp;
            first_val[ ftmp ] = i;
            second_val[ ftmp ] = stmp;
        }

        vector<int> res;

        for ( auto i = 0; i< counts; ++i ) {
            int ftmp = nums[i];
            int stmp = second_val[ ftmp ];
            auto it = first_val.find( stmp );
            if ( it != first_val.end() && it->second != i ){
                res.push_back( i );
                res.push_back( it->second );
                break;
            }
        }
        return res;
    }
};
