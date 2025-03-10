class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
              int n = matrix.size();
            int m = matrix[0].size();
    
        /*
        brute force-> if found any 0 , then mark the row and col with , -1, then after that, iterate each element , which is -1 mark , 0, 
        TC- O(N3)
    
        optimal-> the first row and first col of the matrix, we will consider them as a marker, on iterating each element, if the element is 0 , then 
        mark the , (i,0) to the 0 and (0,j) to the 0,
        and for the first and first row we will check them seperataly initally 
        by two seprate loop. 
    
    
        */
        bool firstR=0, firstC=0;
        for(int i=0; i<n; i++){
            if(matrix[i][0]==0) firstR=1; 
        }
          for(int j=0; j<m; j++){
            if(matrix[0][j]==0) firstC=1; 
        }
    
        // now we can go for each element from 1,n and 1,j
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0]==0|| matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstR) {
         for(int i=0; i<n; i++){
            matrix[i][0]=0;
        }}
           if(firstC) {
         for(int i=0; i<m; i++){
            matrix[0][i]=0;
        }}
    
        }
    };