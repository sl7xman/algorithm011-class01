int trap(int* height, int heightSize){
    int ans = 0;
    int i = 0;
    int max_right_idx = 0;
    int min_left_right = 0;
    int max_left = 0;
    int max_right = 0;
    for ( i = 0; i < heightSize; ++i ) {
        int j = 0;
        int mheight = height[i];
        if ( max_left < mheight ) {
            max_left = mheight;
        }
    
        if ( i >= max_right_idx ) {
            max_right = 0;
            for ( j = i; j < heightSize; ++j ) {
                int mheight = height[j];
                if ( max_right < mheight ) {
                    max_right = mheight;
                    max_right_idx = j;
                }
            }
        }
        min_left_right = max_right > max_left ? max_left : max_right;
        if( min_left_right >= height[i] ) {
            ans += min_left_right - height[i];
        }
    }
    return ans;
}


