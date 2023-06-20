class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        while(n != 1){
            int sum = 0;
             int current = n;

             while(current){
                 int digit = current%10;
                 sum += (digit * digit);
                 current = current/10;
             }

             if(s.count(sum)){
                 return false;
             }

             s.insert(sum);

             n = sum;
             
        }

        return true;
    }
};