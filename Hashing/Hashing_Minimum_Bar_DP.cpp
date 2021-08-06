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

int MIN_BAR_HELPER(string s,vector<string>&v,int idx,unordered_set<string>&m){
    if(s[idx]=='\0')return 0;

    int ans=INT_MAX;
    string currentString="";
    for(int i=idx;s[i]!='\0';i++){
        currentString+=s[i];
        if(m.find(currentString)!=m.end()){
            int temp=MIN_BAR_HELPER(s,v,i+1,m);
            if(temp!=-1){
                ans=min(ans,1+temp);
            }
        }
    }

if(ans==INT_MAX)return -1;
  
  return ans;
 }

int MIN_BAR(string s,vector<string>&v){
    unordered_set<string>m;
    for(auto x:v){m.insert(x);}

        int ans=MIN_BAR_HELPER(s,v,0,m);

    return ans-1;
}


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
 //use this as input ;
/*  
   5
thequickbrownfox
the 
quickbrown
fox
quick
brown
*/
     int n;
     cin>>n;
         string s;
         cin>>s;
      vector<string>v(n);
      loop(i,n)cin>>v[i];

      int ans=MIN_BAR(s,v);
     

      cout<<ans;


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}