// Created by Nitin kumar singh
// problem link ->https://www.spoj.com/problems/EXPEDI/

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
     ll t;cin>>t;
     while(t--){
          ll n;cin>>n;
          vector<pair<ll,ll>>v(n);
          loop(i,n)cin>>v[i].first>>v[i].second;
          ll l,p;
          cin>>l>>p;

          sort(v.begin(),v.end(),greater<pair<ll,ll>>());
          
            
          vector<pair<ll,ll>>temp;
          for(int i=0;i<n;i++){
               ll ch=l-v[i].first;
               
               temp.push_back({ch,v[i].second});
          }
          ll cn=0;
         // loop(i,n)cout<<temp
          priority_queue<pair<ll,ll>>pq;

          // for(int i=0;i<n;i++){
          //      cout<<temp[i].first<<" "<<temp[i].second<<endl;
          // }
            
            ll k=l;
          
            int o=0;
            int f=0;
            ll st=0;
            int i=0;
          while(i<n){
                 int j=temp[i].first;
               if(j-st<=p){
                    pq.push({temp[i].second,temp[i].first});
                   
                    p=p-(j-st);
                     st=j;
                    
               }
               else{
                    if(!pq.empty()){
                        
                              p+=pq.top().first;
                                 cn++;
                                 pq.pop();
                         }
                         
                      
                    
                    else{f=-1;break;}
                    
                    continue;
               }
                i++;
               }

          
          if(f==-1){cout<<-1<<endl;continue;}

          else 
               {
               l-=temp[n-1].first;
               if(p>=l){cout<<cn<<endl;continue;}
               else {
                     while(!pq.empty() and p<l){
                         p+=pq.top().first;
                         cn++;
                         pq.pop();
                     }
                     if(p>=l){cout<<cn<<endl;continue;}
                     else cout<<-1<<endl;
               }
     }

}




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}