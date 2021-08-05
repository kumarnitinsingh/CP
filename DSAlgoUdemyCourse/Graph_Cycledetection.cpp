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

bool dfsHelper(int source,list<int>* l,bool *visited,int parent){
    visited[source]=true;
    
    for(auto nbrs:l[source]){
        if(!visited[nbrs] ){
            bool istrue=dfsHelper(nbrs,l,visited,source);
            if(istrue)return true;
        }
        else if(nbrs!=parent)return true;
    }
    return false;
}

bool dfs(int source,list<int>* l,int v){
    bool *visited=new bool[v]{0};
    return dfsHelper(source,l,visited,-1);
    
}
bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method
    list<int>* l=new list<int>[V];
    for(auto edge:edges){
        l[edge.first].push_back(edge.second);
        l[edge.second].push_back(edge.first);
    }
    
    
    return dfs(l[0].front(),l,V);
    
}


bool dfs_in_directed_graph(int source,list<int>* l,bool* visited,int V){
   static bool* Stack=new bool[V]{false};
    visited[source]=true;
    Stack[source]=true;
    for(auto nbrs:l[source]){
        if(!visited[nbrs]){ 
            bool istrue=dfs_in_directed_graph(nbrs,l,visited,V);
            if(istrue)return true;
        }
        else if(Stack[nbrs])return true;
    }
    Stack[source]=false;
    return false;
}
bool contains_cycle_in_directed_grap(int V,vector<pair<int,int> > edges){
    //Complete this method
     list<int>*l=new list<int>[V];
     for(auto edge:edges){
         l[edge.first].push_back(edge.second);
     }
    bool *visited=new bool[V]{false};
    return dfs_in_directed_graph(l[0].front(),l,visited,V);
    
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