#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++) 
#define ll long long int 
#define pb push_back
#define all(x)       x.begin(),x.end()
#define mod 1000000007
void solved_by_himashis(){
ll d1,d2,d3,d4;cin>>d1>>d2>>d3>>d4;
ll ans=0;
ll alice=0;
ll bob=0;
ans+=d1;
ans+=min(d2,d3)*2;
alice+=d1;
while(alice>=0){
   ans+=min(alice,d4);
   alice--;
   d4--;

}
cout<<ans<<endl;
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
solved_by_himashis();}
return 0;}