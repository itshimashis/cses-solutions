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

bool distinct(string s){
   int arr[10]={0};
   forn(i,s.size()){
    arr[s[i]-'0']++;
   }
   forn(i,10){
    if(arr[i]>1) return false;

   }
   return true;
 
}
const int M=1e9+7;
bool func(vector<ll>&v,ll x,ll h){
    ll temp=0;
    for(int i=1;i<v.size();i++){
        if(v[i-1]+x<=v[i]) temp+=x;
        else temp+=v[i]-v[i-1];

    }
    temp+=x;
    if(temp>=h) return true;
    else return false;


}
static bool comp(pair<ll,ll>p1,pair<ll,ll>p2){
    return p1.second<p2.second;

}

void solve(){
ll n;cin>>n;
vector<ll>arr;
vector<ll>dep;
for(int i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    arr.pb(x);
    dep.pb(y);
}
sort(all(arr));
sort(all(dep));
ll ans=INT_MIN;
ll temp=0;
int i=0,j=0;
while(i<n && j<n){
    if(arr[i]<dep[j]){
        temp++;
        ans=max(ans,temp);
        i++;
        
    }
    else{
        temp--;
        ans=max(ans,temp);
        j++;
    }
}
cout<<ans<<endl;


}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

solve();


return 0;}