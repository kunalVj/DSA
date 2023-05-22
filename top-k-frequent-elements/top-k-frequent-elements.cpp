class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;   // Min heap as question is asking for 'top' K Frequent Elements
        vector<int> ans;

        unordered_map<int,int> hash;   // store the values and their frequency in the map 
        for(auto num : nums){
            hash[num]++;
        }
        
        for(auto i = hash.begin(); i != hash.end(); i++){   // push the map elements in the priority queue
            q.push({i -> second, i -> first}); // while pushing in the pair of key and frequency from map, push them in {frquency, key} form as we need to sort the queue on the basis of frequency

            if(q.size() > k){  // if the q size is greater than k pop the top element because the element with the highest frequency will be within k size 
                q.pop();
            }
        }

        while(!q.empty()){
            ans.push_back(q.top().second);  // the remaining elements in the queue are answers so push them in vector ans, also push the key only i.e second don't push the frquency 
            q.pop();
        }

        return ans;
        
    }
};