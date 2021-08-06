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

class Graph{
	int V;
	list<int>*l;
public:
	Graph(int v){
		V=v;
		l=new list<int>[V];
	}
	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir)l[j].push_back(i);
	}
	void display(){
		for(int i=0;i<V;i++){
			cout<<i<<"-->";
			for(auto x:l[i]){
				cout<<x<<",";
		}
			cout<<endl;
			}
	}

	void bfs(int source){
		queue<int>q;
		bool* visited=new bool[V]{0};
		q.push(source);
		visited[source]=true;
		while(!q.empty()){
			int f=q.front();
			cout<<f<<endl;
			q.pop();
			for(auto x:l[f]){
				if(!visited[x]){
					q.push(x);
					visited[x]=true;
				}	
			}
		}
	}		

	void shortestPath(int source){
		queue<int>q;
		bool* visited=new bool[V]{0};
		int * dist=new int[V]{0};
		int *parent=new int[V];
		for(int i=0;i<V;i++)parent[i]=-1;
			dist[source]=0;
		    parent[source]=source;
		q.push(source);
		visited[source]=true;
		while(!q.empty()){
			int f=q.front();
			cout<<f<<endl;
			q.pop();
			for(auto x:l[f]){
				if(!visited[x]){
					q.push(x);
					dist[x]=dist[f]+1;
					parent[x]=f;
					visited[x]=true;
				}	
			}
		}
		for(int i=0;i<V;i++){
		  cout<<"distance of "<<i<<" is "<<dist[i]<<endl;
		}
	}

	void shortestPathToDestination(int source,int dest=-1){
		queue<int>q;
		bool* visited=new bool[V]{0};
		int * dist=new int[V]{0};
		int *parent=new int[V];
		for(int i=0;i<V;i++)parent[i]=-1;
			dist[source]=0;
		    parent[source]=source;
		q.push(source);
		visited[source]=true;
		while(!q.empty()){
			int f=q.front();
			cout<<f<<endl;
			q.pop();
			for(auto x:l[f]){
				if(!visited[x]){
					q.push(x);
					dist[x]=dist[f]+1;
					parent[x]=f;
					visited[x]=true;
				}	
			}
		}
		if(dest!=-1){
			int temp=dest;
			while(temp!=source){
				cout<<temp<<"-->";
				temp=parent[temp];
			}
			cout<<source<<endl;
		}

	}	


	void dfsHelper(int node,int* visited){
		visited[node]=true;
		cout<<node<<" ";
		for(auto nbrs:l[node]){
			if(!visited[nbrs])dfsHelper(nbrs,visited);
		}
	}	

	void dfs(int source){
		int * visited=new int[V]{0};
		dfsHelper(source,visited);
	}

	int dijkstra(int source ,int dest){
		vector<int>distance(V,INT_MAX);
		set<pair<int,int>>s;
		distance[source]=0;
		s.insert({0,source});
		while(!s.empty()){
			auto it=s.begin();
			int node=it->second;
			int distanceTillNow=it->first;
			s.erase(it);

			  for(auto nbrs:l[node]){
			  		int n=nbrs->second;
			  		int edge=nbrs->first;
			  	 if(edge+distanceTillNow<distance[n]){
			  	 	auto f=s.find({distance[n],n});

			  	 	 if(f!=s.end()){
			  	 	 	s.erase(f);
			  	 	 }
			  	 	 distance[n]=edge+distanceTillNow;
			  	 	 s.insert({distance[n],n});


			  	 }
			  }

		}
		return distance[dest];
	}
};


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     Graph g(6);
     g.addEdge(0,1);
     g.addEdge(0,4);
     g.addEdge(2,1);
     g.addEdge(3,4);
     g.addEdge(4,5);
     g.addEdge(2,3);
     g.addEdge(3,5);

     g.dfs(1);


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}