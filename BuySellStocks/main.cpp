//C++14
#include <bits/stdc++.h>

using namespace std;
/**
 * Calculate the maximum profit you can gather by buying and selling stocks, the proce array given
 * You can hold only one stock at a time. You can do only a single transaction per day
 * I.e . the sequence will be like buy--> sell --> buy --> sell
 * 
 * https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii
 */
int max_profit(const vector<int> &A) 
{
    int n = A.size();
    if(n==0)
        return 0;
        
    int total_profit = 0;
    
    int buy = A[0];
    
    for(int i=1;i<n;i++)
    {
        if(A[i]<=A[i-1])
        {
            total_profit += A[i-1] - buy;
            buy = A[i];
        }
    }
    
    int last_profit = A[n-1] - buy;
    if(last_profit>0)
        total_profit += last_profit;
   
   return total_profit;
}

int main()
{
	cout<<max_profit({1, 2, 3 , 2 , 6 , 8 , 10 , 5, 8})<<endl;
}
