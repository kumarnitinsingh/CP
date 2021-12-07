// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/reverse-pairs/

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

 int merge(vector<int>& arr,int temp[],int left,int mid,int right)
    {
        int count=0;
        int i = left;
        int j = mid+1;
        int k = left;
        for(i=left;i<=mid;i++){
            while(j<=right and arr[i] > 2LL*arr[j]){
                j++;
            }
            count += (j - (mid+1));
        }
        i = left,j=mid+1;
        while((i <= mid) && (j <= right)){
            if(arr[i] <= arr[j]){
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }

        while(i <= mid)
            temp[k++]=arr[i++];

        while(j <= right)
            temp[k++]=arr[j++];

        for(i = left ; i <= right ; i++)
            arr[i] = temp[i];

        return count;
    }

    int merge_Sort(vector<int>& arr,int temp[],int left,int right)
    {
        int mid,count = 0;
        if(right > left)
        {
            mid = (left + right)/2;

            count += merge_Sort(arr,temp,left,mid);
            count += merge_Sort(arr,temp,mid+1,right);

            count += merge(arr,temp,left,mid,right);
        }
        return count;
    }
   


    int reversePairs(vector<int>& nums) {
         int n = nums.size();
        int temp[n];
        return merge_Sort(nums,temp,0,n-1);
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