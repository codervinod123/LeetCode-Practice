//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    
    bool isSafe(vector<vector<bool>> &safety,int row,int col,int n,vector<vector<int>> &m)
    {
        if((row>=0 && row<n) && (col>=0 && col<n) && (safety[row][col]!=1) && (m[row][col]==1))
            return true;
        else
            return false;
    }
    
    void solve(vector<string> &ans,vector<vector<bool>> &safety,int row,int col,int n,string dummy,vector<vector<int>> &m)
    {
       if(row==n-1 && col==n-1)
       {
           ans.push_back(dummy);
           return; 
       }
       
       
       safety[row][col]=1;
       
       
       
       int newRow=row+1;
       int newCol=col;
       
       
       if(isSafe(safety,newRow,newCol,n,m))
       {
           solve(ans,safety,newRow,newCol,n,dummy+'D',m);
       }
       
       newRow=row-1;
       newCol=col;
       
       if(isSafe(safety,newRow,newCol,n,m))
       {
           solve(ans,safety,newRow,newCol,n,dummy+'U',m);
       }
       
       
       newRow=row;
       newCol=col+1;
       
       if(isSafe(safety,newRow,newCol,n,m))
       {
           solve(ans,safety,newRow,newCol,n,dummy+'R',m);
       }
       
       
       newRow=row;
       newCol=col-1;
       
       if(isSafe(safety,newRow,newCol,n,m))
       {
           solve(ans,safety,newRow,newCol,n,dummy+'L',m);
       }
       
       
       
       safety[row][col]=0;
       
       
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        if(m[0][0]==0) return ans;
        
        string dummy="";
        vector<vector<bool>> safety(n,vector<bool>(n,0));
        solve(ans,safety,0,0,n,dummy,m);
        return ans;
        
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