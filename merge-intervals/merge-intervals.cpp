class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {

        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size(); i++){
            if(ans.empty() || arr[i][0] > ans.back()[1]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }

        return ans;
    }
};

/*
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        for(int i = 0; i < n; i++){     // starting with first index after sorting
            int start = intervals[i][0];  
            int end = intervals[i][1];

            if(!ans.empty() && end <= ans.back()[1]){    // if ans vec is not empty and present end is less than the end in ans vector then don't do anything
                continue;
            }

            for(int j = i+1; j < n; j++){    

                if(intervals[j][0] <= end){       // if we are on ith index compare it's end with jth index starting, if starting is less then ending of i then it's overlapping

                    end = max(end, intervals[j][1]);   // update the end if jth index end is greater then ith index end
                }
                else{
                    break;     // end of interval
                }
            }

            ans.push_back({start, end});      // pusht the ovelapping interval
        }

        return ans;
        }

    // tc = O(nlogn) for sorting + O(2n) for going 2 times on intervals element
    // sc = O(n)

    */