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
#define vecl            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x
#define endl           "\n"


void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    #endif
}

bool isValid(string& s){
    stack<char>st;
    for(auto e:s){
        if(e=='('){
            st.push(e);
        }
        else{
            if(!st.empty() and st.top()=='(')st.pop();
            else return false;
        }
    }
    return st.empty()!=0;
}

int cn=0;;
int dp[100000];
bool solve(string & s,int i,string osf){
    if(i==s.size()){
        if(isValid(osf)){
            cn++;
            if(cn>1)return false;
        }
        return true;
    }
    if(cn>1)return false;
    if(dp[i]!=-1)return dp[i];

    bool op1=false,op2=false,op3=false;
    if(s[i]!='?'){
     op1=solve(s,i+1,osf+s[i]);
    }
   
    if(s[i]=='?'){
      op2=  solve(s,i+1,osf+'(');
       op3= solve(s,i+1,osf+')');
    }

    return dp[i]=op1 or op2 or op3;
}

int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();

     ll t;
     cin>>t;
     while(t--){
        memset(dp,-1,sizeof dp);
          string s;
          cin>>s;
          cn=0;
          bool ans=solve(s,0,"");
          if(ans)cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
     }






   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}