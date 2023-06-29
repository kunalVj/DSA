class Solution {
public:
void reverse(vector<int> &nums, int start, int end){
    int temp;
    while(start < end){
        
        // swap first and last index
        
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        start++;
        end--;
    }
}
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k%n;  // if k is greater than size then making it in the range of size

        if(k == 0 || n == 1){
            return;
        }

        reverse(nums, 0, n-1);    // reversing the whole array
        reverse(nums, 0, k-1);    //reversing first half of array
        reverse(nums, k, n-1);    // reversing the second half
    }
};