func moveZeroes(nums []int)  {
    first_zero_index := 0

    for i := 0; i < len(nums); i++ {
        if nums[i] != 0 {
            nums[ first_zero_index ] = nums[i]
            first_zero_index++
        }
    }

    for i := first_zero_index; i < len(nums); i++ {
        nums[i] = 0
    }
}
