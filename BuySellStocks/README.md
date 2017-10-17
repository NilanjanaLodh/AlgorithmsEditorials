## Problem
Say you have an array for which the ith element is the price of a given stock on day i.<br/>
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
<br/>
**Example**:
If stock prices are {1, 2, 3 , 2 , 6 , 8 , 10 , 5, 8} , the max profit is 13 ( 3-1 +  10-2 + 8-5 ).

## Hints and approach
Let's talk about the relatively straightforward approach first which uses Dynamic Programming.

You can sell multiple stocks, but for the sake of simplicity let's concentrate on the **first** stock that you sell.<br/>
You can sell the first stock at any of the days(d) from day 1(0 indexing) to the last day. <br/>
The profit for that will be  = **(price[d] - min_from_left[d-1])**. 
After that you have the rest of the days from d+1 for the next remaining transactions. <br/>
So the total profit if you sell at day d will be = **profit for that first stock + min_from_here[d+1]**

This approach has a time complexity of **O(n²)** , as there are O(n) states, and each state takes O(n) time.

**Could we reduce it further??**

Here we are going to apply an approach for complexity reduction which comes up quite often in DP problems : Putting an element of greedy to eliminate one of the loops. But before that , we need to analyze the problem carefully, and convince oursleves that greedy would indeed work.

### Greedy Approach :
We buy the first stock and sell just before the price drops. We do this for the rest of the array as well.

For example, if our price array is : 
<br/>1, 2, 3 , 2 , 6 , 8 , 10 , 5, 8

We buy 1 , sell at 3. <br/>
Then buy 2 , sell at 10 <br/>
Buy 5 , sell at 8<br/>

#### Why does this work? (Intuition)

Take a look at this illustration to get a _feel_ for why this works.
<img src='https://i.imgur.com/HfG1HVG.jpg' />
Buy at **i** --> Sell at **j** --> Buy at **k** --> Sell at **l** --> ...



