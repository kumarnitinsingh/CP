// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/implement-strstr/

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


//this is far better hashfunction with minimum collision
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}


//this is my own hash function and we need to choose the best hash function such that collision can be minimzed;

//Remember this is not the good hash function 
int hashFunction(string patt){
    int ans=0;
     for(int i=0;i<patt.size();i++){
         int k=int(patt[i]-'a')+1;
         ans+=k*k;
     }
    return ans;
}

int Rabinkarp(string text,string patt){
    int hash=hashFunction(patt);
    int temp=0;
    for(int i=0;i<patt.size();i++){
        int k=int(text[i]-'a')+1;
        temp+=k*k;
    }
    //cout<<patt<<" "<<hash<<endl;
    int n=text.size();
    int m=patt.size();
    if(temp==hash){
        bool t=true;
        for(int i=0;i<m;i++){
            if(text[i]!=patt[i]){t=false;break;}
        }
        if(t)return 0;
    }
    int j=0;
    int i=patt.size();
    
    while(i<(n)){
        
        int k=int(text[j]-'a')+1;
        temp-=k*k;
        j++;
        k=int(text[i]-'a')+1;
        temp+=k*k;
        i++;
      // cout<<temp<<endl;
    if(temp==hash){
        
        bool t=true;
        for(int p=j;p<j+m;p++){
            if(text[p]!=patt[p-j]){t=false;break;}
        }
        
        if(t)return j;}
      
    }
    return -1;
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