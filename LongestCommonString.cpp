// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int arr[n+1][m+1];
        for(int i = 0 ; i < n+1 ; i ++){
            for(int j=0;j<m+1;j++){
                arr[i][j] = 0 ;
            }
        }
        int result = 0 ;
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(S1[i] == S2[j]){
                    arr[i+1][j+1] = arr[i][j]+1;
                    result = max(result , arr[i+1][j+1]);
                    //cout<<"arr : "<<arr[i+1][j+1]<<endl;
                    //cout<<S1[i]<<" "<<S2[j]<<" "<<endl;
                }
                else
                    arr[i+1][j+1] = 0; //max(arr[i-1+1][j+1],arr[i+1][j-1+1]);
                
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends