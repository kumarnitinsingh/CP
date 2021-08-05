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



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

        //input graph
     
        // 10 9
        // 0 1
        // 1 2
        // 2 9
        // 2 6
        // 6 7
        // 6 8
        // 2 3
        // 3 4
        // 3 5


      
    int n,m;
    cin>>n>>m;
    vector<int>g[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

     vector<int>degree(n);
     int counter=0;
     //calculating degrees
     for(int i=0;i<n;i++){
        degree[i]=g[i].size();
    }
     
     vector<int>leaves;
     //storing leave nodes
     for(int i=0;i<n;i++){
        if(degree[i]==0 || degree[i]==1){
            leaves.push_back(i);
            degree[i]--;
        }
     }
     counter=leaves.size();

   
     while(counter<n){
          vector<int>temp_leaves;
        for(auto node:leaves){
            for(auto nbr:g[node]){
                degree[nbr]--;
                if(degree[nbr]==1){
                    temp_leaves.push_back(nbr);
                    degree[node]=0;
                }
            }
        }
        counter+=temp_leaves.size();
        leaves=temp_leaves;
     }

     for(auto centers:leaves){
        cout<<centers<<" ";
     }



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}