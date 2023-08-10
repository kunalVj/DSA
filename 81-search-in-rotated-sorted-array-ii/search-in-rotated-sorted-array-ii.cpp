class Solution {
public:
       // the idea is same as the problem "search in rotated array" but we have a extra condition i.e. of duplicates
       // in this num[start] == nums[mid] && nums[end] == nums[mid] can be possible for this we have to add an extra if condition in which nums[start] == nums[mid] == nums[end] can be checked before the original logic, if so then move start and end both towards the middle by 1 and repeat.
    
    bool search(vector<int>& nums, int target) {
     
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[start] == nums[mid] && nums[end] == nums[mid]){   // this the case of duplicate
                start++;
                end--;
            }
            else if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[end]){
                    start = mid + 1;
                }
                else{
                    end  = mid - 1;
                }
            }
            
        }

        
        return false;
        
    }
};

/*
 (or we can sort it : sort(nums.begin(), nums.end());)
 
for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;

*/