// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
   string osf;
    
bool isItSafe(int i , int j , int  n , vector<vector<bool>> &visited)
{
	return i>=0 && j >= 0 && i<n && j<n && visited[i][j]==false;
}
    
    string helper(int i , int j , int n , vector<vector<int>> &grid, vector<vector<bool>> &visited){
        
        //base case :
        if(i==n-1 and j==n-1){
            return osf;
        }
        if(!isItSafe(i,j,n,visited )){
            return NULL;
        }
        visited[i][j]=true;
        if(i-1>=0 && grid[i-1][j]==1) //up
	    {
            osf = osf + to_string('U');
		helper(i-1,j,n,grid,visited);
	    }
        if(i+1<n && grid[i+1][j]==1) //down
	    {
            osf = osf + to_string('L');
		helper(i+1,j,n,grid,visited);
	    }
	    if(j-1 >=0 && grid[i][j-1]==1) //left
	    {
            osf = osf + to_string('L');
		helper(i,j-1,n,grid,visited);
	    }
	    if(j+1<n &&grid[i][j+1]==1) //right
	    {
           osf = osf + to_string('R');
		helper(i,j+1,n,grid,visited);
	    }
	    
	    
	    visited[i][j]=false;
	    return NULL;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ss;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        ss.push_back(helper(0,0,n,m,visited));
        //cout<<osf<<endl;
        return ss;
    }
};

    


// { Driver Code Starts.

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
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends