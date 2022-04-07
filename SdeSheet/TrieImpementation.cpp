// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/implement-trie-prefix-tree/

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
  char data;
   unordered_map<char,node*>mp;
    bool isterminal;
};

class Trie {
public:
    node* root;
    Trie() {
        root=new node();
        root->data='\0';
        root->isterminal=false;
    }
    
    void insert(string word) {
        node* temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
             if(temp->mp.count(ch)){
                 temp=temp->mp[ch];
             }
            else{
             node* p=new node();
            p->data=ch;
            if(i<word.size()-1)p->isterminal=false;
           // if(i==word.size()-1)p->isterminal=true;
            temp->mp[ch]=p;
                temp=p;
            } 
        }
        temp->isterminal=true;
    }
    
    bool search(string word) {
          node* temp=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
             if(temp->mp.count(ch)==0)return false;
              else{
                 temp=temp->mp[ch];
             }
        }
      return temp->isterminal;       
    }
    
    bool startsWith(string prefix) {
            node* temp=root;
      
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
             if(temp->mp.count(ch)==0){
                 return false;}
                 temp=temp->mp[ch];
             
        }

        
        return true;
    
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