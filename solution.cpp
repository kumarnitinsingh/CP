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

    void dfsHelper(vector<vector<int>>l,int node,int* visited,vector<int>& ans){
         visited[node]=1;
         ans.push_back(node);
             for(auto nbrs:l[node]){
            if(!visited[nbrs])dfsHelper(l,nbrs,visited,ans);
            return;
        }
            
        
        
    }   

    vector<int> dfs(int source,vector<vector<int>>g,int n){
        vector<int>ans;
        int * visited=new int[n+2]{0};
        dfsHelper(g,source,visited,ans);
        return ans;
    }



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
        int t;cin>>t;
        while(t--){
            ll n;cin>>n;
            vector<vector<int>>g(n+2);

            vector<int>v(n);loop(i,n)cin>>v[i];

            for(int i=0;i<n-1;i++){
                g[i+1].push_back(i+2);
            }

            for(int i=0;i<n;i++){
                if(v[i]==0){
                    g[i+1].push_back(n+1);
                }
                else if(v[i]==1) g[n+1].push_back(i+1);
            }

                 vector<int>ans;
          //       for(int i=1;i<=n+1;i++){
                 ans=dfs(n+1,g,n);
          //        if(ans.size()==n+1)break;

          // }  
                 if(ans.size()!=n+1){ans=dfs(1,g,n);}

               if(ans.size()!=n+1){cout<<-1<<endl;continue;}
              else  {
                for(auto x:ans)cout<<x<<" ";;
                    cout<<endl;
              }

        }




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}

