#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++) 
#define ll long long int 
#define pb push_back
#define all(x)       x.begin(),x.end()
#define mod 1000000007
void solved_by_himashis(){
int n;cin>>n;
vector<int>v(n);
ll sum=0;
forn(i,n) {cin>>v[i];sum+=v[i];}
ll dp[n][n];
memset(dp,0,sizeof dp);
for(int i=0;i<n;i++){
    dp[i][i]=v[i];
}
for(int i=n-1;i>=0;--i){
    for(int j=i;j<n;j++){
        if(i==j){
            dp[i][j]=v[i];
        }
        else{
            dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
    }
}
cout<<(dp[0][n-1]+sum)/2;

}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   // int t;cin>>t;
  //  while(t--){
solved_by_himashis();
return 0;}