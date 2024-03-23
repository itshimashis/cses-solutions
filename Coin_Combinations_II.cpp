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
ll f(int ind,int money,vector<int>&coins,vector<vector<int>>&dp){
    if(ind==0){
        if(money%coins[ind]==0) return 1;
        else return 0;
    }
    if(dp[ind][money]!=-1) return dp[ind][money];
    int take=0;
    if(coins[ind]<=money) take=f(ind,money-coins[ind],coins,dp);
    int notake=f(ind-1,money,coins,dp);
    return dp[ind][money]=(take+notake)%M;
}

void solve(){
int n,x;cin>>n>>x;
vector<int>coins(n,0);
forn(i,n) cin>>coins[i];
vector<vector<int>>dp(n,vector<int>(x+1,0));
//vector<int>dp(x+1,-1);
//cout<<f(x,coins,dp);
//cout<<f(n-1,x,coins,dp);
for(int i=0;i<=x;i++){
    if(i%coins[0]==0){
    dp[0][i]=1;}
    else dp[0][i]=0;
}
for(int ind=1;ind<n;ind++){
    for(int money=0;money<=x;money++){
        int take=0;
    if(coins[ind]<=money) take=dp[ind][money-coins[ind]];
    int notake=dp[ind-1][money];
     dp[ind][money]=(take+notake)%M;
    }
}
cout<<dp[n-1][x];



}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
solve();
 
 
return 0;}