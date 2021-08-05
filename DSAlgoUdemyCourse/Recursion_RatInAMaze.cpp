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

    void ratInmaze(vector<vector<char>>&grid,int i,int j,int n,vector<vector<int>>&visited){
            if(i==n-1 and j==n-1){
                for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<visited[i][j]<<" ";
            }cout<<endl;
        }

            return;}
        if(i==n ||j==n)return;
         visited[i][j]=1;
       
        if(grid[i][j+1]=='O' and i<n and j<n and visited[i][j+1]==0){
        ratInmaze(grid,i,j+1,n,visited);}
         if(grid[i+1][j]=='O' and i<n and j<n and visited[i+1][j]==0){
        ratInmaze(grid,i+1,j,n,visited);}

        visited[i][j]=0;


    }

    vector<int> findPath(int n, vector<vector<char>> c){
        vector<int>ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        ratInmaze(c,0,0,n,visited);
        int numbers=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==1)ans.pb(numbers);
                cout<<visited[i][j]<<" ";
                numbers++;
            }
            cout<<endl;
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
        cout<<"hello";
        vector<vector<char>>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }
         
                for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<v[i][j]<<" ";
            }cout<<endl;
        }


       // vector<int> ans=findPath(n,v);

        // loop(i,ans.size())cout<<ans[i]<<" ";




       
        #ifndef  ONLINE_JUDGE
         clock_t end=clock();
        cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
        #endif
       return 0;
    }