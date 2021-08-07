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

pair<double, double> find_Centroid(vector<pair<double, double> >& v)
{
    pair<double, double> ans = { 0, 0 };
      
    int n = v.size();
    double signedArea = 0;
      
    // For all vertices
    for (int i = 0; i < v.size(); i++) {
          
        double x0 = v[i].first, y0 = v[i].second;
        double x1 = v[(i + 1) % n].first, y1 = 
                            v[(i + 1) % n].second;
                              
        // Calculate value of A
        // using shoelace formula
        double A = (x0 * y1) - (x1 * y0);
        signedArea += A;
          
        // Calculating coordinates of
        // centroid of polygon
        ans.first += (x0 + x1) * A;
        ans.second += (y0 + y1) * A;
    }
  
    signedArea *= 0.5;
    ans.first = (ans.first) / (6 * signedArea);
    ans.second = (ans.second) / (6 * signedArea);
  
    return ans;
}

double polygonArea(vector<pair<double,double>>v, int n)
{
   
    double area = 0.0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (v[j].first + v[i].first) * (v[j].second - v[i].second);
        j = i;  
    }
    return abs(area / 2.0);
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
     ll t;cin>>t;
     while(t--){
        ll n,q;
        cin>>n>>q;
        vector<pair<double,double>>v(n);
        loop(i,n)cin>>v[i].first>>v[i].second;
        double ar=polygonArea(v,n);
            pair<double,double> cen=find_Centroid(v);
            cout<<cen.first<<","<<cen.second<<endl;
        while(q--){
            ll v,t;
            cin>>v>>t;
            cout<<ar+<<endl;
            
        }
        //cout<<endl;
     }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}