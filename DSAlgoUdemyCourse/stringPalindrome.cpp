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

bool ispalindrome(string &s){
    int i=0;int j=s.size()-1;

    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
string breakPalindrome(string &s) {
    int f=0;
    if(s.size()==1)return "";
        for(int i=0;i<s.size();i++){
            if('a'<s[i] and s[i]<='z'){char temp=s[i];f=1;s[i]='a';
           if(ispalindrome(s)){
            s[i]=temp;
             f=0;
            continue;

           }
            break;}
        }
       if(f==0)s[s.size()-1]='b';

        return s;
}
int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
   string s;
   cin>>s;
   string str=breakPalindrome(s);
   cout<<str<<endl;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}