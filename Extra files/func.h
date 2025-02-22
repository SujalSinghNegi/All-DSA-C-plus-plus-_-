#ifndef FUNC_H
#define FUNC_H


#include<bits/stdc++.h>
using namespace std;

void printA(vector<int>&arr){
    int n= arr.size();
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printA(vector<int>&arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void p(int n){
    if(n==0) return;
    cout<<"hello"<<endl;
    p(--n);
}
void printIndex(int i, int n){
    cout<<"sujal"<<endl;
    if(i>=n)return;
    printIndex(i+1, n);
}
void printLinearlyfrom1toN(int i, int n){
    cout<<i<<" ";
    if(i>=n)return;
    printLinearlyfrom1toN(i+1, n);
}
void printLinearlyfromNto1(int n){
    cout<<n--<<" ";
    if(n<=0)return;
    printLinearlyfromNto1(n);


}
void print1toN(int i, int n){
    cout<<n - i--<<" ";
    if(i==-1)return;
    print1toN(i,n);
}
void printN(int n){
    if(n<=0) return;
    printN(n-1);
    cout<<n<<" ";
}

int sumOfN(int n){
    if(n<=0) return 0;
   return n+sumOfN(n-1);
}
int fact(int n){
    if(n==0) return 1;
    return n* fact(n-1);
}
void ReverseArray(vector<int>&arr, int n, int i){
    if(i<=n/2) return;
    swap(arr[i], arr[n-i-1]);
    ReverseArray(arr, n, i-1);
}
bool check(string s, int n , int i){
    if(i>=2) return 1;
    return s[i]==s[n-i-1] & check(s,  n, i+1);
}
void printSubSeq(vector<int>arr, int n ,vector<int>&ds, int ind){
    if(ind==n){
        for(int i=0; i<ds.size(); i++){
            cout<<ds[i]<<" ";
        }
        cout<<endl;
        return;
       
    }
    ds.push_back(arr[ind]);
    printSubSeq(arr, n, ds, ind+1);
    ds.pop_back();
    printSubSeq(arr, n, ds, ind+1);

}
// count the subsequence with sum of K
void KsumInSS(vector<int>&arr, int n , int ind, int &cnt, int sum, int k){
    if(ind ==n){
        if(sum==k) cnt++;
        return;
    }
    if(sum==k){
        cnt++;
        return;
    }
    KsumInSS(arr, n, ind+1, cnt, sum+arr[ind], k);
    KsumInSS(arr, n ,ind+1, cnt, sum, k);

}
// count the subsequence with sum of K
int countKsums(vector<int>&arr, int n , int ind, int sum, int k){
    if(ind ==n){
        if(sum==k) return 1;
        else return 0;
    }
    if(sum==k){
        return 1;
    }
    int l= countKsums(arr, n, ind+1, sum+arr[ind], k);
    int r= countKsums(arr, n ,ind+1, sum, k);

    return l+r;
}

// print all sequence of sum k
void printSSofKsum(vector<int>&arr, int n , vector<int>&ds, int ind, int sum, int k){
    if(ind == n){
        if(sum==k){
            printA(ds);
        }
        return;
    }
    if(sum==k){
        printA(ds);
        return;
    }
    ds.push_back(arr[ind]);
    printSSofKsum(arr, n, ds, ind+1,sum+arr[ind], k);
    ds.pop_back();
    printSSofKsum(arr, n, ds, ind+1,sum, k);
    
}
 // Ksum all sequence , and one number can be used any number of times
 void allKsum(vector<int>& candidates, int n, int target,vector<int>&ds, int ind, vector<vector<int>>&ans){
    if(ind==n){
        if(0==target){
            ans.push_back(ds);
        }
         return;
    }
    if(candidates[ind]<= target){
       ds.push_back(candidates[ind]);
       allKsum(candidates, n, target-candidates[ind], ds, ind, ans);
          ds.pop_back();
    }
 
    allKsum(candidates, n, target, ds, ind+1, ans);

}
// any sequence that sum k 
bool anySumK(vector<int>&arr, int n , vector<int>&ds, int ind, int sum, int k){
    if(ind == n){
        if(sum==k){printA(ds);
        return 1;
    }
    return 0;
    }
    if(sum==k){
        printA(ds);
        return 1;
    }
    ds.push_back(arr[ind]);
   
    if(anySumK(arr, n, ds, ind+1,sum+arr[ind], k)) return 1;
    ds.pop_back();
   
    if(anySumK(arr, n, ds, ind+1,sum, k)) return 1;
    return 0;
}

#endif