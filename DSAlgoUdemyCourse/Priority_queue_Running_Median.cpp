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



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code 
         

         int n ;
         cin>>n;
        vector<int>v;
         loop(i,n){
            int x;
            cin>>x;
            v.push_back(x);
         }
 
          priority_queue<int> Max;
          priority_queue<int,vector<int>,greater<int>>Min;
            float median=v[0];
            Max.push(v[0]);
            cout<<median<<endl;
          for(int i=1;i<n;i++){
            if(v[i]<median){
                while(!Max.empty() and Min.size()<Max.size()){
                    int x=Max.top();
                    Max.pop();
                    Min.push(x);
                }
                Max.push(v[i]);
            }
            else{
                  while(!Min.empty() and Max.size()<Min.size()){
                    int x=Min.top();
                    Min.pop();
                    Max.push(x);
                }
                Min.push(v[i]);
            }

            if(Min.size()==Max.size()){
                median=float(Min.top()+Max.top())/2;
                cout<<median<<" ";
                continue;
            }
            else if(Min.size()>Max.size()){
                median=Min.top();
                cout<<median<<" ";
                continue;
            }
            else {
                median=Max.top();
                cout<<median<<" ";
                continue;
            }
          }

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}