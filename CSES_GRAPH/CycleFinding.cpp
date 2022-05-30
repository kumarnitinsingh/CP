// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1197/

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
    freopen("output3.txt","w",stdout);
    #endif
}

ll NINF=-1e16;
ll INF=1e16;



ll n,m;
const int maxn=3e3+5;
vector<vector<ll>>edges;
vector<ll>par(maxn,-1),ans;


bool bellmanford(){
   
    vector<ll>dist(n+1,1e16);
    dist[1]=0;
    par[1]=1;
    ll x=-1;
    for(int i=1;i<=n;i++){
        x=-1;
         for(auto e:edges){
             ll u=e[0];
             ll v=e[1];
             ll wt=e[2];
                if(dist[v]>(dist[u]+wt)){
                   
                    dist[v]=(dist[u]+wt);
                    par[v]=u;
                    x=v;
                }
             
         }
    }
    

  
       if(x==-1){
        return false;
       }
        

        for(int i=1;i<=n;i++)x=par[x];
        
        for(auto v=x; ;v=par[v]){
            ans.push_back(v);
            if(v==x and ans.size()>1){
                break;
            }
        }

        reverse(ans.begin(),ans.end());

         return true;
            
    
}




 
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
   
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            ll x,y,z;
            cin>>x>>y>>z;
            vector<ll>temp={x,y,z};
            edges.push_back(temp);
        }
            
           
           bool an=bellmanford();

           if(an==false){
            cout<<"NO"<<endl;
            return 0;
           }

          

         
             cout<<"YES"<<endl;
            for(auto e:ans){
                cout<<e<<" ";
            }
        
         
         
           

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}