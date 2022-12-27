//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here\\
    
    int s=0;
    int e=len-1;
    int maxi=0;
    while(s<=e)
    {
        
        int val=min(A[s],A[e]);
        maxi=max(maxi,val*(e-s));
        if(A[s]>=A[e])
        {
            e--;
        }
        else{
            s++;
        }
        
    }
    return maxi;
    
    
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends