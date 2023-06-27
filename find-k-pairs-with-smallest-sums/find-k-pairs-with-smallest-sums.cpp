class Solution {
public:

// both array are sorted in ascending order

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        int n = nums1.size();
        int m = nums2.size();

        for(int i = 0; i < n; i++){
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

            while(!pq.empty() && k--){
                auto temp = pq.top().second;
                int x = temp.first;
                int y = temp.second;
                pq.pop();

                ans.push_back({nums1[x], nums2[y]});

                if(y != m-1){        // if y is less then nums2 size we can still go to next index but if it's last index then we can not
                    pq.push({nums1[x] + nums2[y+1], {x, y+1}});
                }
            }
        

        return ans;
    }
};

/*
// it will be of O(n*m) tc but if we remove the =  else{
    break;
}
part then it will give TLE;

vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;



        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                
                if(pq.size()<k) pq.push({sum,{nums1[i],nums2[j]}});

                else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    break;
                }
            }
        }
        while(!pq.empty()){
            
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
*/