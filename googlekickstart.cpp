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
       
       int n;
       cin>>n;
       int w=1;
       while(n--){
       	ll n,c;
       	cin>>n>>c;
       	vector<ll>v(10002,0);
       	  while(n--){
       	  		ll l,r;
       	  		cin>>l>>r;
       	  		v[l+1]++;
       	  		v[r]--;
       	  }

       	  ll ans =0;
       	  for(int i=1;i<10001;i++){
       	  	v[i]=v[i]+v[i-1];
       	  }
       	  // for(int i=0;i<10001;i++){
       	  // 	 if(v[i]>0)ans+=v[i];
       	  // }
       	    sort(v.begin(),v.end(),greater<ll>());
       	     int i=0;
       	    while(i<v.size() and i<c and v[i]>0){
       	    	ans+=v[i]*2;i++;

       	    }
       	   ans=ans-1;
       
          cout<<"case #"<<w<<": "<<ans<<endl;
          w++;

}

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}