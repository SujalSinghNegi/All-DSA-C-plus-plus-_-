class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        if(n == 0) return 0;
        // we have to move n disk from From to To.. 
        // for that we have to move n - 1 disk from From to the Aux
        
        // so that we can move 1 disk from From to the TO.
        
      //  it says move the n - 1 disk From - Aux
      
        int a =  towerOfHanoi(n-1, from , aux, to);
      // we have one disk in From.. now move it to the TO
      // cout<< move disk From -> TO
        // we have n - 1 disk in the AUX.
        // move those n - 1 disk in the AUX to the TO using from as an auxillary
        
        int b = towerOfHanoi(n-1, aux, to, from);
        return a + b + 1;
    }
};