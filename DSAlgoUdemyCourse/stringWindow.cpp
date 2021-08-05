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

string solve(string s,string p){
 int fp[256]={0};
 int sp[256]={0};

 for(int i=0;i<p.size();i++){
  fp[p[i]]++;
 }
int cn=0;
 int i=0;int j=0;
 int min_length=INT_MAX;
 int start=-1;int wimdow_length=0;
 for(;j<s.size();j++){
  char ch=s[j];
  sp[ch]++;
  if(fp[ch]!=0 and sp[ch]<=fp[ch]){
    cn++;
  }

  if(cn==p.size()){
    //do some work
    while(fp[s[i]]==0 or fp[s[i]]<sp[s[i]]){
      sp[s[i]]--;
      i++;
    }
    
    wimdow_length=j-i+1;
    if(wimdow_length<min_length){
    min_length=wimdow_length;
     start=i;
  }
  }

  
 }
if(start==-1)return "not found";
 return s.substr(start,min_length);
  
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    

    string s,p;
    cin>>s>>p;
    string ans=solve(s,p);
    cout<<ans<<endl;
   // cout<<isUnique(s)<<endl;


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}