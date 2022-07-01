// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/satisfiability-of-equality-equations/

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




void dfs(vector<int>graph[],int src,vector<int>&color,int t){
     color[src]=t;
    for(auto e:graph[src]){
        if(color[e]==0)dfs(graph,e,color,t);
    }
}

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int>graph[26];
        for(auto e:equations){
            if(e[1]=='='){
             int x=e[0]-'a';
              int y=e[3]-'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
                }
        }
         
        vector<int>color(26,0);
        
        int t=0;
         for(int i=0;i<26;i++){
             t++;
             if(color[i]==0){
                 dfs(graph,i,color,t);
             }
         }
        
        
        for(auto e:equations){
            if(e[1]=='!'){
                int x=e[0]-'a';
                int y=e[3]-'a';
                
                if(x==y or x!=y and color[x]==color[y])return false;
            }
        }
        return true;
    }
};





int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here





   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}