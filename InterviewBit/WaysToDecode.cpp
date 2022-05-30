// Created by Nitin kumar singh
// problem link -> https://www.interviewbit.com/problems/ways-to-decode/

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






int mod=1e9+7;
  vector<int>dp;
 int solve(string A,int n){
    if(n==0 or n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    int ones=0;
    if(A[n-1]!='0'){
        ones=(ones+solve(A,n-1))%mod;
    }
    int two=0;
    if(A[n-2]!='0'){
        int num=(A[n-2]-'0')*10+(A[n-1]-'0');
        if(1<=num and num<=26)
          two=(two+solve(A,n-2))%mod;
    }

    return dp[n]=(ones+two)%mod;
}

int Solution::numDecodings(string s) {
     int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++)
        {
            if(s[i-1] == '0')
            {
                if(i == 1 || (s[i-2] != '1' && s[i-2] != '2')) return 0;
                
                dp[i] = dp[i-2];
            }
            else
            {
                if(i != 1 && ((s[i-2] == '2' && s[i-1] <= '6') || (s[i-2] == '1')))
                {
                    dp[i] = (dp[i-1] + dp[i-2])%mod;
                }
                else
                {
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[n];
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