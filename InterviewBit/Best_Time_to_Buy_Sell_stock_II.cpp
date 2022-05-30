// Created by Nitin kumar singh
// problem link -> https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

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







int dp[100001][2];

int solve(const vector<int>& A,int i,int buy){
    if(i==A.size())return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    int profit=0;
    if(buy==0){
        profit=max(-A[i]+solve(A,i+1,!buy),solve(A,i+1,buy));
    }
    if(buy==1){
        profit=max(A[i]+solve(A,i+1,!buy),solve(A,i+1,buy));
    }

    return dp[i][buy]= profit;

}

int Solution::maxProfit(const vector<int> &A) {
    memset(dp,-1,sizeof dp);
    int ans=solve(A,0,0);
    return ans;;
}




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