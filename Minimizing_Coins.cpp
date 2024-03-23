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
int ans(vector<ll>&coins,int money,int ind,vector<vector<int>>&dp){
  if(ind==0){
    if(money%coins[ind]==0) return money/coins[ind];
    else return 1e9;
  }
  if(dp[ind][money]!=-1) return dp[ind][money];
  int take=1e9;
  if(money-coins[ind]>=0){
     take=1+ans(coins,money-coins[ind],ind,dp);
  }
  int notake=ans(coins,money,ind-1,dp);
  return dp[ind][money]=min(take,notake);

}
void solve(){
int n,x;cin>>n>>x;
vector<int>coins(n,0);
forn(i,n) cin>>coins[i];
int dp[n][x+1]={0};
for(int money=x;money>=0;--money){
  if(money%coins[0]==0){
  dp[0][money]=money/coins[0];}
  else dp[0][money]=1e9;
}
for(int ind=1;ind<n;ind++){
  for(int money=0;money<=x;money++){
     int take=1e9;
  if(money-coins[ind]>=0){
     take=1+dp[ind][money-coins[ind]];
  }
  int notake=dp[ind-1][money];
   dp[ind][money]=min(take,notake);
  }
}
if(dp[n-1][x]==1e9) cout<<-1<<endl;
else cout<<dp[n-1][x];
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
solve();
 
 
return 0;}