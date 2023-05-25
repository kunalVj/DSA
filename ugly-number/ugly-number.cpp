class Solution {
public:
int helper(int dividend, int divisor){
    while(dividend % divisor == 0){
        dividend = dividend / divisor;
    }

    return dividend;

}
    bool isUgly(int n) {
        if(n <= 0){
            return false;
        }
       
       for(auto factor : {2, 3, 5}){
           n = helper(n, factor);
       }

       if(n == 1){
           return true;
       }

       return false;

    }
};