// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1140/

#include <bits/stdc++.h>

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>

using namespace std;

//using namespace __gnu_pbds;
//typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;

//find_by_order(k) and order_of_key(k)



#define ll             long long int
#define ld             long double
#define mod            1000000007
#define inf            1e18
#define vec            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x



void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    #endif
}
class work{
public:
    int Start;
    int End;
    int profit;
    work(int x,int y,int p){
        Start=x;
        End=y;
        profit=p;

    }
};

const int maxN=2e5+5;

int n;
vector<work>v;
int dp[100][100000];

int solve(int i,int last){
    if(i==n)return 0;

   if(last>=v[i].Start)return dp[i][last]=solve(i+1,last);
    if(dp[i][last]!=-1)return dp[i][last];

    int op1=v[i].profit+solve(i+1,v[i].End);
    int op2=solve(i+1,last);
    int ans=max(op1,op2);

     return dp[i][last]=ans;
}


bool mycom(work w1,work w2){

     if(w1.End<w2.End)return true;
      return false;
}
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     cin>>n;
     map<int,int>mp;
     vector<work>a;
     loop(i,n){
        int x,y,p;cin>>x>>y>>p;
        y++;
        work w(x,y,p);
        mp[x]=0,mp[y]=0;
        a.push_back(w);
     }

     int cn=0;
     for(auto& e:mp){
        e.second=cn++;
     }

    
     vector<vector<pair<int,int>>>project(cn+1);

     for(int i=0;i<n;i++){
        project[mp[a[i].End]].emplace_back(mp[a[i].Start],a[i].profit);
     }
     vector<long long>dp(cn+1,0);

     for(int i=0;i<cn;i++){
        if(i>0)dp[i]=dp[i-1];

        for(auto p:project[i]){
            dp[i]=max(dp[i],p.second+dp[p.first]);
        }
     }

     cout<<dp[cn-1]<<endl;


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}