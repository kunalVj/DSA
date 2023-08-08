class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0 ;
        int end = nums.size() - 1;
        int mid;

        /*The idea is that we can always divide the array into two parts L, R. If L is sorted and the key is in the range we can simply throw R away, if key is not in the range then we know the key must be in the unsorted part(i.e. R). If key is in R, we are back to the same problem with the size halved, so we can apply the same idea on R.*/

        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[start] <= nums[mid]){   // when left part is sorted 
                if(nums[start] <= target && target <= nums[mid]){   // target in the left part (target in the range of start and mid)
                    end = mid - 1;
                }
                else{                  // target in the right part
                    start = mid + 1;
                }
            }
                else{
                    if(nums[mid] <= target && target <= nums[end] ){  //target in the right part(target in the range of mid and end)
                        start = mid + 1;
                    }
                    else{                      // target in the left part
                        end = mid - 1;
                    }
                }
            
        }
        return -1;
        
    }
};