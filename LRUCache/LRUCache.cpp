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
        string key;
        int value;
         node(string s,int val){
            key=s;
            value=val;
         }
};

class LRUCache{
public:
    int maxsize;
    list<node>l;
    unordered_map<string,list<node>::iterator>m;

    LRUCache(int size){
        if(size>1)maxsize=size;
        else maxsize=1;
    }

    void insert(string key,int val){
        //if key is present
         if(m.count(key)!=0){
             m[key]->value=val;
         }

         if(l.size()==maxsize){
             node t=l.back();
             m.erase(t.key);
             l.pop_back();
         }

         node n(key,val);
         l.push_front(n);
         m[key]=l.begin();
    }

    int* getValue(string key){
        if(m.count(key)!=0){
            auto it=m[key];
            
            l.push_front((*it));
            m[key]=l.begin();
                l.erase(it);
             return &l.begin()->value;
        }
        return NULL;
    }
    string getRecentkey(){
        return l.front().key;
    }
};


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     LRUCache lru(4);
     lru.insert("mango",10);
     lru.insert("apple",20);
     lru.insert("guava",30);

     cout<<lru.getRecentkey()<<endl;

     lru.insert("mango",50);
     cout<<lru.getRecentkey()<<endl;
      lru.insert("banana",90);
      lru.insert("pineapple",100);
      cout<<lru.getRecentkey()<<endl;
     
     if(lru.getValue("apple")==NULL){
        cout<<"apple doesnt exist"<<endl;
     }

  
       if(lru.getValue("guava")==NULL){
        cout<<"guava doesnt exist"<<endl;
     }
       if(lru.getValue("banana")==NULL){
        cout<<"banana doesnt exist"<<endl;
     }








   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}