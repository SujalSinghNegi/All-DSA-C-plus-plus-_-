// moore's voting algorithm
class Solution {
    public:
        vector<int> majorityElement(vector<int>& arr) {
            int cnt1= 0, cnt2=0, ele1= INT_MIN, ele2= INT_MIN;
            int n= arr.size();
            vector<int>ans;
            for(int i=0; i<n; i++){ 
                if(cnt1==0 && arr[i]!= ele2){
                    ele1= arr[i];
                    cnt1=1;
                }
                else if(cnt2==0 && arr[i]!= ele1){
                    ele2=arr[i];
                    cnt2=1;
                }
                else if(arr[i]==ele1) cnt1++;
                else if(arr[i]==ele2) cnt2++;
                else{
                    cnt1--;
                    cnt2--; 
                }
    
            }
            cnt1=cnt2=0;
            for(int i=0; i<n; i++){
                if(arr[i]==ele1)cnt1++;
                if(arr[i]==ele2)cnt2++;
            }
            
            if(cnt1 >= n/3 +1)ans.push_back(ele1);
            if(cnt2 >= n/3 +1)ans.push_back(ele2);
            return ans;
        }
    };