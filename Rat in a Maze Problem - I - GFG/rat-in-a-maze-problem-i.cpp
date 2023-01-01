//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    void helper(int i, int j, vector<vector<int>> &arr, int n, vector<vector<int>> &vis, vector<string> &result, string path, int di[], int dj[]){
        if(i== n-1 && j== n-1){
            result.push_back(path);
            return;
        }
        string move= "DLRU";
        for(int index=0; index<4; index++){
            int new_i = i+di[index];
            int new_j = j+dj[index];
            if(new_i >=0 && new_j >=0 && new_i < n && new_j < n && !vis[new_i][new_j] && arr[new_i][new_j]==1){
                vis[i][j]=1;
                helper(new_i, new_j, arr, n, vis, result, path + move[index], di, dj);
                vis[i][j]=0;
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        vector<vector<int>> vis(n, vector<int>(n,0));
        int di[]={+1, 0, 0, -1};
        int dj[]={0, -1, +1, 0};
        if(m[0][0]==1) helper(0,0, m, n, vis, result, "", di, dj);
        return result;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends