// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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

int position(vector<int>&inorder,int key,int start,int end){
    for(int i=start;i<=end;i++){
        if(inorder[i]==key)return i;
    }
    return -1;
}

TreeNode* build(vector<int>&postorder,vector<int>&inorder,int start,int end,int &idx){
    if(start>end)return NULL;
   
    int key=postorder[idx];
    int pos=position(inorder,key,start,end);
    TreeNode* root=new TreeNode(key);
    
    idx--;
     root->right=build(postorder,inorder,pos+1,end,idx);
    root->left=build(postorder,inorder,start,pos-1,idx);
   
    return root;
}



    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          int n=inorder.size();
       // if(n==1)return new TreeNode(postorder[0]);
        int idx=n-1;
        return build(postorder,inorder,0,n-1,idx);
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