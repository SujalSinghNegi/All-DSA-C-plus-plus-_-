
//N queens
// this problem is that give the all posible combo of that at which position where the queen can be placed
// so solve startin by , row 0,1,2....n-1 , as each each row, col, left dia , right dia, can have max one queen, 
// so , try by each row index, form j =0 to n-1, and when the safe box is there ,then again call the backtrack , for next row+1, and start form 0 index to n-1
// we can detect the safe box, if that row dont have any prev queen, so this condition will never arrived, because
// when we are marking the some row index, then we are going to the another row, and when that call is over we unmark the row index
// now the second is col, so we have colmap, if any col is marked, that is j, any index of j is marked earlier, then we cant place the queen at that j, 
//  for right to left diagonal we see the they have all have equal sum of row+col , so if we are marking any row index, then mark their sum , and when return , then unmark
//  for left to right diagonal we see the diffrence property , they all have equal diff, so when we are makring any row index, then we also mark the row - j , index , and unmark when return
//  and the when the row reaches the end, row==n, then push it to the answer

class Solution {
    public:
        void backtrack(int row,  vector<vector<int>>&ans, vector<int>&ds,int n,unordered_map<int,int>&colmap,unordered_map<int,int>&summap,unordered_map<int,int>&diffmap ){
            if(row ==n){
                ans.push_back(ds);
                return;
            }
            for(int j=0; j<n; j++){
                if(!(colmap[j] || summap[row+j] || diffmap[row-j] )){
                    colmap[j]=1;
                    summap[row+j]=1;
                    diffmap[row-j]=1;
                    ds.push_back(j+1);
                    backtrack(row+1, ans, ds, n, colmap, summap, diffmap);
                    colmap[j]=0;
                    summap[row+j]=0;
                    diffmap[row-j]=0;
                ds.pop_back();
                }
                    
            }
        }
      vector<vector<int>> nQueen(int n) {
          // code here
          vector<vector<int>>ans;
          vector<int>ds;
         unordered_map<int,int>colmap, summap, diffmap;
          backtrack(0, ans, ds, n, colmap, summap, diffmap);
          return ans;
      }
  };
