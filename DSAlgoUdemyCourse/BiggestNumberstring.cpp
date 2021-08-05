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
bool mycom(int x,int y){
    string f= (to_string(x)+to_string(y));
      string s=(to_string(y)+to_string(x));

     // cout<<f<<" "<<s<<endl;
      return f>s;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
   // sort(numbers.begin(),numbers.end(),greater<int>());
    sort(numbers.begin(),numbers.end(),mycom);
    loop(i,numbers.size())cout<<numbers[i]<<" ";
    string s="";
    for(auto x:numbers){
        s+=to_string(x);
    }
return s;
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

    int n;
    cin>>n;
    vector<int>v(n);
    loop(i,n)cin>>v[i];
    cout<<concatenate(v);



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}