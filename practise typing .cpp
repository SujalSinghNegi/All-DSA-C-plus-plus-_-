#include <bits/stdc++.h>
using namespace std;

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    for(int qq = 1;  qq<=tt; qq++){
        cout<<"Case #"<<qq<<": ";
        int64_t n, a, b;
        cin>>n>>a>>b;
        vector<int64_t> divs;
        for(int64_t i = 1; i*i <= b; i++){
            if(b%i==0){
                divs.push_back(i);
                if(i*i <b){
                    divs.push_back(b/i);

                }

            }
        }
        sort(divs.begin(), divs.end());
        int sz = int(divs.size());
        const int MAX= 60;
       //----------------------------------------------------







    }
}