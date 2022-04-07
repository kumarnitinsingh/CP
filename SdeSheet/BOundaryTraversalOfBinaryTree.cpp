// Created by Nitin kumar singh
// problem link -> https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

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

void left(Node *root,vector<int>&ans){
    if(!root)return;
     
    if(root->left){ ans.push_back(root->data);left(root->left,ans);}
    else if(root->right){ans.push_back(root->data); left(root->right,ans);}
}
void right(Node *root,vector<int>&ans){
    if(!root)return;
    if(root->right){ right(root->right,ans);ans.push_back(root->data);}
    else if(root->left) {right(root->left,ans);ans.push_back(root->data);}
}

void leaf(Node* root,vector<int>&ans){
     if(root==NULL)return;
     leaf(root->left,ans);
     if(root->left==NULL and root->right==NULL){ans.push_back(root->data);}
     
     leaf(root->right,ans);
}


    vector <int> boundary(Node *root)
    {  
        
        if(!root)return{};
         vector<int>l,r,le,pe;
       l.push_back(root->data);
        //Your code here
       
        vector<int>ans;
       // ans.push_back(root->data);
        left(root->left,l);
       
        leaf(root->left,le);
        leaf(root->right,pe);
        right(root->right,r);
        
        
        for(int i=0;i<l.size();i++)ans.push_back(l[i]);
        
        for(int i=0;i<le.size();i++)ans.push_back(le[i]);
         for(int i=0;i<pe.size();i++)ans.push_back(pe[i]);
        
        for(int i=0;i<r.size();i++)ans.push_back(r[i]);
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