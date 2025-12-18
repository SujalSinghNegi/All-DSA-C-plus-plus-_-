class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;
        /*
think like you have to buy stocks , so when you buy the stocks, your money get deducted, 
like here, buy1 = max(buy1, -price); so you want max money in the wallet, so will want to buy the stock that have minimum cost to buy ,

after buying you want to sell at max profit, 
so -> sell1 = max(sell1, buy1 - price); // you sell you get the money, 

again same process, now you have remaining sell1 in the wallet, and now you want to max money in the wallet to buy another stock, 
or say you want to buy the minimum stock price, 

buy2 = max(buy2 , sell1 - price); // you are purchasing the stock at current price, 

now you have buy2 in the account and one stock, 

now if you sell it at current price

sell2 = max(sell2, buy2  + price); 

now you have sell2 money, which is the current maximum till now, 

        */
        for (int price : prices) {
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);

        }

        return sell2;
    }
};
