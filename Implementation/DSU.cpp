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


class DSU{
   

     vector<int>parent;
     vector<int>rank;

public:
	 DSU(int n){
	      parent.resize(n);
	      rank.resize(n);

	 	for(int i=0;i<n;i++){
	 		parent[i]=-1;
	 		rank[i]=1;
	 	}
	 }

	 int Find(int x){
	 	if(parent[x]==-1)return x;
	 	return parent[x]=Find(parent[x]);
	 }

	 void Union(int x,int y){
	 	 x=Find(x);
	 	 y=Find(y);
	 	if(x!=y){
	 		if(rank[x]>rank[y]){
	 			parent[y]=x;
	 			rank[x]+=rank[y];}
	 		else{
	 				parent[x]=y;
	 				rank[y]+=rank[x];
	 			}
	 	}
	 }
 
};

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