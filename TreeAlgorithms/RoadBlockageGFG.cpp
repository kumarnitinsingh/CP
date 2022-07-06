// Created by Nitin kumar singh
// problem link -> https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems#

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



 const int ma=1e5+5;

vector<int>entry,Exit,value,dist;

int timer=0;


 
void dfs(vector<int>tree[],int src,int par){
     entry[src]=timer;
     value[timer]=src;
     timer++;
     if(par!=-1)dist[src]=1+dist[par];
     
     for(auto child:tree[src]){
        if(child!=par){
           
            dfs(tree,child,src);
            
            
        }
     }
     Exit[src]=timer;
     value[timer]=src;
     timer++;
}
 

 
class Solution {
  public:
    vector<int> solve(int n, int Q, vector<vector<int> > &Edge,
                      vector<vector<int> > &query) {
        // code here
        timer=0;
        vector<int>tree[n+1];
        vector<int>ans;
         
         dist.resize(n+1);
         Exit.resize(n+1);
         entry.resize(n+1);
         value.resize(2*n+1);
         dist[0]=0;
         
        for(auto e:Edge){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        
         dfs(tree,0,-1);
       
       
        vector<int>prefix,suffix(2*n);
        prefix.push_back(dist[value[0]]);
        for(int i=1;i<2*n;i++)prefix.push_back(max(prefix.back(),dist[value[i]]));
        suffix[2*n-1]=dist[value[2*n-1]];
        for(int i=2*n-2;i>=0;i--)suffix[i]=max(suffix[i+1],dist[value[i]]);
         
         for(auto q:query){
             int u=q[0];
             int v=q[1];
               int f=entry[u];
                int l=Exit[u];
                
                if(dist[v]>dist[u]){f=entry[v],l=Exit[v];}
                  f;
                  l;
                  int ans1=0,ans2=0;
                  if((f-1)>=0)ans1=prefix[f-1];
                  if((l+1)<=2*n-1)ans2=suffix[l+1];
                ans.push_back(max(ans1,ans2));
            
         }
         
         dist.clear();
         entry.clear();
         Exit.clear();
         value.clear();
       
          
         return ans;
    }



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();






   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}