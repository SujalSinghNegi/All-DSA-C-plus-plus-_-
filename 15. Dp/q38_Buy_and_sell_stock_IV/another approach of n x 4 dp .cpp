/*
we can buy or sell,  and we have  k capacity, 
so we can do , k * 2 transaction, 
B S B S B S ...
SO WE take it as a transaction no., 
and instead of two parameters in the recursion, we can pass one param, trans, 
    if(trans % 2 == 0)  {
     //   we have to buy
    }
    else {
      //  we have to sell 
    }

    same block of code are used here, for the logic, and only thing we are doing is, we can just pass, the trans + 1 or trans for performing or not performing transaction,

*/