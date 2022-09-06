class Solution {
public:
    bool isPalindrome(int x) {
       long int result=0;
        int temp=x;
        if(x<0){
            return false;
        }
        while(temp !=0){
         long int lastdigit= temp%10;
            result=result*10+lastdigit;
            temp=temp/10;
        }
        if(x==result){
            return true;
        }
        else
            return false;
        
    }
};