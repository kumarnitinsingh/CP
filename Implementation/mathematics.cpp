// Created by Nitin
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
