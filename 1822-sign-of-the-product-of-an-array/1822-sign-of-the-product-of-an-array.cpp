class Solution {
public:
   int arraySign(vector<int>& nums) {
        int product=1;
        for (int x:nums) {
            if (x<0) product*=-1;
            else if (x>0) product*=1;
            else return 0;
        }
        return product;
    }
};



