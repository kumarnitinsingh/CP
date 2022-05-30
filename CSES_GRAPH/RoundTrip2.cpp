// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1678/

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

const int maxn=2e5+5;
ll n,m;
vector<ll>graph[maxn];
vector<ll>topo;
vector<ll>vis1(maxn,0),Stack(maxn,0),res;
stack<ll>st;
int f=0;
void dfs(ll src, ll par){
   
    vis1[src]=1;
    Stack[src]=1;
    st.push(src);

    for(auto nbr:graph[src]){
        if(!vis1[nbr]){
            dfs(nbr,src);
        }
        else if(Stack[nbr] ){

             if(res.size()==0){
                    res.push_back(nbr);
                    while(!st.empty() and st.top()!=nbr){
                        res.push_back(st.top());
                        st.pop();
                    }
                    res.push_back(nbr);
                }
        }
    }

   
    Stack[src]=0;
     if(st.top()==src) st.pop();

     return ;
    
}
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
    //  memset(mat,0,sizeof mat);
         cin>>n>>m;
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            graph[x].push_back(y);
        }
            

            for(int i=1;i<=n;i++){
             if(vis1[i]==0)   dfs(i,-1);
             if(res.size()>0){
                  reverse(res.begin(),res.end());
                cout<<res.size()<<endl;

       
            for(auto e:res)cout<<e<<" ";
                f=1;
                break;
             }

        }

                if(f==0){cout<<"IMPOSSIBLE";
                return 0;}
              
            

           
   
           

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}