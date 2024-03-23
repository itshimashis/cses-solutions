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
int n;cin>>n;
vector<ll>dp(n+1,0);
for(int i=1;i<=n;i++){
    ll temp=i;
    ll ans=INT_MAX;
    while(temp>=1){
        ll digit=temp%10;
        temp=temp/10;
        if(digit==0) continue;
        ans=min(ans,dp[i-digit]+1);
    }
    dp[i]=ans;
}
cout<<dp[n];
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
solve();
 
 
return 0;}