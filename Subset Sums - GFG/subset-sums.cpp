//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void helper(int index, int sum, vector<int> &arr, int N, vector<int> &Result){
    if (index == N){
        Result.push_back(sum);
        return;
    }
    
    //pick
    helper(index + 1, sum + arr[index], arr, N, Result);
    
    //Not pick
    helper(index + 1, sum, arr, N, Result);
}

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> Result;
        helper(0, 0, arr, N, Result);
        return Result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends