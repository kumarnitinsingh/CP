// Created by Nitin kumar singh
// problem link ->

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

int sub[200001];
void subtree(vector<int>tree[],int src,int par){
    int si=0;
    sub[src]=0;

    for(auto child:tree[src]){
        if(child!=par){
            subtree(tree,child,src);
            si+=sub[child];
        }
    }

     sub[src]=1+si;
}


int  dfs(vector<int>tree[],int n,int src,int par){


     for(auto child:tree[src]){
        if(child!=par){
            if(sub[child]>n/2){
                return dfs(tree,n,child,src);
            }
        }
     }
     return src;
}
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

        int n;cin>>n;
        vector<int>tree[n+1];
    
    
        for(int i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        subtree(tree,1,-1);
        
    int ans=dfs(tree,n,1,-1);
    cout<<ans<<endl;



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}