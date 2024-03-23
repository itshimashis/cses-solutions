#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<numeric>
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
//ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
void printvec(vector<int>&v){
    forn(i,v.size()){
        cout<<v[i]<<" ";
    }
}

//building a segment tree
void buildtree(int s,int e,int si,vector<int>&segtree,vector<int>&v){
    if(s==e) {segtree[si]=v[s]; return;}
    int mid=(s+e)/2;
    buildtree(s,mid,2*si,segtree,v);
    buildtree(mid+1,e,2*si+1,segtree,v);
    segtree[si]=min(segtree[2*si],segtree[2*si+1]);
}
//query inside a segment tree
int query(int s,int e,int qs,int qe,int si,vector<int>&segtree){
    if(s>qe || qs>e) return INT_MAX;//no overlaap
    if(s>=qs && e<=qe) return segtree[si];//total overlap
    int mid=(s+e)/2;
    int left=query(s,mid,qs,qe,2*si,segtree);
    int right=query(mid+1,e,qs,qe,2*si+1,segtree);
     return min(left,right);
}
//point update inside a segment tree
void update(int si,int ind,int val,int s,int e,vector<int>&segtree,vector<int>&v){
    if(s==e){
        segtree[si]=val;
        v[ind]=val;
        return;
    }
    int mid=(s+e)/2;
    if(ind>mid){
        update(2*si+1,ind,val,mid+1,e,segtree,v);
    }
    else update(2*si,ind,val,s,mid,segtree,v);
     segtree[si]=min(segtree[2*si],segtree[2*si+1]);
    

}
void solve(){
int n,q;cin>>n>>q;
vector<int>v(n+1);
for(int i=1;i<=n;i++) cin>>v[i];
vector<int>segtree(4*n);
buildtree(1,n,1,segtree,v);
//cout<<segtree[1]<<endl;
while(q--){
    int a,b,c;cin>>a>>b>>c;
    if(a==2){
        int ans=query(1,n,b,c,1,segtree);
        cout<<ans<<endl;
    }
    else if(a==1){
        update(1,b,c,1,n,segtree,v);
    }
}

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
solve();
return 0;}