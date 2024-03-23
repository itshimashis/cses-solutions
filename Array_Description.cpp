#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++) 
#define ll long long int 
#define pb push_back
#define all(x)       x.begin(),x.end()
#define mod 1000000007

 
void solve(){
int n,m;cin>>n>>m;
vector<int>v(n);
forn(i,n) cin>>v[i];
vector<vector<int>>dp(n,vector<int>(m+1,0));
if(v[0]==0){
    fill(all(dp[0]),1);
}
else dp[0][v[0]]=1;
for(int i=1;i<n;i++){
    if(v[i]==0){
        for(int j=1;j<=m;j++){
            for(int k:{j,j-1,j+1}){
                if(k>=1 && k<=m){
                     (dp[i][j]+=dp[i-1][k])%=mod;
                }
            }
        }
    }
    else{
        for(int k:{v[i],v[i]-1,v[i]+1}){
            if(k>=1 && k<=m){

                (dp[i][v[i]]+=dp[i-1][k])%=mod;
            }
        }
    }
}
long long ans=0;
for(int i=1;i<=m;i++){
   ( ans+=dp[n-1][i])%=mod;
}
cout<<ans<<endl;
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
solve();
return 0;}