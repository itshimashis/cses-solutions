#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++) 
#define  mp make_pair
#define ll long long int 
#define um unordered_map 
#define m map
#define pb push_back
#define all(x)       x.begin(),x.end()
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
void printvec(vector<int>&v){
    forn(i,v.size()){
        cout<<v[i]<<" ";
    }
}
const int M=1e9+7;
long long int f(vector<vector<int>>&grid,vector<vector<int>>&dp,int row,int col,int n){
   if(row>=n || col>=n || row<0 || col<0) return 0;
   if(row==n-1 && col==n-1) return 1;
   if(grid[row][col]==-1) return 0;
   if(dp[row][col]!=-1) return dp[row][col];
   int down=0;int right=0;
   if(row+1<n) down=f(grid,dp,row+1,col,n);
   if(col+1<n) right=f(grid,dp,row,col+1,n);
   return dp[row][col]=(down+right)%M;
}
void solve(){
int n;cin>>n;
vector<vector<int>>grid(n+1,vector<int>(n+1,0));
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      char x;cin>>x;
      if(x=='*') grid[i][j]=-1;
    }
}
vector<vector<int>>dp(n+1,vector<int>(n+1,0));
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(grid[i][j]==-1) dp[i][j]=0;
        else if(i==1 && j==1) dp[i][j]=1; //because in case of of it being a star marked grid this would have been zero
        else{
            
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
        }

    }
}
cout<<dp[n][n];

}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
solve();
return 0;}