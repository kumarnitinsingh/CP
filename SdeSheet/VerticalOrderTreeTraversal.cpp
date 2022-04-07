// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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


  vector<vector<int>> verticalTraversal(TreeNode* root) {
   if(!root)return {};
   vector<vector<int>>ans;
   map<int,vector<pair<int,int>>>mp;
     queue<pair<TreeNode*,int>>q;
     int depth=0;
     q.push({root,0});
     while(!q.empty()){
           int k=q.size();
         while(k--){
          TreeNode* temp=q.front().first;
          int hd=q.front().second;
             q.pop();
             mp[hd].push_back({depth,temp->val});
            
             if(temp->left){q.push({temp->left,hd-1});}
             if(temp->right){q.push({temp->right,hd+1});}
         }
          depth++;
     }
     
      for (auto i = mp.begin(); i != mp.end(); i++) {
          vector<pair<int,int>>p=i->second;
          sort(p.begin(),p.end(),[&](const pair<int, int> &a, const pair<int, int> &b) {
                if (a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });
            vector<int>temp;
                for(auto t:p)
          temp.push_back(t.second);               
                ans.push_back(temp);
 
    }
  
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