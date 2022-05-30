// Created by Nitin kumar singh
// problem link ->  https://leetcode.com/problems/course-schedule/

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



bool DfsCycleDetectionInDirectedGraph(int source,int V,vector<bool>&visited, vector<int>l[], vector<bool>&Stack){
   
    visited[source]=true;
     Stack[source]=true;
    for(auto nbr:l[source]){
    	if(!visited[nbr]){
    		bool isTrue=DfsCycleDetectionInDirectedGraph(nbr,V,visited,l,Stack);
    		if(isTrue)return true;
    	}
    	else if(Stack[nbr])return true;
    }
    Stack[source]=false;
    return false;

}


bool contains_cycle_in_directed_graph(int source,int V,vector<int>l[]){
	vector<bool>visited(V,false),Stack(V,false);
	return DfsCycleDetectionInDirectedGraph(source,V,visited,l,Stack);
}



    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>graph[numCourses];
         for(int i=0;i<prerequisites.size();i++){
             graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
         }
      
        for(int i=0;i<numCourses;i++){ 
         bool temp=contains_cycle_in_directed_graph(i,numCourses,graph);
                   if(temp==true)return false;                     
         }
        return true;
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
}t