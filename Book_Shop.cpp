
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
long long int f(int ind,vector<pair<int,int>>&v,int x,vector<vector<int>>&dp){
 if(ind==0){
    //if(x==0) return 0;
    return 0;
 }
 if(dp[ind][x]!=-1) return dp[ind][x];
 int take=0,notake=0;
 //int ans=INT_MIN;
 if(x>=v[ind].first){
    take=v[ind].second+f(ind-1,v,x-v[ind].first,dp);
 }
 notake=f(ind-1,v,x,dp);
 return dp[ind][x]=max(take,notake);

}
void solve(){
int n,x;cin>>n>>x;
vector<pair<int,int>>v(n+1);
vector<int>prices;
int maxi=-1;
forn(i,n){
int x;cin>>x;
prices.pb(x);
maxi=max(maxi,x);
}
vector<int>pages;
forn(i,n){
int x;cin>>x;
pages.pb(x);
}
forn(i,n){
    v[i+1]=(make_pair(prices[i],pages[i]));
}
vector<vector<int>>dp(n+1,vector<int>(x+1,0));
//cout<<f(n,v,x,dp);
for(int i=1;i<=n;i++){
    for(int j=0;j<=x;j++){
         int take=0,notake=0;
 //int ans=INT_MIN;
 if(j>=v[i].first){
    take=v[i].second+dp[i-1][j-v[i].first];
 }
 notake=dp[i-1][j];
  dp[i][j]=max(take,notake);
    }
}
cout<<dp[n][x];

}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
solve();
return 0;}