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

string stringTokenKey(string str,int key){
    char* token;
    token=strtok((char*)str.c_str()," ");
    while(key>1){
        token=strtok(NULL," ");
        key--;
    }
    return (string)token;
}
int ToInteger(string s){
    int ans=0;
    int p=1;
    for(int i=s.length()-1;i>=0;i--){
        ans+=((s[i]-'0')*p);
        p=p*10;
    }
    return ans;
}

bool numericOrdering(pair<string,string>s1,pair<string,string>s2){
    string a=s1.second;
    string b=s2.second;

    return ToInteger(a)<ToInteger(b);
}

bool lexico(pair<string,string>s1,pair<string,string>s2){
     string a=s1.second;
    string b=s2.second;
    return a<b;
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

     int n;
     cin>>n;
     cin.get();
     string temp;
     vector<string>v;

     for(int i=0;i<n;i++){
        getline(cin,temp);
        v.push_back(temp);
     }
    int key;
    string reversal,ordering;
    cin>>key>>reversal>>ordering;
    
    vector<pair<string,string>>vp;
    for(int i=0;i<n;i++){
        vp.push_back({v[i],stringTokenKey(v[i],key)});
    }
    
    if(ordering=="numeric"){
        sort(vp.begin(),vp.end(),numericOrdering);
    }
    else{
        sort(vp.begin(),vp.end(),lexico);
    }

   if(reversal=="true")reverse(vp.begin(),vp.end());

   for(int i=0;i<n;i++){
    cout<<vp[i].first<<endl;
   }
   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}