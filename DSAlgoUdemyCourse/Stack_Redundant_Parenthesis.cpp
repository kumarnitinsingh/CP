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
bool Redundantparenthesis(string str){
  
  bool ans=false;
  stack<char>st;

  for(int i=0;i<str.size();i++){
    char ch=str[i];
     if(ch!=')')st.push(ch);
     if(ch==')'){
        ans=false;
        while(!st.empty() and st.top()!='('){
            if(st.top()=='+' || st.top()=='-'||st.top()=='*'||st.top()=='/')ans=true;
            st.pop();
        }
        st.pop();
        if(ans==false)return true;
     }


  }

return false;
}
int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

    string s;
    cin>>s;
    if(Redundantparenthesis(s))cout<<" Redundantparenthesis";
    else cout<<"Not Redundantparenthesis";



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}