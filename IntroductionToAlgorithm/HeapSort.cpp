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

void heapify(vector<ll> &v,ll i,ll n){
	ll left=2*i;
	ll right=2*i+1;
	ll largest =i;
	if(left<n and v[left]>v[largest]){
		largest=left;
	}
	if(right<n and v[right]>v[largest]){
		largest=right;
	}
	if(largest!=i){
		swap(v[i],v[largest]);
		heapify(v,largest,n);
	}
}

void BuildHeap(vector<ll> &v){
	ll n=v.size();
	for(int i=v.size()/2;i>=1;i--){
		heapify(v,i,n);
	}
}

void HeapSort(vector<ll> &v){
	BuildHeap(v);
    ll n=v.size()-1;
	for(int i=v.size()-1;i>=2;i--){
		swap(v[1],v[i]);
		n--;
		heapify(v,1,n);
	}
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

    ll n;
    cin>>n;
    vector<ll>v(n+1);
    v[0]=0;
    for(int i=1;i<=n;i++)cin>>v[i];

    	BuildHeap(v);

       for(int i=1;i<=n;i++){
       	   cout<<v[i]<<" ";
       }
       cout<<endl;
       HeapSort(v);
       for(int i=1;i<=n;i++){
       	cout<<v[i]<<" ";
       }
       cout<<endl;



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}