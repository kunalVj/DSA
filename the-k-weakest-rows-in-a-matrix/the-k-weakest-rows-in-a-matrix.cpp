class Solution {
private:
    int bsearch(vector<int>& v){
        int left = 0, right=v.size()-1, mid;
        while(left<=right){
            mid = left + (right - left)/2;
            
            if(v[mid]==1){
                left = mid + 1;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        priority_queue<pair<int,int>> pq;
        int count = 0;
        
        for(int i=0; i<n; ++i){
            count = bsearch(mat[i]);
            pq.push({count, i});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*
TIME COMPLEXITY
Considering no. of rows=m,
At each iteration, for binary search O(logn) and maximum heap size =k, so for inserting into max_heap O(logk)
O(m(logn+logk))

SPACE COMPLEXITY
Since maximum heap size is k.
O(2*k) [ For pair of heap ]
*/