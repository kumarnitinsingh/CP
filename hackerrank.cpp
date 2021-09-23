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

long double fact(long double n){
    long double ans=1;
    for(int i=2;i<=n;i++){
        ans=ans*i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
       
       int t;
       cin>>t;
       int w=1;
       while(t--){
         
         long double n;
         cin>>n;

         vector<ll>v;
          for(int i=1;i<=n;i++)v.push_back(i);

         double ans;

         vector<ll>res;
         do{
            ll cn=1;
            ll last=v[0];
            cout<<v[0]<<" ";
            for(int i=1;i<n;i++){
                cout<<v[i]<<" ";
                if(v[i]>last){
                    cn++;
                    last=v[i];
                }
            }
            cout<<"->"<<cn<<endl;
            res.push_back(cn);

         }while(next_permutation(v.begin(),v.end()));

         ll fc=fact(n);

          long double total=accumulate(res.begin(),res.end(),0);

          for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
            cout<<endl;

          cout<<total<<endl;

          ans=double(total)/double(fc);

       
          cout<<"case #"<<w<<": "<<fixed<<setprecision(8)<<ans<<endl;
          w++;

}

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}