#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++) 
#define  mp make_pair
#define ll long long int 
#define ull unsigned long long int
#define um unordered_map 
#define m map
#define pb push_back
#define all(x)       x.begin(),x.end()
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
void printvec(vector<ll>&v){
    forn(i,v.size()){
        cout<<v[i]<<" ";
    }
}
 
vector<vector<ll>>vvll;
void generate(vector<ll>&nums,vector<ll>&temp,int ind){
    if(ind==nums.size()){
        vvll.push_back(temp);
    }
    else{
       temp.pb(nums[ind]);
       generate(nums,temp,ind+1);
       temp.pop_back();
       generate(nums,temp,ind+1);
    }
 
 
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 int n;cin>>n;
vector<ll>vll;
ll total=0;
forn(i,n){
    ll x;cin>>x;
    vll.push_back(x);
  total+=vll[i];
}
ll ans=INT_MAX;
vector<ll>kl;
generate(vll,kl,0);
//cout<<vvll.size()<<endl;
forn(i,vvll.size()){
   // ll sum=0;
    forn(j,vvll[i].size()){
       // ll sum=0;
      // sum+=vvll[i][j];
      cout<<vvll[i][j]<<" ";
 
    }
   // ans=min(ans,abs(total-2*sum));
   cout<<endl;
    
}
//cout<<ans<<endl;
 
 
 
 
 
 
 
 
 
 
return 0;}