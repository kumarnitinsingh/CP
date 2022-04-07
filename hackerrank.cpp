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
    freopen("output2.txt","w",stdout);
    #endif
}


bool ispalindrome1(string s){
    int i=s.size()-5,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}

bool ispalindrome2(string s){
    int i=s.size()-6,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}

map<string,int>mp;
bool solve(string& s,int i,string osf){
     if(osf.size()>=5 and ispalindrome1(osf) )return 0;
     if(osf.size()>=6 and ispalindrome2(osf) )return 0;
    
     if(i==s.size())return 1;
   // if(s.size()<5)return 1;
        string temp=osf.size()>5?osf.substr(osf.size()-5,5):osf  +to_string(i);
    if(mp.find(temp)!=mp.end())return mp[temp];

    
    if(s[i]!='?')return mp[temp] =solve(s,i+1,osf+s[i]);

    bool op1=solve(s,i+1,osf+"1");
    
    bool op2=solve(s,i+1,osf+"0");

    return mp[temp]=op1 or op2; 

}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
       int T;
       cin>>T;
       int w=1;
       while(T--){
        cout<<"case #"<<w<<": ";
          w++;
         // memset(dp,-1,sizeof dp);
          ll n;cin>>n;
          string s;cin>>s;
          string osf="";
          bool f=solve(s,0,osf);
          if(f)cout<<"POSSIBLE"<<endl;
          else cout<<"IMPOSSIBLE"<<endl;

       mp.clear();
       
          
          

}

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}