// Created by Nitin kumar singh
// problem link -> https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

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
    freopen("output2.txt","w",stdout);
    #endif
}




ll dp[1001][1000][2];

ll  solve2(string & num,ll n,ll sum,bool tight,int f){
    if(sum<0)return 0;
    if(n==1){
        if(sum>=0 and sum<=9)return 1;
        return 0;
    }

    if(dp[n][sum][tight]!=-1)return dp[n][sum][tight];
    ll ans=0;
    ll upper= 9;
    ll dig=f?1:0; //to avoid trailing zeroes
    f=0; 

    for(;dig<=upper;dig++){
         ans=(ans+solve2(num,n-1,sum-dig,(tight and (dig==upper)),f))%mod;
    }

    return dp[n][sum][tight]=ans;

}

int Solution::solve(int A,int B){
    memset(dp,-1,sizeof dp);
    string num="";
    for(int i=0;i<A;i++)num+='9';
    int ans=solve2(num,A,B,1,1);;
    return ans;

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