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

class graph{
public:
int V;
list<pair<int,int>> *l;
public:
	graph(int v){
		V=v;
		l=new list<pair<int,int>>[V];
	}

	void addEdge(int u,int v,int wt,bool undir=true){
		l[u].push_back({wt,v});
		if(undir)l[v].push_back({wt,u});
	}


void bfs(int source){
	queue<int>q;
	vector<bool>visited(V,false);
	q.push(source);
	visited[source]=true;
	while(!q.empty()){
		int v=q.front();q.pop();
		cout<<v<<" ";
		for(auto nbr:l[v]){
			if(!visited[nbr]){
				q.push(nbr);
				visited[nbr]=true;
			}
		}
	}
}

void dfsHelper(int source ,vector<bool>&visited){

	cout<<source<<" ";
	visited[source]=true;
	for(auto nbr:l[source]){
		if(!visited[nbr])dfsHelper(nbr,visited);
	}
}
void dfs(int source){
	vector<bool>visited(V,false);
	dfsHelper(source,visited);
}

int ShortestPathInUndirectedGraph(int source,int dest){
	vector<int>dist(V,0);
	vector<int>parent(V,-1);
	vector<bool>visited(V,false);
	queue<int>q;
	  dist[source]=0;
	  q.push(source);
	  parent[source]=0;
	  while(!q.empty()){
	  	int v=q.front();q.pop();
	  	for(auto nbr:l[v]){
	  		if(!visited[nbr]){
	  			dist[nbr]=dist[v]+1;
	  			visited[nbr]=true;
	  			q.push(nbr);
	  		}
	  	}
	  }
 
 return dist[dest];
}



bool DfsCycleDetection(int source,int parent,vector<bool>&visited){
	visited[source]=true;
	for(auto nbr:l[source]){
		if(!visited[nbr]){
			bool isTrue=DfsCycleDetection(nbr,source,visited);
			if(isTrue)return true;
		}
		else if(parent!=nbr)return true;
	}
	return false;
}




bool contains_cycle_in_Undirected_Grap(int source){
	vector<bool>visited(V,false);
	int parent=-1;
	return DfsCycleDetection(source,parent,visited);
}




bool DfsCycleDetectionInDirectedGraph(int source,vector<bool>&visited){
    static vector<bool>Stack(V,false);
    visited[source]=true;
     Stack[source]=true;
    for(auto nbr:l[source]){
    	if(!visited[nbr]){
    		bool isTrue=DfsCycleDetectionInDirectedGraph(nbr,visited);
    		if(isTrue)return true;
    	}
    	else if(Stack[nbr])return true;
    }
    Stack[source]=false;
    return false;

}




bool contains_cycle_in_directed_graph(int source){
	vector<bool>visited(V,false);
	return DfsCycleDetectionInDirectedGraph(source,visited);
}



void shortestPath_in_undirected_Graph(int source,int dest){
	vector<bool>visited(V,false);
	vector<int>parent(V,-1);
	queue<int>q;
	 visited[source]=true;
	 q.push(source);
	 parent[source]=source;
	 while(!q.empty()){
	 	int v=q.front();q.pop();
	 	for(auto nbr:l[v]){
	 		if(!visited[nbr]){
	 			parent[nbr]=v;
	 			visited[nbr]=true;
	 			q.push(nbr);
	 		}
	 	}
	 }

	 int temp=dest;
	 while(temp!=source){
	 	cout<<temp<<"->";
	 	temp=parent[temp];
	 }
	 cout<<temp;
}


vector<int> DijkstraAllPairShortestPath(int source){
	vector<int>dist(V,INT_MAX);

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	 dist[source]=0;
	 pq.push({0,source});
	 while(!pq.empty()){
	 	int u=pq.top().second;
	 	pq.pop();
	 	for(auto nbr:l[u]){
	 		int v=nbr.second;
	 		int wt=nbr.first;
	 		if(dist[v]>dist[u]+wt){
	 			dist[v]=dist[u]+wt;
	 			pq.push({dist[v],v});
	 		}
	 	}
	 }
	 return dist;
}

void toplogicalSort(int start){
	vector<int>res;
	vector<int>indegree(V,0);
	for(int i=1;i<V;i++){
		for(auto x:l[i]){
			indegree[x]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=V;i++){
		if(indegree[i]==0)q.push(i);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		res.push_back(u);
		for(auto nbr:l[u]){
			indegree[nbr]--;
			if(indegree[nbr]==0)q.push(nbr);
		}
	}
if(res.size()!=V-1){cout<<"toplogicalSort not exist because cycle detected";}
else {
	for(auto x:res)cout<<x<<",";
}

}

void toplogicalSortusingDfs(int start,vector<int>&res){
	static vector<bool>visited(V,false);

	visited[start]=true;
	for(auto nbr:l[start]){
		if(!visited[nbr])toplogicalSortusingDfs(nbr,res);
	}
	res.push_back(start);
}

void BellmanfordAlgorithForSingleSourceShortestPathWithNegativeWeight(int start){
	vector<int>dist(V,INT_MAX);
	dist[start]=0;
	vector<tuple<int,int,int>>edgelist;
	for(int i=1;i<V;i++){
		for(auto p:l[i]){
			edgelist.push_back({i,p.second,p.first});
		}
	}

	for(auto edge:edgelist){
		int u=get<0>(edge);
		int v=get<1>(edge);
		int wt=get<2>(edge);
		if(dist[v]>dist[u]+wt){
			dist[v]=dist[u]+wt;
		}
	}

	for(auto edge:edgelist){
		int u=get<0>(edge);
		int v=get<1>(edge);
		int wt=get<2>(edge);
		if(dist[v]>dist[u]+wt){
			cout<<"Shortest path not possible from "<<u<<" to "<<v<<endl;
			break;
		}
	}

	for(int i=1;i<V;i++){
		cout<<"distance from "<<start<<" to "<<i<<" is "<<dist[i]<<endl;
	}

}

void FloydWarshallAlgorithAllPairShortestPath(){
	vector<vector<int>>dist(V,vector<int>(V,INT_MAX));
	for(int i=1;i<V;i++){
		for(auto p:l[i]){
			dist[i][p.second]=p.first;
		}
	}

	for(int i=1;i<V;i++){
		dist[i][i]=0;
	}
	for(int k=1;k<V;k++){
		for(int i=1;i<V;i++){
			for(int j=1;j<V;j++){
				if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}

		}
	}


	for(auto i=1;i<V;i++){
		for(int j=1;j<V;j++){
			cout<<"distance of " <<j<<" from "<<i <<" is "<<dist[i][j]<<endl;
		}
		cout<<endl<<endl;
	}
}



void make_set(vector<int>&v){
for(int i=1;i<V;i++){
	v[i]=i;
}

}
int Find(int x,vector<int>&v){
    
    if(x!=v[x]){
        v[x]=Find(v[x],v);
    }
return v[x];
}

void union_set(int x,int y,vector<int>&v,vector<int>&rank){
       int rootX=Find(x,v);
       int rootY=Find(y,v);
       if(rootX==rootY)return;
       if(rank[rootX]>rank[rootY])v[rootY]=rootX;
       else{
           v[rootX]=rootY;
                if(rank[rootX]==rank[rootY])rank[rootY]++;

                  }

}
class mycom{
 public:
 	bool operator()(vector<int>v1,vector<int>v2){
 		return v1[0]>v2[0];
 	}
};

void kruskalsAlgorithmForMST(){
	vector<int>parent(V);
	make_set(parent);
    vector<int>rank(V,0);
	vector<tuple<int,int,int>>edgelist;
	priority_queue<vector<int>,vector<vector<int>>,mycom>pq;
	for(int i=1;i<V;i++){
		for(auto p:l[i]){
			pq.push({p.first,i,p.second});
		}
	}

	while(!pq.empty()){
         vector<int> temp=pq.top();
         pq.pop();
         int u=temp[1];
         int v=temp[2];
         int wt=temp[0];

         if(Find(u,parent)!=Find(v,parent)){
         	edgelist.push_back({u,v,wt});
         	union_set(u,v,parent,rank);
         }
	}


int minWt=0;

for(int i=0;i<edgelist.size() ;i++){
	cout<<get<0>(edgelist[i])<<"->"<<get<1>(edgelist[i])<<" with weight "<<get<2>(edgelist[i])<<endl;
    minWt+=get<2>(edgelist[i]);
}

cout<<"minimum wt = "<<minWt<<endl;

}



 
};




int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
      	int v=9;
      graph g(v);
      g.addEdge(1,2,1);
      g.addEdge(1,3,6);
      g.addEdge(2,4,2);
      
      g.addEdge(2,5,1);

      g.addEdge(3,5,3);
      g.addEdge(3,6,2);
      g.addEdge(5,4,1);
      g.addEdge(4,7,2);
      g.addEdge(5,7,1);
      g.addEdge(2,8,3);  

      // g.addEdge(1,2,false);
      // g.addEdge(2,3,false);
      // g.addEdge(3,4,false);
      // g.addEdge(1,4,false);
      // g.addEdge(4,5,false);
       g.kruskalsAlgorithmForMST();




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}