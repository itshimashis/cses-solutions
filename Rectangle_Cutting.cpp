#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++) 
#define ll long long int 
#define pb push_back
#define all(x)       x.begin(),x.end()
#define mod 1000000007
void solved_by_himashis(){
int a,b;cin>>a>>b;
int dp[a+1][b+1];
//memset(dp,0,sizeof dp);
for(int i=0;i<=a;i++){
    for(int j=0;j<=b;j++){
        if(i==j) dp[i][j]=0;
        else{
           // int ans=1e8;
           dp[i][j]=1e8;
            for(int k=1;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
            for(int k=1;k<=i-1;k++){
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
           // dp[i][j]=ans;
        }
    }
}
cout<<dp[a][b];
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   // int t;cin>>t;
  //  while(t--){
solved_by_himashis();
return 0;}