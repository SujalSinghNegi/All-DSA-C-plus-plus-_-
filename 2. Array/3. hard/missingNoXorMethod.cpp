class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        // here we xor all the element form the array , and form 1 to n
        
       int n= arr.size();
       int xorAll=0,xorArr=0;
      for(int i=0; i<n; i++){
          xorArr^=arr[i];
          xorAll^=i+1;
      }
     // now the diff bit is this, here diffBit represent the xor of the missing and repeated element
     // because all element is coming twice so they caneled, and repeated no. comes thrice so two of them cancel and one remains,
     // and the missing number only appears once (because it was only present in the 1 to n, not in the array)
     
      int diffBit= xorAll^xorArr;
      
      //here is the we are trying to get most sigificant bit form the right,
      // as the significant bit is on on the one and on another number it is off.
      
    //   int bitNo=0;
    //   while((diffBit&1)==0){
    //       diffBit=diffBit>>1;
    //       bitNo++;
    //   }
    //  int firstOnBitNo=1<<bitNo;
     
     
     // this is more clean way to find the same thing, by the method of 2's compliment
     
        int firstOnBitNo=diffBit & (-diffBit);
      
      // so we can divide the array into two list , one have the missing and one have the repeated element
     // so we xor all the elements in the array and as well in the the 1ton
     
      int bitOn=0, bitOff=0;
      int i=1;
      for(auto it:arr){
          if(it&firstOnBitNo)bitOn^=it;
          else bitOff^=it;
          if(i&firstOnBitNo)bitOn^=i;
          else bitOff^=i;
          i++;
      }
     
      // here we get the missing and repeating number on the bitOn adn bitOff, but we dont know which one is the missing and which one is repating
      int cnt=0;
      for(auto it:arr){
          if(it==bitOn)cnt++;
      }
      // so if the cnt is 0 which menas the bitOn is the missing number
      // we have to return the answer as
      // {repeating, missing}
      if(cnt==0) return {bitOff,bitOn};
      return {bitOn,bitOff};
    }
};