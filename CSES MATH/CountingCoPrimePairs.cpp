// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/2417/

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





int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();


     int t;
     t=1;
     while(t--){
        int n;
        cin>>n;
        vector<ll>v(n);
        int k=1e6+5;
        vector<ll>cn(k,0),cn2(k,0);
        loop(i,n){
            cin>>v[i];cn[v[i]]++;

        }

        for(int i=1;i<k;i++){
            for(int j=i;j<k;j+=i){
                cn2[i]+=cn[j];
            }
        }


        for(int i=1;i<k;i++){
            cn2[i]=(cn2[i]*(cn2[i]-1))/2;
        }

        for(int j=k-1;j>=1;j--){
            for(int i=2*j;i<k;i+=j){
                cn2[j]-=cn2[i];
            }
        }
        cout<<cn2[1]<<endl;

    
     }



   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}