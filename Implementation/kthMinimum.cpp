// Created by Nitin kumar singh
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>


//using namespace_-gnu_pbds;
using namespace std;

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


int solve(vector<int> s,int k){
    if(s.size()==1)return s[0];

    int x=(rand()*s.size())%s.size();
    vector<int> l,r,g;
    for(int i=0;i<s.size();i++){
        if(s[i]<s[x])l.push_back(s[i]);
        else if(s[i]==s[x])r.push_back(s[i]);
        else g.push_back(s[i]);
    }

    if(k<=l.size())return solve(l,k);
    else if(k<=l.size()+r.size())return s[x];
    else return solve(g,k-l.size()-r.size());
    return INT_MAX;
}

int Maximum(vector<int> s,int k){
    if(s.size()==1)return s[0];
  // int x=((rand()*s.size())+1)%s.size();
     int x=s.size()/2;
    vector<int>l,r,g;
    for(int i=0;i<s.size();i++){
        if(s[i]<s[x])l.push_back(s[i]);
        else if(s[i]==s[x])r.push_back(s[i]);
        else g.push_back(s[i]);
    }
    if(g.size()>=k)return Maximum(g,k);
    else if(k<=g.size()+r.size())return s[x];
    else Maximum(l,k-r.size()-g.size());
 return INT_MIN;
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    int n;int k;
    cin>>n>>k;
    vector<int>v(n);
    loop(i,n)cin>>v[i];

    cout<<Maximum(v,k)<<endl;





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}