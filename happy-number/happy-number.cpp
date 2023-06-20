class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> s;

        while(n != 1){
            int sum = 0;
             int current = n;

             while(current){
                 int digit = current%10;
                 sum += (digit * digit);
                 current = current/10;
             }

             if(s.find(sum) != s.end()){
                 return false;
             }

             s[sum]++;
            n = sum;
        }

        return true;
    }
};