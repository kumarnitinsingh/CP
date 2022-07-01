// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/validate-binary-tree-nodes/

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




bool solve(vector<int>graph[],int src,int par,vector<int>&visited,vector<int>&Stack){
     visited[src]=1;
    Stack[src]=1;
    for(auto child:graph[src]){
        if(visited[child]==0){
          bool temp=  solve(graph,child,src,visited,Stack);
            if(temp==true)return true;
        }
        else if(Stack[child]==1){
            return true;
        }
        
    }
    Stack[src]=0;
    return false;
    
}


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int>graph[n];
         queue<int>q;
        vector<int>indegree(n,0);
          for(int i=0;i<n;i++){
              if(leftChild[i]!=-1){
                  indegree[leftChild[i]]++;
                  graph[i].push_back(leftChild[i]);
              }
          }
        
         for(int i=0;i<n;i++){
              if(rightChild[i]!=-1){
                  indegree[rightChild[i]]++;
                  graph[i].push_back(rightChild[i]);
              }
          }
        
          int val=0;
        for(int i=0;i<n;i++){
            if(indegree[i]>1)return false;
             if(indegree[i]==0)val++;
        }
         if(val>=2)return false;
         vector<int>visited(n,0),Stack(n,0);
        
          bool ans =solve(graph,0,-1,visited,Stack);
        if(ans==true)return false;
        
      
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