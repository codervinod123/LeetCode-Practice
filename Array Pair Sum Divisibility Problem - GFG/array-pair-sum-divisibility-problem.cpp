//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        unordered_map<int,int> mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
           int val=nums[i]%k;
           int remain=(k-val)%k;
           if(mp.find(remain)!=mp.end())
           {
               mp[remain]--;
               if(mp[remain]==0)
               {
                   mp.erase(remain);
               }
           }
           else
           {
               mp[val]++;
           }
        }
        
        if(mp.size()!=0) return false;
        return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends