void moveZeroes(int* nums, int numsSize){
    
    int first_zero_index = -1; 
    int i =0; 
    
    for ( i = 0; i < numsSize ; i++ ) { 
        if ( nums[i] == 0) {
            if ( first_zero_index == -1 ) { 
                first_zero_index = i;    
            }
        } else {
            if ( first_zero_index != -1 ) { 
                nums[first_zero_index++] = nums[i];    
            }    
        }    
    }   
    if ( first_zero_index != -1 ) { 
        for ( i = first_zero_index ; i < numsSize ; i++ ) { 
            nums[i] = 0;    
        }    
    }   

}
