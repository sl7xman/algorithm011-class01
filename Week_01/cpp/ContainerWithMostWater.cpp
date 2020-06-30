class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int max_area = 0;

        while( left < right ) {
            int cur_left_high = height[left];
            int cur_right_high = height[right];

            int cur_area = min( cur_left_high, cur_right_high ) * ( right - left );
            max_area = max( cur_area, max_area );
            
            if( cur_left_high < cur_right_high ) {
                while( (++left < right) && (cur_left_high > height[left] ) );
            } else {
                while ( ( --right > left ) && ( cur_right_high > height[right] ) );
            }
        }
        return max_area;
    }
};
