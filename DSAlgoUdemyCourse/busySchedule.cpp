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

class mycom{
public:
	bool operator()(pair<int,int>a,pair<int,int>b){
		if(a.second<b.second)return true;
		if(a.second==b.second and a.first>b.first)return true;
	    return false;
	}
};



int countActivites(vector<pair<int,int> > activities){
    //Complete this method
    sort(activities.begin(),activities.end(),mycom());
       int ans;
       for(int i=0;i<activities.size();i++){
       	cout<<activities[i].first<<","<<activities[i].second<<" ";//112960, 114515, 81825, 93424, 54316,
       }
     int maxtime=activities[activities.size()-1].second;
     if(activities[0].second<=maxtime)ans=1;
     else ans=0;
     ans=1;
     int j=0;
    for(int i=1;i<activities.size();i++){
        if(activities[j].second<=activities[i].first and activities[i].second<=maxtime){ans++;j=i;}
    }
    return ans;
    
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

     int n;
     cin>>n;
     vector<pair<int,int>>v(n);
     for(int i=0;i<n;i++){
     	cin>>v[i].first>>v[i].second;
     }
     
     cout<<countActivites(v)<<endl;

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}