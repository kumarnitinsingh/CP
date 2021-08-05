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


vector<string> ans;
unordered_set<string>h;
  
  bool mycom(string s1,string s2){
    return s1<s2;  }

void Permutaion(string input,int i){
  
   
    if(input[i]=='\0'){
        if(h.find(input)==h.end()){
        ans.push_back(input);}
        h.insert(input);
        return;
    }
    
    for(int k=i;k<input.size();k++){
        swap(input[i],input[k]);
        Permutaion(input,i+1);
        swap(input[i],input[k]);
    }
return;
    
}

vector<string> findSortedPermutations(string s){
    //Your code goes here. Do not change the function or parameters. You can use
     Permutaion(s,0);
 
   sort(ans.begin(),ans.end(),mycom);
   vector<string>v(ans);
  // for(int i=0;i<ans.size();i++)v.pb(ans[i]);
   ans.clear();
   h.clear();
return  v;
}


int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

    string s;
    cin>>s;
   vector<string>ans1= findSortedPermutations(s);
    loop(i,ans1.size())cout<<ans1[i]<<" ";
    cout<<endl<<endl<<endl;
    string k;
    cin>>k;
  vector<string>str = findSortedPermutations(k);
   loop(i,str.size())cout<<str[i]<<" ";


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}