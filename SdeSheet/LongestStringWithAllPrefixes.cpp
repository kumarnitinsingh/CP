// Created by Nitin kumar singh
// problem link ->

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
    node(char data){
        this->data=data;
        isterminal=false;
    }
};
class trie{
    public:
    node* root;
    trie(){
        root=new node('\0'); 
    }
    void insert(string& word){
        node* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->mp.count(word[i])==0){
                node *p=new node(word[i]);
                temp->mp[word[i]]=p;
                temp=p;
            }
            else temp=temp->mp[word[i]];
        }
        temp->isterminal=true;
    }
    bool isPrefix(string& word){
          node* temp=root;
       
        for(int i=0;i<word.size();i++){
            if(temp->mp.count(word[i])!=0){
                temp=temp->mp[word[i]];
                if(temp->isterminal==false)return false;
            }
            else return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
      trie* t=new trie();
    
    for(auto &s:a){
        t->insert(s);
    }
    string longest="";
    for(int i=0;i<n;i++){
        if(t->isPrefix(a[i])){
            if(a[i].size()>longest.size()){
                longest=a[i];
            }
            else if(a[i].size()==longest.size() and a[i]<longest){
                longest=a[i];
            }
        }
    }
    if(longest=="")return "None";
    return longest;
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