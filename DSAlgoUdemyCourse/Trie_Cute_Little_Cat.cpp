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
  bool isTerminal;
  unordered_map<char,node*>m;

  node(char val){
    data=val;
    isTerminal=false;
  }
};

class Trie{
public:
    node* root;
    Trie(){
        root=new node('\0');
 }
    void insert(string word){
        node* temp=root;
        for(auto ch:word){
            if(temp->m.count(ch)==0){
                node* n=new node(ch);
                temp->m[ch]=n;
            }
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }


    bool search(string word){
        node* temp=root;
        for(auto ch:word){
            if(temp->m.count(ch)==0)return false;
            temp=temp->m[ch];
        }

        return temp->isTerminal;
    }

};

void SearchInTrie(Trie t,string document,int i,unordered_map<string,bool>&hash){
  
   node *temp=t.root;

   for(int j=i;j<document.size();j++){
    if(temp->m.count(document[j])==0)return;
      temp=temp->m[document[j]];
      if(temp->isTerminal){
        string out=document.substr(i,j-i+1);
        hash[out]=true;
      
      }
   }
return;
}

void CuteCat(string document,vector<string>words){
    //first insert trie of words;
    Trie t;
    for(auto word:words)t.insert(word);
    unordered_map<string,bool>hash;
     for(int i=0;i<document.size();i++){
         SearchInTrie(t,document,i,hash);
     }

     for(auto word:words){
        if(hash[word]){
            cout<<word<<" : true"<<endl;
        }
        else cout<<word<<" : false"<<endl;
     }
   
return ;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
         string document="little cute cat loves to code in c++";
    vector<string>words={"ttle","cute cat","quick","cat"};
    CuteCat(document,words);


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}