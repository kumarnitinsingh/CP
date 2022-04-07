#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int n, z;
int a[N];


// Let's denote the points that have greater coordinates in their matched pairs as R-points,
// and the points that have smaller coordinates as L-points.

// Suppose we have an R-point that has smaller coordinate than some L-point.
// Then we can "swap" them, and the answer won't become worse. Also, 
//if some R-point has smaller coordinate than some point that doesn't belong to any pair, or
// some L-point has greater coordinate than some point that doesn't belong to any pair, 
//we can swap them too. So, if the answer is k, we choose k leftmost points as L-points, and
// k rightmost ones as R-points.

// For a fixed value of k, it's easy to see that we should match the leftmost L-point with the leftmost R-point,
// the second L-point with the second R-point, and so on, in order to maximize the minimum distance in a pair. 
//This fact allows us to check whether it is possible to construct at least k pairs, 
//and we can use binary search to compute the answer to the problem

int main()
{
	scanf("%d", &n);
	scanf("%d", &z);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 0;
	int r = n / 2 + 1;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		bool good = true;
		for(int i = 0; i < m; i++)
			good &= (a[n - m + i] - a[i] >= z);
		if(good)
			l = m;
		else
			r = m;
	}
	cout << l << endl;
}



//my approach but don't know why it is not passing some testcases
ll maxPairs(vector<ll> skillLevel, ll minDiff) {
     sort(skillLevel.begin(),skillLevel.end());
     ll ans=0;
     ll n=skillLevel.size();
     

    
    if(minDiff==0 or n==1)return n/2;
     
     vector<bool>paired(n,false);
     ll i=0,j=0;
     j=lower_bound(skillLevel.begin(),skillLevel.end(),skillLevel[0]+minDiff)-skillLevel.begin();
     if(j==n)return 0;
     else ans=1;
    
     paired[i]=true;
     paired[j]=true;
     i++;
     ll k=j+1;
     while(i<n and j<n){
          if(paired[i]){i++;continue;}
            
            if(k==n)break;
          j=lower_bound(skillLevel.begin()+k,skillLevel.end(),skillLevel[i]+minDiff)-skillLevel.begin();
          while(j<n and paired[j]==true)j++;
          
          if(j>=n)break;        
              ans++;
              paired[i]=true;
              paired[j]=true;
             
               i++;
              
               k=j;
              continue;
         
         
          
     }
     return ans;
     
}
