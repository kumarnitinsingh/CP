// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

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

class node{
    public:
  
   node* left;
   node* right; 
    bool isterminal;
    node(){
        left =nullptr;
        right=nullptr;
        isterminal=false;
    }

};

class Trie {
public:
    node* root;
    Trie() {
        root=new node();
        
       
    }
    
    void insert(string word) {
        node* temp=root;
        for(int i=0;i<word.size();i++){
             char ch=word[i];
            
            if(ch=='0'){
                if(temp->left)temp=temp->left;
                else {
                    node* t=new node();
                    temp->left=t;
                    temp=t;
                }
            }
            else{
                if(temp->right)temp=temp->right;
                else{
                     node* t=new node();
                    temp->right=t;
                    temp=t;
                }
            }
        }
            
        temp->isterminal=true;
    }
        
      int MaximumXor(string word){
          node* temp=root;
          int ans=0;
          for(int i=0;i<word.size();i++){
              char ch=word[i];
              if(ch=='0'){
                  if(temp->right){
                      temp=temp->right;
                      ans+=(1<<(32-i-1));
                  }
                  else temp=temp->left;
              }
              else{
                  if(temp->left){
                      temp=temp->left;
                     ans+=( 1<<(32-i-1));
                  }
                  else temp=temp->right;
                  
              }
          }
       return ans;   
      }  
    
  
    
  
};
    
  
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto p:nums){
            string str = std::bitset<32>(p).to_string();
            t.insert(str);
        }
        
        int ans=0;
         
        for(int i=0;i<nums.size();i++){
            string str = std::bitset<32>(nums[i]).to_string();
            int temp=t.MaximumXor(str);
            ans=max(ans,temp);
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