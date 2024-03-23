#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++) 
#define ll long long int 
#define pb push_back
#define all(x)       x.begin(),x.end()
#define mod 1000000007
void solved_by_himashis(){
int n;cin>>n;
vector<int>coins(n);
int sum=0;
forn(i,n) {cin>>coins[i]; sum+=coins[i];}
bool dp[n][sum+1];
//if it is possible to construct sum of i till using coins till the index j then 
//dp[j][i]=1 , otherwise it is zero
memset(dp,0,sizeof dp);
//dp[0][coins[0]]=1;;
for(int i=0;i<n;i++){
    dp[i][coins[i]]=1;
}
for(int i=1;i<n;i++){
    for(int j=1;j<=sum;j++){
       if(j-coins[i]>=0) dp[i][j]=dp[i-1][j-coins[i]];
        dp[i][j]=dp[i][j]|dp[i-1][j];
       
      dp[i][coins[i]]=1;
       //dp[i][]

    }
}
vector<int>ans;
for(int i=1;i<=sum;i++){
    for(int j=0;j<n;j++){
        if(dp[j][i]){
           // cout<<i<<" ";
            ans.push_back(i);
            break;
        }
    }
}
cout<<ans.size()<<endl;
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   // int t;cin>>t;
  //  while(t--){
solved_by_himashis();
return 0;}