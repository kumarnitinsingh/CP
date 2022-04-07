// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/scramble-string/

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

unordered_map<string,bool>dp;
bool solve(string s1,string s2){
     if(s1.size()!=s2.size())return false;
    if(s1.size()==0 and s2.size()==0)return true;
    if(s1==s2)return true;
    if(s1.size()<1)return false;
    if(dp.count(s1+s2)!=0)return dp[s1+s2];
    bool flag=false;
    int n=s1.size();
    for(int k=1;k<n;k++){
        if(solve(s1.substr(0,k),s2.substr(n-k,k)) and
           solve(s1.substr(k),s2.substr(0,n-k))){
               flag=true; break;
           }
         if(solve(s1.substr(0,k),s2.substr(0,k)) and 
           solve(s1.substr(k),s2.substr(k))
           )   {
             flag=true;
             break;
         }
    
    }
    return dp[s1+s2] =flag;
}


    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
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