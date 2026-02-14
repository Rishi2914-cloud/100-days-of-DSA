int maxProfit(int* prices, int pricesSize) 
{
    int minPrice = prices[0];   // minimum price seen so far
    int maxProfit = 0;         // maximum profit

    for(int i = 1; i < pricesSize; i++)
    {
        // If we find a lower price, update minPrice
        if(prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else
        {
            // Calculate today's profit
            int profit = prices[i] - minPrice;

            // Update maxProfit if this is better
            if(profit > maxProfit)
            {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}
