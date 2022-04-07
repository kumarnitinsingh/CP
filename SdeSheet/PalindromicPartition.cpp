// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/palindrome-partitioning/

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
    while(i<j){
    if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
  }
void solve( vector<vector<string>>&ans,string s,vector<string>temp){
     if(s.size()==0){
         ans.push_back(temp);
         return;
     }
    
    for(int i=0;i<s.size();i++){
        string str1=s.substr(0,i+1);
        string str2=s.substr(i+1);
        if(ispalindrome(str1)){
            temp.push_back(str1);
            solve(ans,str2,temp);
            temp.pop_back();
        }
    }
   
}



    vector<vector<string>> partition(string s) {
         vector<vector<string>>ans;
        vector<string>temp;
        solve(ans,s,temp);
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