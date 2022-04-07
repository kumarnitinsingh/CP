// Created by Nitin kumar singh
// problem link -> https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem

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
    freopen("output2.txt","w",stdout);
    #endif
}


//bool ispossible(vector<int>v,int i,int mid){}

ll dp[101][2][2][2];


ll solve(string & num,ll n,ll even ,ll leading,ll tight){
    if(n==0)return 1;

    if(dp[n][even][leading][tight]!=-1)return dp[n][even][leading][tight];

 


    if(even){
           ll ub=tight?(num[num.size()-n]-'0'):9;
        vector<int>digits={0,2,4,6,8};
        ll ans=0;
        for(auto d:digits){
          if(d<=ub){
            ans+=solve(num,n-1,0,0,(tight and (d==ub)));
          }  
        }
        return dp[n][even][leading][tight]=ans;
    }
    else{
           ll ub=tight?(num[num.size()-n]-'0'):9;
        ll ans=0;

        if(leading){
           ans+=solve(num,n-1,0,1,0);
        }
           vector<int>digits={1,3,5,7,9};
           
           for(auto d:digits){
            if(d<=ub){
                ans+=solve(num,n-1,1,0,(tight and (d==ub)));
            }
           } 

        

        return dp[n][even][leading][tight]=ans;

    }
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
       int T;
       cin>>T;
       int w=1;
       while(T--){
          cout<<"case #"<<w<<": "; 
            w++;

        
     ll  x,y;
     cin>>x>>y;
     x--;
     string s=to_string(y);
     string r=to_string(x);
     memset(dp,-1,sizeof dp);
     ll ans=solve(s,s.size(),0,1,1);
     memset(dp,-1,sizeof dp);
      ll ans2=solve(r,r.size(),0,1,1);
      cout<<ans-ans2<<endl;

}

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}