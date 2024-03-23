#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++) 
#define ll long long int 
#define pb push_back
#define all(x)       x.begin(),x.end()
#define mod 1000000007

void solve(){
int n;cin>>n;
ll dp[n][2];
memset(dp,0,sizeof dp);
dp[0][1]=1;//linked
dp[0][0]=1;//not linked
for(int i=1;i<n;i++){
    dp[i][0]=(4*dp[i-1][0]+dp[i-1][1])%mod;
    dp[i][1]=(2*dp[i-1][1]+dp[i-1][0])%mod;
}
cout<<(dp[n-1][0]+dp[n-1][1])%mod;
cout<<endl;

}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
solve();}
return 0;}