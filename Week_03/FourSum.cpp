class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int length = nums.size();
        if ( length < 4 ) {
            return ans;
        }
        sort( nums.begin(), nums.end() );
        for ( int k = 0; k < length - 3; ++k ) {
            if ( k > 0 && nums[k] == nums[k-1]){ continue; }
            int min1 = nums[k] + nums[k+1] + nums[k+2] + nums[k+3];
            if ( min1 > target ) { break; }
            int max1 = nums[k] + nums[length-1] + nums[length-2] + nums[length-3];
            if ( max1 < target ) { continue; }
            for ( auto i = k+1; i < length - 2; i++ ){
                if ( i > k+1 && nums[i] == nums[i-1]) { continue; }
                int j = i+1;
                int h = length -1;
                int min2 = nums[k] + nums[i] + nums[j] + nums[j+1];
                if ( min2 > target ){ break; }
                int max2 = nums[k] + nums[i] + nums[h] + nums[h-1];
                if ( max2 < target ) { continue; }
                while( j<h ) {
                    int curr = nums[k] + nums[i] + nums[j] + nums[h];
                    if ( curr == target ) {
                        ans.push_back( vector<int>{nums[k], nums[i], nums[j], nums[h]} );
                        ++j;
                        while( j<h && nums[j] == nums[j-1]){ ++j; }
                        --h;
                        while( j<h && i<h && nums[h] == nums[h+1] ){ --h; }
                    }else if( curr > target ){ --h;
                    }else { ++j; }
                }
            }
        }
        return std::move( ans );
    }
};
