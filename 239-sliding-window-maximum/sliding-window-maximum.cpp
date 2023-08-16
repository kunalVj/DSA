
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            if(!dq.empty() && dq.front() == i - k ){     // popping out of bound lement
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){        // if a[i] > previous  max element than pop the previous index from dq
                dq.pop_back();
            }

            dq.push_back(i);           

            if(i >= k - 1){                      
                res.push_back(nums[dq.front()]);    
            }
        }
        return res;

    }
};