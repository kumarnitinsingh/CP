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

bool ispossible(bool graph[101][101],int m,int V,int color,int src,vector<int>&temp){
    
    for(int i=0;i<V;i++){
        if(graph[src][i] and temp[i]==color)return false;
    }
    return true;
}
bool solve(bool graph[101][101], int m, int V,int color,int src,vector<int>&temp){
    if(src==V)return true;
    
    for(int i=1;i<=m;i++){
        if(ispossible(graph,m,V,i,src,temp)){
            temp[src]=i;
            if(solve(graph,m,V,i,src+1,temp)==true)return true;
            temp[src]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int>temp(V+1,0);
    return solve(graph,m,V,0,0,temp);
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}