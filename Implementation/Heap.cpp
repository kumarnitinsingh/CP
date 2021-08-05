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

//UpHeapify adjustment from leaf to root;
void UpHeapify(vector<int> &heap,int i){
if(i==0)return;
int pi=(i-1)/2;
if(heap[pi]<heap[i]){
	swap(heap[pi],heap[i]);
	UpHeapify(heap,pi);
}
else return;

}

//DownHeapify adjustment from root to leaf;
void DownHeapify(vector<int> &heap,int i){
int li=2*i+1;
int ri=2*i+2;
int idx=i;
if(li>=heap.size() and ri>=heap.size())return;
if(li<heap.size() and heap[li]>heap[i])idx=li;
else if(ri<heap.size() and heap[ri]>heap[i])idx=ri;

if(idx==i)return;
swap(heap[i],heap[idx]);
DownHeapify(heap,idx);
}

//creating heap using vector inplace with O(NlogN) approach
void CreateHeap(vector<int> &heap){
	int n;cin>>n;
for(int i=0;i<n;i++){
	int x;
	cin>>x;
	heap.push_back(x);
	UpHeapify(heap,i);

}
}

//deleting highest priority element;
int Delete(vector<int> &heap){
if(heap.size()==0)return -1;
swap(heap[0],heap[heap.size()-1]);
int x=heap[heap.size()-1];
heap.pop_back();
DownHeapify(heap,0);
return x;
}

//optimized heap with O(N) approach;
void BuildHeapOptimized(vector<int>&heap){
for(int i=heap.size()-1;i>=0;i--){
	DownHeapify(heap,i);
}
}


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