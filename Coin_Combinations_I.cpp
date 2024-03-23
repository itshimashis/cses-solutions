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
long long f(int money,vector<int>&coins,vector<int>&dp){
    if(money==0) return 1;
    if(money<0) return 0;
    if(dp[money]!=-1) return dp[money];
    ll ans=0;
    for(int i=0;i<coins.size();i++){
        if(money-coins[i]>=0)  ans+=f(money-coins[i],coins,dp)%M;
       // else return f(money,coins);
    }
    return dp[money]=ans%M;
}

void solve(){
int n,x;cin>>n>>x;
vector<int>coins(n,0);
forn(i,n) cin>>coins[i];
//vector<vector<int>>dp(n,vector<int>(x+1,-1));
vector<int>dp(x+1,-1);
cout<<f(x,coins,dp);



}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
solve();
 
 
return 0;}