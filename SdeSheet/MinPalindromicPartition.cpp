// Created by Nitin kumar singh
// problem link -> https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1#

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

bool ispalindrome(string s){
    int i=0;int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
}

int solve(string str, unordered_map<string,int>&mp){
    if(str.size()==0)return 0;
    if(ispalindrome(str)){return 0;}
    if(mp.count(str)!=0)return mp[str];
    int ans=INT_MAX;
    for(int j=1;j<str.size();j++){
         if(ispalindrome(str.substr(0,j))){
             int temp= 1+solve(str.substr(j),mp);
             ans=min(ans,temp);
         }
    }
    return mp[str]=ans;
}


    int palindromicPartition(string str)
    {
        // code here
        unordered_map<string,int>mp;
        return solve(str,mp);
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