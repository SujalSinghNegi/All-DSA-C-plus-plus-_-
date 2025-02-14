#include<bits/stdc++.h>
#include "my_stdio.h"
#include "func.h"
int main(){
    int n=5;
    vector<int>arr={2,7,3,4,5};
    string s="abcba";
    int size= s.size();
    vector<int>ds;
    // p(5);
    // printIndex(1,n);
    // printLinearlyfrom1toN(1,n);
    // cout<<endl;
    // printLinearlyfromNto1(n);
    // cout<<endl;
    // print1toN(n-1,n);
    // cout<<endl;
    // printN(n);
    // cout<<endl;
    // cout<<sumOfN(n);
    // cout<<endl;
    // cout<<fact(n);
    // cout<<endl;
    // ReverseArray(arr, n,0);
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<check(s,size,0);
    // printSubSeq(arr, arr.size(),ds, 0 );
    // cout<<endl;
    int cnt=0;
    int k=7;
    // KsumInSS(arr, n, 0, cnt, 0,k );
    // cout<<cnt<<endl;
    //printSSofKsum(arr, n, ds, 0, 0, k);
    // cout<<endl;
   // anySumK(arr, n, ds, 0, 0, k);
   cout<<countKsums(arr, n, 0, 0, k)<<endl;
  // cout<<endl;
   
    return 0;
}