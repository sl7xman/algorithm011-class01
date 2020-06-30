func maxArea(height []int) int {
    var l, r = 0, len(height)-1
    max_waters := 0

    for l < r {
        var l_val, r_val = height[l], height[r]
        min_val := 0
        if l_val > r_val {
            min_val = r_val
        }else {
            min_val = l_val
        }

        cur_waters := min_val * ( r - l )
        if max_waters < cur_waters {
            max_waters = cur_waters
        }

        if l_val < r_val {
            l++
        } else {
            r--
        }
    }
    return max_waters
}
