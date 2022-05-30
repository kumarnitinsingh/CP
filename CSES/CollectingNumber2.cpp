// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/2217/

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
#define vecl            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x
#define endl           "\n"


void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    #endif
}


/*

//prime checking
//------------------------------------------------------------------
bool isPrime(long x){
  if(x<=1)return false;
  for(int i=2;i*i<=x;i++){
    if(x%i==0)return false;
  }
  return true;
}


//---------------------------------------------------------------------
vector<long>v(1000000);
vector<long>primes;

void Prime(long n){
  v[0]=v[1]=0;
  for(long i=2;i<=n;i++)v[i]=1;

    for(long i=2;i<=n;i++){
      if(v[i]){
        for(long j=i*i;j<=n;j+=i){
          v[j]=0;
        }
      }
    }

    for(long i=2;i<=n;i++){
           if(v[i])primes.push_back(i);
    }
}

//---------------------------------------------------------------------------

 long FastModulo(long x,long p,long m){
   long ans=1;
  while(p>0){
    if(p&1){
      ans=((ans%m)*(x%m))%m;

    }
    x=((x%m)*(x%m))%m;
    p=p>>1;
  }
  return ans;
 }

 //------------------------------------------------------------------------------

 long GCD(long a,long b){
 if(b==0)return a;

  return GCD(b,a%b);

 }

//---------------------------------------------------------------------------------

 long LCM(long a, long b){

 return (a*b)/GCD(a,b);
 }

//--------------------------------------------------------------------------------

    long x;
    long y;
    long gcd;

void ExtendedEuclideanAlgorithm(long a,long b){

if(b==0){
    x=1;
    y=0;
    gcd=a;return;
}
 ExtendedEuclideanAlgorithm( b,a%b);
long cx=y;
long cy=x-(a/b)*y;
x=cx;
y=cy;

}
//-----------------------------------------------------------------------------------

long InverseModulo(long a,long m){
ExtendedEuclideanAlgorithm(a,m);
return x;
}

//-----------------------------------------------------------------------------------

long ChineseRemainderTheorem(vector<long> nums,vector<long> rem){
  long ans=0;

long product=1;

for(int i=0;i<nums.size();i++){
  product*=nums[i];
}

for(int i=0;i<nums.size();i++){
  ans+=(rem[i]*(product/nums[i])*InverseModulo(product/nums[i],nums[i]))%product;
}

return ans+product;
}


*/










int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

        ll n,q;
        cin>>n>>q;
        vector<ll>v(n),pos(n+1,INT_MAX);
        
        loop(i,n)cin>>v[i];
        loop(i,n)pos[v[i]]=i;

       
        int cn=0;

        for(int i=1;i<=n;i++){
           if(pos[i]<pos[i-1])cn++;
        }

         while(q--){
            int x,y;
            cin>>x>>y;
            x--;y--;
            set<pair<int,int>>affected;
            if(v[x]>1){
                affected.insert({v[x]-1,v[x]});


            }
            if(v[x]<n){
                affected.insert({v[x],v[x]+1});
            }
             if(v[y]>1){
                affected.insert({v[y]-1,v[y]});


            }
            if(v[y]<n){
                affected.insert({v[y],v[y]+1});
            }

            for(auto af:affected){
                if(pos[af.first]>pos[af.second])cn--;
            }

            swap(v[x],v[y]);
            swap(pos[v[x]],pos[v[y]]);

              for(auto af:affected){
                if(pos[af.first]>pos[af.second])cn++;
            }
            cout<<cn<<endl;

         }





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}