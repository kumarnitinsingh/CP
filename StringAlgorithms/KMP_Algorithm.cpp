// Created by Nitin kumar singh
// problem link ->https://leetcode.com/problems/implement-strstr/

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

void LPI(string s,vector<int>&lpi){
    int len=0,i=1;
   
    lpi[0]=0;
    int m=s.size();
    while(i<m){
        if(s[i]==s[len]){
            len++;
            lpi[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lpi[len-1];
            }
            else{
                lpi[i]=0;
                i++;
            }
        }
    }
   return;
}

int KMPAlgorithm(string text,string pattern){
    int m=pattern.size();
     vector<int>lpi(pattern.size()+1);
       LPI(pattern,lpi);
    int i=0;int j=0;
    
   int n=text.size();
    if(n==0 and m==0)return 0;
    if(n==0)return -1;
    if(m==0)return 0;
    while(i<n){
        if( pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==pattern.size()){return i-pattern.size();}
        else if(i<n and pattern[j]!=text[i]){
            if(j!=0)j=lpi[j-1];
            else i=i+1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}