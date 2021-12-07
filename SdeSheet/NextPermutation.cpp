// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/next-permutation/

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

void rev(vector<int>& s, int l, int r)
{
    while (l < r)
        swap(s[l++], s[r--]);
}
int bsearch(vector<int>& s, int l, int r, int key)
{
    int index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (s[mid] <= key)
            r = mid - 1;
        else {
            l = mid + 1;
            if (index == -1 || s[index] >= s[mid])
                index = mid;
        }
    }
    return index;
}

    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-2;
        int len=j+2;
        int last=nums[nums.size()-1];
         while(j>=0 and nums[j]>=nums[j+1])j--;
        if(j<0)sort(nums.begin(),nums.end());
        if(j>=0){
            int temp=bsearch(nums,j+1,len-1,nums[j]);
            //temp+=1;
            swap(nums[j],nums[temp]);
            rev(nums, j + 1, len - 1);
            
        }
    }
//     1) An sequence sorted in descending order does not have next permutation. For example edcba” does not have next permutation.
// 2) For a sequence which is not sorted in descending order for example “abedc”, we can follow below steps.
// ……….a) Traverse from right and find the first item that is not following the descending order. For example in “abedc”, the character ‘b’ does not follow the descending order.
// ……….b) Swap the found character with closest greater (or smallest greater) element on right side of it. In case of “abedc”, we have ‘c’ as the closest greater element. After swapping ‘b’ and ‘c’, string becomes “acedb”.
// ……….c) After swapping, sort the string after the position of character found in step a. After sorting the substring “edb” of “acedb”, we get “acbde” which is the required next permutation.

// Optimizations in step b) and c)
// a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element.
// c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), we can get the sequence sorted (in increasing order) after reversing it.

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