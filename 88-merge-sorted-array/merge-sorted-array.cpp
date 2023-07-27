class Solution {
public:

// we will use rverse sorting. We will keep checking for the greater element of the two arrays(i=m-1,j=n-1) and insert the values.
// We initialize k=m+n-1 as that will be the last location of nums1.


    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;
        int j = n-1;
        int k = m + n - 1;

        while( i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[k] = nums1[i];              // 'nums1[k]' as per question final sorted array should not be returned by func., but instead be stored inside the array nums1.
                i--;
                k--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
     /*   while(i >= 0){                         (not including this, look below for explanation)
            nums1[k] = nums1[i];
            i--;
            k--; 
        } */

        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }

      

    }
};
// for while(i >= 0)
/* Generally in merging sorted arrays there is a loop condition of (i>=0) but In this question , we wont need it as both the arrays are sorted and we are checking from the last of both the arrays and if at any test case j pointer reaches 0 before i , it will mean that the elements left before i are placed accordingly . will be more clear with an example

Example - 1 - where j terminates before i
nums1 = [1,2,0,0,0] ; nums2 = [3,4,5] ; m = 2 , n = 3
in this case j will reach zero when i will still be at 1st index , and the resultant array will be [1,2,3,4,5] -> this only implicates that the elements in nums2 were greater than nums1 so we dont need to iterate i till 0 

Example -2 - where i terminates before j
*nums1 = [4,5,6,7,0,0,0] ; nums1 = [1,4,5] ; m = 4 ; n = 3
in this case i will reach zero where as j will still be at 0th position of nums2 implicating that all the elements in nums1 are merged except one in nums2  */




