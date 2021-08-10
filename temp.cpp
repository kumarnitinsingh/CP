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

struct triple{
   ll timereq;
   ll timeHave;
   ll idx;
};

bool mycom(triple x,triple y){
    if(x.timeHave<y.timeHave)return true;
    if(x.timeHave==y.timeHave and  x.timereq<y.timereq)return true;
    return false;
}

ll solve(vector<triple>&v,ll n,vect &st){
	sort(v.begin(),v.end(),mycom);
    ll ans=0;
     ll j=0;
    

    for(int i=0;i<n;i++){
        if(v[i].timereq<=v[i].timeHave and v[i].timeHave>=v[i].timereq+j){
            ans++;
             st.push_back({v[i].idx,j,v[i].timereq+j});
            j+=v[i].timereq;
        }

    }
    return ans;

}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
      
       ll t;
       cin>>t;
       while(t--){
       	   ll n;cin>>n;
       	   vector<triple>v(n);
       	   loop(i,n)cin>>v[i].timereq;
       	   loop(i,n){cin>>v[i].timeHave;v[i].idx=i+1;}

           for(int i=0;i<n;i++){
             v[i].timereq=v[i].timeHave-v[i].timereq;
           }

       	   	vect st;
       	   	
       	   ll ans=solve(v,n,st);
            cout<<ans<<endl;
            for(unsigned int i=0;i<st.size();i++){
                cout<<st[i][0]<<" "<<st[i][1]<<" "<<st[i][2]<<endl;
            }
       	  
       }




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}