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
bool checkRightAngled(ll X1, ll Y1,
                      ll X2, ll Y2,
                      ll X3, ll Y3)
{
    // Calculate the sides
    ll A = (ll)pow((X2 - X1), 2)
            + (ll)pow((Y2 - Y1), 2);
 
    ll B = (ll)pow((X3 - X2), 2)
            + (ll)pow((Y3 - Y2), 2);
 
    ll C = (ll)pow((X3 - X1), 2)
            + (ll)pow((Y3 - Y1), 2);
 
    // Check Pythagoras Formula
    if ((A > 0 and B > 0 and C > 0)
        and (A == (B + C) or B == (A + C)
             or C == (A + B)))
        return true;
 
    else
        return false;
}

void solve(){
ll n,m;cin>>n>>m;
set<ll>s1;
multiset<ll>s2;
s1.insert(0);
s1.insert(n);
s2.insert(n);
for(int i=0;i<m;i++){
    ll x;cin>>x;
    s1.insert(x);
    ll prevval=*prev(s1.find(x));
    ll nextval=*next(s1.find(x));
    s2.erase(s2.find(nextval-prevval));
    s2.insert(prevval-x);
    s2.insert(nextval-x);
    cout<<*rbegin(s2)<<" ";
}

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

int t;cin>>t;

solve();


return 0;}