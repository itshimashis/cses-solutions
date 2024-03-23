#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//policy based data structure /*ordered sets basically/*
template<class T>using pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(key) ans find_by_order(the nth element you want to find)
//upper_bound and upper_bound also works fine
#define forn(i,n) for(int i=0;i<n;i++) 
#define  mp make_pair
#define ll long long int 
#define um unordered_map 
#define m map
#define pb push_back
#define ln '\n'
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
typedef struct range{
    int l;
    int r;
    int index;
      bool operator < (const range &other) const
    {
        if(l == other.l)
            return r > other.r;
        return l < other.l;
    }

}range;



void solve(){
    int n;
    cin>>n;
    vector<range> ranges(n);
    vector<bool> contained(n);
    vector<bool> contains(n);
    for(int i = 0; i < n; i++)
    {
        cin>>ranges[i].l;
        cin>>ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());
    int maxEnd = 0;
    for(int i = 0; i < n; i++)
    {
        if(ranges[i].r <= maxEnd)
            contained[ranges[i].index] = true;
        maxEnd = max(maxEnd, ranges[i].r);
    }
    int minEnd = 1e9 + 1;
    for(int i = n-1; i >= 0; i--)
    {
        if(ranges[i].r >= minEnd)
            contains[ranges[i].index] = true;
        minEnd = min(minEnd, ranges[i].r);
    }
    for(int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << ln;
    for(int i = 0; i < n; i++)
        cout << contained[i] << " ";
    cout << ln;




}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

solve();


return 0;}