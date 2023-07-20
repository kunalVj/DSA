class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;
        
        for(int i = 0; i < n; i++){
            if(stk.empty() || asteroids[i] > 0){
                stk.push(asteroids[i]);
            }else{
                while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i])){
                    stk.pop();
                }

                if(!stk.empty() && stk.top() == abs(asteroids[i])){
                    stk.pop();
                }else{
                    if(stk.empty() || stk.top() < 0){
                        stk.push(asteroids[i]);
                    }
                } 
            }
        }
        vector<int> ans(stk.size(), 0);
        int size = stk.size();
        while(!stk.empty()){
            ans[--size] = stk.top();
            stk.pop();
        }
        return ans;
    }
};


/*class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        
        for(int i = 0; i < asteroids.size(); i++){
            if(!s.empty() || asteroids[i] > 0){
                s.push(asteroids[i]);
            }

            else{
                while(!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])){
                    s.pop();
                }

                if(!s.empty() && s.top() == abs(asteroids[i])){
                    s.pop();
                }
                else{
                    if(s.empty() || s.top() < 0){
                        s.push(asteroids[i]);
                    }
                }
            }
        }

        vector<int> ans(s.size(), 0);

        int size = s.size();
        while(!s.empty()){
            ans[--size] = s.top();
            s.pop();

        }
        return ans;
        
    }
};*/