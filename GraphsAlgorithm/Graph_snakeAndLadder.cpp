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



int Bfs(vector<int>g[],int src,int des,int n){
    vector<int>dist(n+1,INT_MAX);
    vector<bool>visited(n+1,false);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    visited[src]=true;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto nbr:g[u]){
            if(!visited[nbr]){
                dist[nbr]=dist[u]+1;
                visited[nbr]=true;
                q.push(nbr);
            }
        }
        
    }
    
    return dist[des];
}

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int>> ladders){
    
    vector<int>Graph[n+1];
    vector<int>board(n+1,0);
    for(unsigned int i=0;i<snakes.size();i++){
        board[snakes[i].second]=-(snakes[i].second-snakes[i].first);
    }
    for(unsigned int j=0;j<ladders.size();j++){
        board[ladders[j].first]=ladders[j].second-ladders[j].first;
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=6;j++){
            int p=i+j+board[i+j];
            
            if(p<=n)Graph[i].push_back(p);
        }
    }
    Graph[n].push_back(n);
    // for(int i=0;i<n+1;i++){
    //   cout<<i<<"->";
    //   for(auto x:Graph[i]){
    //     cout<<x<<",";
    //   }
    //   cout <<endl;
    // }
    
    int ans = Bfs(Graph,0,n,n);
    
    return ans;
    
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
       int n=36;
       vector<pair<int,int>>ladders;
        vector<pair<int,int>>snakes;
          ladders.push_back({2,15});
           ladders.push_back({5,7});
            ladders.push_back({9,27});
             ladders.push_back({18,29});
              ladders.push_back({25,35});

              snakes.push_back({4,17});
               snakes.push_back({12,34});
                snakes.push_back({16,24});
                 snakes.push_back({30,32});



           cout<<min_dice_throws(n,snakes,ladders)<<endl;
   

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}