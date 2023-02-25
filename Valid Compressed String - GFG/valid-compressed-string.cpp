//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        
        int n=S.size();
        int m=T.size();
        
        int i=0;
        int j=0;
        
        while(i<n && j<m)
        {
            if(S[i]==T[j])
            {
                i++;
                j++;
            }
            else if(T[j]>='0' && T[j]<='9')
            {
                string str;
                while(T[j]>='0' && T[j]<='9')
                {
                  str+=T[j];
                  j++;
                }
                int num=stoi(str);
                while(num--)
                {
                    i++;
                }
                
            }
            else
            return 0;
            
        }
        
        
        if(i==n && j==m) return 1;
        else 
          return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends