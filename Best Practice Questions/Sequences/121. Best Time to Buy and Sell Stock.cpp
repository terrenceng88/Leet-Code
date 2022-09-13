/*
-----QUESTION-----
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

//Runs in O(n) time 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        //brute force method
        int max  = 0;
        
        for(int i = 0; i < prices.size() - 1; i++) { //skips last one because its the buy day
            for(int j = i + 1; j < prices.size(); j++) { //starts the day after the buy day because its the sell day
                if(prices[j] - prices[i] > max) {
                    max = prices[j]-prices[i];
                    //cout << "j = " << prices[j] << " i = " << prices[i] << " max = " << max << endl ; //for testing
                }
            }
        }
        return max;
        */
        
        
        //efficient method
        int least = INT_MAX; //smallest buy price seen so far
        int profit = 0; //current profit
        int possible = 0; //possible profit with the smallest buy price seen so far
        
        for(int i = 0; i < prices.size(); i++) { //skips last one because its the buy day
            if(prices[i] < least) { //find smallest price possible
                least = prices[i];
            }
            
            possible = prices[i] - least; //calculate possibe profit using the smallest price found so far and the current price
            
            if(possible > profit) { //if the possible profit using the smallest price found so far is bigger than the current biggest profit
                profit = possible; //set it as the current biggest profit
            }
        }
        
        return profit;
        
        
    }
};