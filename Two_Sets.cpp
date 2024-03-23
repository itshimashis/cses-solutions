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
vector<int> create(int n){
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.pb(i+1);
    }
    return ans;
}
ll factorial(int n){
  ll ans=1;
  for(int i=1;i<=n;i++){
    ans=ans*i;
  }
  return ans;
}
ll ncr(int n,int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}
 
int highest(ll n){
    int ans=0;
    while(n%2==0){
        n=n/2;
        ans++;
 
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
ll n;cin>>n;
ll check=n*(n+1)/2;
if(check%2==0){
    cout<<"YES"<<endl;
    vector<ll>v1,v2;
   if(n%4==0){
    for(int i=1;i<=n/4;i++){
        v1.push_back(i);
        v1.push_back(n+1-i);
        v2.push_back(i+n/4);
        v2.pb(n+1-i-n/4);
    }

   }
     else if(n%4==3){
        v1.push_back(n);
        for(int i=1;i<=n/4;i++){
            v1.pb(i);
            v1.pb(n-i);
            v2.pb(n/4+i);
            v2.pb(n-i-n/4);

        }
        v2.push_back(n/2);
        v2.push_back(n-n/2);

    }
    cout<<v1.size()<<endl;
    forn(i,v1.size()){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    cout<<v2.size()<<endl;
    forn(i,v2.size()){
        cout<<v2[i]<<" ";
    }

}
else cout<<"NO"<<endl;
return 0;}