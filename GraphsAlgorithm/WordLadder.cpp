// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/word-ladder/

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


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>s1,dic(wordList.begin(),wordList.end());
         if(dic.count(endWord)==0)return 0;
         s1.insert(beginWord);
       
        int ans=0;
        int len=beginWord.size();
         while(!s1.empty())
        {
             
            ans++;
            unordered_set<string>cur;
            
              for(auto w:s1){
               
                   
                  for(int i=0;i<len;i++){
                      char temp=w[i];
                      
                      for(char j='a';j<='z';j++){
                          w[i]=j;
                          
                          if(w==endWord){
                              return ans+1;
                          }
                          if(dic.count(w)==0)continue;
                          
                          dic.erase(w);
                          cur.insert(w);
                          
                      }
                      w[i]=temp;
                  }
                  
              }
            
              s1=cur;
        }
        return 0;
        
    }
};









int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here





   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}