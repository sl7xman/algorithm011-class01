func merge(nums1 []int, m int, nums2 []int, n int)  {

    for k := m + n -1; k >= 0; k-- {
        if n -1 < 0 || ( m-1 >= 0 && nums1[ m-1 ] > nums2[ n-1 ]) {
            nums1[ k ] = nums1[ m-1 ]
            m--
        }else {
            nums1[ k ] = nums2[ n-1 ]
            n--
        }
    }
}

