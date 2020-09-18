/*
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std; 


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        it is basically taking every profit that you can get so instead of 
        finding the valleys and the mountains we can just add every consecutive transaction
        which is profitable O(n) time O(1) space. 
        */
        int profit =0 ;
        for(int i=0 ;i<prices.size()-1 ;i++){
            if(prices[i+1] - prices[i] > 0){
                profit += prices[i+1] - prices[i]; 
            }
        }
        
        return profit;
    }
};

/*
Algorithm

Say the given array is:

[7, 1, 5, 3, 6, 4].

If we plot the numbers of the given array on a graph, we get:

If we analyze the graph, we notice that the points of interest are the consecutive valleys and peaks.

Mathematically speaking: Total Profit= \sum_{i}(height(peak_i)-height(valley_i))TotalProfit=∑ 
i
​	
 (height(peak 
i
​	
 )−height(valley 
i
​	
 ))

The key point is we need to consider every peak immediately following a valley to maximize the profit. In case we skip one of the peaks (trying to obtain more profit), we will end up losing the profit over one of the transactions leading to an overall lesser profit.

For example, in the above case, if we skip peak_ipeak 
i
​	
  and valley_jvalley 
j
​	
  trying to obtain more profit by considering points with more difference in heights, the net profit obtained will always be lesser than the one obtained by including them, since CC will always be lesser than A+BA+B.
*/
class Solution {
    public:
     int maxProfit(vector<int>& prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};