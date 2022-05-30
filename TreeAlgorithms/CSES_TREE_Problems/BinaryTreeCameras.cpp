// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/binary-tree-cameras/

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

map<pair<TreeNode*,pair<bool,bool>>,int>dp;

int solve(TreeNode* root,bool cam,bool parcam){
    if(root==NULL){
        if(cam)return INT_MAX-9999;
        else return 0;
    }
    if(root->left==NULL and root->right==NULL){
        if(cam)return 1;
        else if(parcam)return 0;
        else return INT_MAX-9999;
    }
    
    if(dp.find({root,{cam,parcam}})!=dp.end())return dp[{root,{cam,parcam}}];
    
    if(cam){
        return dp[{root,{cam,parcam}}]=1+min(solve(root->left,1,1),solve(root->left,0,1))+
                  min(solve(root->right,1,1),solve(root->right,0,1));
    
    }
   else if(parcam){
         return dp[{root,{cam,parcam}}]=min(solve(root->left,1,0),solve(root->left,0,0))+
                  min(solve(root->right,1,0),solve(root->right,0,0));
    }
    
    else{
         return dp[{root,{cam,parcam}}]=min(solve(root->left,1,0)+min(solve(root->right,0,0),solve(root->right,1,0)),
                                             solve(root->right,1,0)+min(solve(root->left,0,0),solve(root->left,1,0)))   ;                      
                                                                      
    }
    
    
}

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        dp.clear();
        
        return min(solve(root,1,0),solve(root,0,0));
    }
};

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