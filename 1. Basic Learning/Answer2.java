import java.util.Scanner;
class Primes{
    int n1,n2;
    int arr[];
    Primes(int n1, int n2){
       arr= new int[n2+1];

    this.n1=n1;
    this.n2=n2;

    for(int i=0; i<n2; i++){
        arr[i]=1;
      }
    arr[0]=0;
    arr[1]=0;
    for(int i=2; i*i<=n2; i++){
        if(arr[i]==1){
            for(int j=i*i; j<=n2; j+=i){
                arr[j]=0;
             }
            }
        }
  } 
    void printPrimes(){
    for(int i=n1; i<=n2; i++){
        if(arr[i]==1){
            System.out.print(i+" ");
        }
    }
    System.out.println();
}
}
class Answer2{
    public static void main(String[] args) {
        // write the the prime number between n1 to n2
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number n1");
        int n1 = s.nextInt();
        System.out.println("Enter the number n2");
        int n2 = s.nextInt();
        Primes p = new Primes(n1,n2);
        p.printPrimes();

    }
}