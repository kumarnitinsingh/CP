// Created by Nitin kumar singh
// problem link -> https://www.hackerrank.com/challenges/chessboard-game-again-1/problem?isFullScreen=true

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


 map<pair<int,int>,int>mp;
 
   int dx[4]={-2,-2,1,-1};
   int dy[4]={1,-1,-2,-2};
   
 int grundy(int x,int y){
     if(mp.count({x,y}))return mp[{x,y}];
     set<int>st;
     for(int i=0;i<4;i++){
         int nx=x+dx[i];
         int ny=y+dy[i];
         if(nx>0 and ny>0 and nx<=15 and ny<=15){
             st.insert(grundy(nx,ny));
         }
     }
     int mex=0;
     while(true){
         if(st.find(mex)!=st.end())mex++;
         else break;
     }
     
     return mp[{x,y}]= mex;
 }
 
 string chessboardGame(vector<vector<int>> coins) {
    int xo=0;
    
    for(auto e:coins){
       
        xo^=grundy(e[0],e[1]);
    }
    
    if(xo)return "First";
    return "Second";

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