// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1139/

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
    freopen("output.txt","w",stdout);
    #endif
}


const int maxn=2e5+5;
vector<int>tree[maxn];
set< int>*mp[maxn];
 int color[maxn],ans[maxn];


//first Implementation
void dfs1(int src,int par){

        int mx=0;
        int mxNode=-1;
    for(auto child:tree[src]){
        if(child!=par){
            dfs1(child,src);
            if(mx<mp[child]->size()){
                mx=mp[child]->size();
                mxNode=child;
            }
          
        }
    }


    if(mxNode==-1){mp[src]=new set<int>();}
    else mp[src]=mp[mxNode];

    mp[src]->insert(color[src]);

    for(auto child :tree[src]){
        if(child!=par and child!=mxNode){

            for(int i:*mp[child])
            mp[src]->insert(i);
        }
    }

    ans[src]=mp[src]->size();
}



//second implementation;

set<int>dfs(int src,int par){
    set<int>parentSet;
    parentSet.insert(color[src]);

    for(auto child:tree[src]){
        if(child!=par){
            set<int>childSet=dfs(child,src);

            if(childSet.size()>parentSet.size()){

                for(auto p:parentSet){
                    childSet.insert(p);
                }
                swap(childSet,parentSet);
            }
            else{
                for(auto p:childSet){
                    parentSet.insert(p);
                }
            }
        }
    }

    ans[src]=parentSet.size();
    return parentSet;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>color[i];
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }    


        dfs(1,-1);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}