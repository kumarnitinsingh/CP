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



string normalize(const string &sentence) {
    string copy = sentence;
 

     int i=0;int j=0;


     for(int i=0;i<copy.length();i++){
          if(copy[i]==' ')continue;
           if((i>0?copy[i-1]:' ')==' ' and 'a'<= copy[i] and copy[i]<='z')copy[i]=(char)((int)copy[i]-32);
           else{
            j=i+1;
            while(j< copy.length() and copy[j]!=' ' ){
                if('A'<=copy[j] and copy[j]<='Z')copy[j]=char((int)copy[j]+32);
                j++;
            }

           }
           i=j-1;
     }
    return copy;
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

   string s;
   getline(cin,s);
   cout<<normalize(s);
   




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}