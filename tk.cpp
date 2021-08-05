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
    
     //write your code here
     

     ll t;
     cin>>t;
     while(t--){
         unsigned ll a,b;
         cin>>a>>b;
         ll ans=gcd(a,b);
         if(ans==a and ans==b){cout<<"0 0"<<endl;continue;}
        if(ans==1 and a!=1 and b!=1){
            ll diff=max(a,b)-min(a,b);
           
            unsigned ll m=min(a,b);
            unsigned ll temp=0;
            while(temp<=m){
                temp=temp+diff;
            }
             ll leftmin=temp-diff;
             ll leftmax=temp;
             ll rightmin=temp;
             ll rightmax=rightmin+diff;

        
             ll ans1=gcd(leftmin,rightmin);
             ll ans2=gcd(leftmax,rightmax);
              if(ans1>ans2)(cout<<ans1<<" "<<max(a,b)-max(leftmin,rightmin))<<endl;
               if(ans1<ans2)(cout<<ans2<<" "<<max(leftmax,rightmax)-max(a,b))<<endl;
               else{
                cout<<ans1<<" "<<min(min(a,b)-min(leftmin,rightmin),min(leftmax,rightmax)-min(a,b))<<endl;
               }
               continue;
           }

         if(ans==1 and a==1 or b==1){cout<<max(a,b)-1<<" "<<( a==2 or b==2 ?0:1)<<endl;continue;}
         if(ans==min(a,b) ){cout<<max(a,b)-min(a,b)<<" "<<(gcd(max(a,b)-min(a,b),0)==ans?0:min(a,b))<<endl;continue;}
         else {cout<<max(gcd(a,b),gcd(max(a,b)-min(a,b),0))<<" "<<(gcd(a,b)>=gcd(max(a,b)-min(a,b),0)?0:min(a,b))<<endl;continue;}
     }




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}