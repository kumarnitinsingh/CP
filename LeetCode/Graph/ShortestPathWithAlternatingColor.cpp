// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/shortest-path-with-alternating-colors/

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




 
vector<int>bfs(vector<int>red[],vector<int>blue[],int n){
    vector<pair<int,int>>dist(n,{INT_MAX,INT_MAX});
    queue<pair<int,int>>q;
    int rcolor=-1;
    int bcolor=1;
    q.push({0,bcolor});
    q.push({0,rcolor});
    int curdis=0;
    dist[0]={0,0};
     while(!q.empty()){
          int s=q.size();
           while(s--){
               int u=q.front().first;
               int col=q.front().second;
               q.pop();
               
               if(col==bcolor){
                   
                   for(auto nbr:red[u]){
                       if(dist[nbr].second>curdis+1){
                           dist[nbr].second=curdis+1;
                           q.push({nbr,rcolor});
                       }
                       
                   }
               }
               else if(col==rcolor){
                    for(auto nbr:blue[u]){
                       if(dist[nbr].first>curdis+1){
                           dist[nbr].first=curdis+1;
                           q.push({nbr,bcolor});
                       }
                       
                   }
               }
           }
         curdis++;
     }
    
    vector<int>ans(n);
    
    for(int i=0;i<n;i++){
        int k=min(dist[i].first,dist[i].second);
        if(k==INT_MAX)ans[i]=-1;
        else ans[i]=k;
    }
    
    return ans;
}



class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>red[n];
        vector<int>blue[n];
        for(auto e:redEdges){
            red[e[0]].push_back(e[1]);
        }
        for(auto e:blueEdges){
            blue[e[0]].push_back(e[1]);
        }
        
        vector<int>ans=bfs(red,blue,n);
        return ans;
        
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