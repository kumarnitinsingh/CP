// Created by Nitin kumar singh
// problem link -> https://www.codechef.com/START39B/problems/MINBLOCK

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
#define vecl            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x
#define endl           "\n"


void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    #endif
}

const int maxn =2e5+5;
ll si[maxn];
vector<ll>result;


void dfs(vector<pair<ll,ll>>graph[],ll src,ll par){
    si[src]=1;

    for(auto child:graph[src]){
        if(child.first==par)continue;
        dfs(graph,child.first,src);
        si[src]+=si[child.first];
    }
}


void dfs2(vector<pair<ll,ll>>graph[],ll src,ll par){

    for(auto child:graph[src]){
        if(child.first==par)continue;
        if(child.second){
            result.push_back(si[child.first]);
            continue;
        }
        dfs2(graph,child.first,src);
    }
}





int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here


     ll t;cin>>t;
     while(t--){
     ll n,k;
     cin>>n>>k;
     vector<pair<ll,ll>>graph[n+1];
     for(int i=1;i<n;i++){
         ll x,y,z;
         cin>>x>>y>>z;
         graph[x].push_back({y,z});
         graph[y].push_back({x,z});
     }
        
        dfs(graph,1,-1);
        dfs2(graph,1,-1);


        sort(result.begin(),result.end(),greater<ll>());

        ll sum=n;int i=0;
        while(i<result.size() and sum>k){
            sum-=result[i];
            i++;
        }

        if(sum>k)cout<<-1<<endl;
        else cout<<i<<endl;

        result.clear();

    }


   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}

