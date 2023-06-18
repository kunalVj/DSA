class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++){    // calculate the total sum.
            sum += i;
        }

/* 
Run a for loop n times again but this time, reduce the sum and check if (temp==sum), if not add it to temp.
Ex. n=8: 1,2,3,4,5,6,7,8: Sum = 36, temp = 0
*/
        int temp = 0;

        for(int i = 0; i <= n; i++){
            sum -= i;
            if(temp == sum){
                return i;
            }
            temp += i;
        }

        return -1;
    }
};