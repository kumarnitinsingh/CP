// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/lru-cache/

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
  int data;
    int key;
    node(int data,int key){
        this->data=data;
        this->key=key;
    }
    
};
class LRUCache {
public:
    list<node>l;
    unordered_map<int,list<node>::iterator>mp;
    int size;
    LRUCache(int capacity) {
        size=capacity;
        
    }
    
    int get(int key) {
        int x=-1;
        if(mp.count(key)!=0){
             x=mp[key]->data;
            auto it=mp[key];
            l.push_front(*it);
            mp[key]=l.begin();
             l.erase(it);
            return l.front().data;
        }
        return x;
    }
    
    void put(int key, int value) {
         if(mp.count(key)!=0){
             auto it=mp[key];
             l.erase(it);
             l.push_front(node(value,key));
             mp.erase(key);
             mp[key]=l.begin();
               
            return;
         }
         if(mp.size()==size){
             node temp=l.back();
              int k=temp.key;
               mp.erase(k);
              l.pop_back();
         }
        
         node n(value,key);
         l.push_front(n);
         mp[key]=l.begin();
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