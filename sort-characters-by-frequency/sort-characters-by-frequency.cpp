class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++){ // store the frequency of letters
            mp[s[i]]++;
        } 

        priority_queue<pair<int, char>> pq; // max heap to sort them in decreasing order, we sort based on frequency

        for(auto it : mp){
            pq.push({it.second, it.first});  // store the in pair with frequency at first and char at second
        }

        string str = "";

        while(!pq.empty()){

            pair<int, char> curr = pq.top(); // top element will be the max char so we put it in starting
            pq.pop();

            while(curr.first--){   // exhaust the frequency of poped char and keep storing in ans string
                str += curr.second;
            }
        }

        return str;
    }
};