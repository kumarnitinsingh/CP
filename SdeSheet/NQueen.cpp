// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/n-queens/

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

bool canplace(vector<vector<int>>&v,int i,int j,int n){
    for(int k=0;k<n;k++){
        if(v[i][k]==1) return false;
        if(v[k][j]==1)return false;
    }
    
    int p=i-1,q=j-1;
    while(p>=0 and q>=0){
        if(v[p][q]==1)return false;
        p--;
        q--;
    }
    p=i-1;q=j+1;
    while(p>=0 and q<n){
         if(v[p][q]==1)return false;
        p--;
        q++;
    }
    
    return true;
    
}


void solve(int n,int i, vector<vector<vector<int>>>&ans,vector<vector<int>>&v){
    if(i==n ){ans.push_back(v);return;}

        for(int k=0;k<n;k++){
        if(canplace(v,i,k,n)){
         v[i][k]=1;
          solve(n,i+1,ans,v);
             v[i][k]=0;
            }
        }
       
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<vector<int>>>ans;
        vector<vector<int>>v(n,vector<int>(n,0));
        solve(n,0,ans,v);
       
        vector<vector<string>>temp;
        for(auto vp:ans){
            vector<string>st;
            for(int i=0;i<n;i++){
                string s="";
                for(int j=0;j<n;j++){
                    
                    if(vp[i][j]==0)s+=".";
                    else s+="Q";
                }
                st.push_back(s);
            }
            temp.push_back(st);
        }
        return temp;;
        
        
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