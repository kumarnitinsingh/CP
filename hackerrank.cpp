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

string decode(string s){
    vector<int>v(27,0);
    for(unsigned long int i=0;i<s.size();i++){
         v[s[i]-'a']++;
    }
  string str="";
    for(int i=0;i<27;i++){
        str+=to_string(v[i]);
            
    }
    return str;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
         int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
     map<string,vector<string>>m;
      for(int i=0;i<n;i++){
          string d=decode(v[i]);
        
          m[d].push_back(v[i]);
      }
    unsigned long int ans=0;
    auto ref=m.begin();
    
    for(auto it=m.begin();it!=m.end();it++){
    	 vector<string>v=it->second;
          if(v.size()>ans){
                ref=it;
              ans=v.size();
              //cout<<ans<<endl;
          }
        
         //  for(unsigned long int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
    }
    
     cout<<ref->second.size()<<endl;
      vector<string> ans2=ref->second;
    sort(ans2.begin(),ans2.end());
     for(unsigned long int i=0;i<ans2.size();i++)cout<<ans2[i]<<" ";
    
    return 0;


  


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}