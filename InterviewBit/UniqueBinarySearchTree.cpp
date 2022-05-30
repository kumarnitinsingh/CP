// Created by Nitin kumar singh
// problem link -> https://www.interviewbit.com/problems/unique-binary-search-trees/

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



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 
   vector<TreeNode*> generate(int lo,int hi){
       vector<TreeNode*>cans;
       if(lo>hi){
           cans.push_back(NULL);
           return cans;
       }
       for(int i=lo;i<=hi;i++){
           vector<TreeNode*>l=generate(lo,i-1);
           vector<TreeNode*>h=generate(i+1,hi);
           for(int x=0;x<l.size();x++){
               for(int y=0;y<h.size();y++){
                   TreeNode* root=new TreeNode(i);
                   root->left=l[x];
                   root->right=h[y];
                   cans.push_back(root);
               }
           }
           l.clear();
           h.clear();
       }
       return cans;
   }
  

vector<TreeNode*> Solution::generateTrees(int n) {
    
     
     return generate(1,n);
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