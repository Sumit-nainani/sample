/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int func(int i,vector<vector<int>>&v,int n,int m,vector<vector<int>>&dp,int j){
    
    if(i==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=0;k<2;k++){
        if(j==k) continue;
        ans = min(ans,v[i][j]+func(i+1,v,n,m,dp,k));
    }
    return dp[i][j]=ans;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m)),dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>v[i][j];
    cout<<min({func(0,v,n,m,dp,0),func(0,v,n,m,dp,1),func(0,v,n,m,dp,2)});
    

    return 0;
}
