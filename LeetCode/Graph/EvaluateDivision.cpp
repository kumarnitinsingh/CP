// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/evaluate-division/

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





double bfs(vector<pair<int,double>>graph[],int src,int des){
    vector<int>visited(1000,0);
    vector<double>dist(1000,-1.00);
    queue<pair<int,double>>q;
    q.push({src,1.00});
    dist[src]=1.00;
    visited[src]=1;
     while(!q.empty()){
         pair<int ,double>p=q.front();
         q.pop();
         int u=p.first;
         double uwt=p.second;
         
         for(auto nbr:graph[u]){
             if(visited[nbr.first]==0){
                 visited[nbr.first]=1;
                 dist[nbr.first]=dist[u]*nbr.second;
                
                 
                 if(nbr.first==des)return dist[des];
                 q.push({nbr.first,nbr.second});
             }
         }
         
     }
    
    return -1.00;
}


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=2*equations.size()+5;
         map<string,int>mp;
        
        vector<pair<int,double>>graph[n];
        int i=1;
         for(auto v:equations){
             if(!mp[v[0]])mp[v[0]]=i++;
             if(!mp[v[1]])mp[v[1]]=i++;
         }
        
         int j=0;
         for(auto v:equations){
             graph[mp[v[0]]].push_back({mp[v[1]],values[j]});
             graph[mp[v[1]]].push_back({mp[v[0]],(1/values[j])});
             j++;
         }
         
        
         vector<double>ans;
         
        for(auto q:queries){
            int src=mp[q[0]];
            int des=mp[q[1]];
            
             if(src==0 or des==0){
                 ans.push_back(-1.00);
                 continue;
             }
            
            if(src==des){
                ans.push_back(1.00);
                continue;
            }
            
           
            
            double ans1=bfs(graph,src,des);
            ans.push_back(ans1);
        }
          
        
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