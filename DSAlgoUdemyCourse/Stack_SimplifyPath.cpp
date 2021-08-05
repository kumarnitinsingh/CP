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


string simplifyPath(string path){
 

 istringstream ss(path);
 vector<string>tokens;
 string token;
 while(getline(ss,token,'/')){
    if(token=="." or token== "")continue;
    tokens.push_back(token);
 }

 vector<string>Stack;
 if(path[0]=='/')Stack.push_back("");

  for(string token:tokens){
    if(token ==".." ){
        if(Stack.size()==0 or Stack[Stack.size()-1]=="..")Stack.push_back("..");
        else if(Stack[Stack.size()-1]!="")Stack.pop_back();}
    else Stack.push_back(token);
  }

  if(Stack.size()==1 and Stack[0]=="")return "/";

  string ans="";

 int i=0;
   for(auto x:Stack){
      if(i!=Stack.size() and i!=0){ans+='/';}
      ans+=x;
      i++;
   }

   return ans;

}


int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

   string s;
   cin>>s;
    cout<<simplifyPath(s);


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}


