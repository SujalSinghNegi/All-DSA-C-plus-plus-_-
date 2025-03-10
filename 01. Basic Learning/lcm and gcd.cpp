int gcd1(int a,int b){
        return (b==0) ? a : gcd1(b,a%b);
    }
   
    int lcm1(int a,int b){
        return (a/gcd1(a,b)*b);
    }
    
    vector<int> lcmAndGcd(int a, int b) {
        return {lcm1(a,b),gcd1(a,b)};
    }