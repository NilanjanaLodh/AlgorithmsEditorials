#include <bits/stdc++.h>
using namespace std;

/**
 * http://codeforces.com/problemset/problem/607/B
 * c1 c2 c3 c4 ... cn
 *
 * Chose a substring that's a palindrome and remove it
 * Repeat until the entire string has been "destroyed"
 *
 * Output: the minimum number of removals you need to do destroy the string completely
 * Example :  for 1 4 5 6 2 2 2 6 4 5 1, we need two removals.
 * Range : n<500
 *
 * Hint : focus on the left most character. What are the possible ways to destroy it??
 */
int min_destroy_time(const vector<int>&a)
{
	int n = a.size();
	vector<vector<int>> destroy_time(n+1,vector<int>(n+1,0));
	
	for(int len=1;len<=n;len++)
	{
		for(int i=0;(i+len)<=n;i++)//this is the starting index
		{
			int j = i+len-1; //this is the ending index
			
			//initialize to the case where you destroy the leftmost one individually			
			int mintime = 1 + destroy_time[i+1][j];
			
			/**
			 * Now iterate over all the other cases where you match with a right element
			 */
			for(int k=i+1;k<=j;k++)
			{
				if(a[k]==a[i])
				{
					int time_req = destroy_time[i+1][k-1] + destroy_time[k+1][j];	
					
					//you can't remove it along with some inner substring, because the inner substring is empty!	
					if((k-i) == 1) 
						time_req++;
					
					mintime = min(mintime, time_req);
				}
			}
			destroy_time[i][j] = mintime;
		}
		
	}
	
	return destroy_time[0][n-1];
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<min_destroy_time(a)<<endl;
	
	return 0;
}

/*
 *  ******Complete Approach*********
 * 
 * Intuition:
 * 
 *-  We need to successively remove palindromic substrings from the string, right!
 *-  We can remove **any** palindromic substring, in any order
 *-  After removing the substring, we need to operate on the leftover string formed from the left + right
 *-  Keeping track of both the left and right parts after removing the substring is not easy
 *-  We need something easier : 
 *-  So lets focus on the left most substring (i.e the substring containing the left most character) to remove.
 *		- Why? Because doing this eliminates the left part after removing the substring:
 *		- The left part will always be empty, so our problem becomes easier
 *		- That is, after removing the leftmost substring, we are only left with the string to its right.
 *-  Okay, so now,what are all the possible ways in which we can remove the left character?
 *-  It can either be removed individually 	like c1  |  c2 c3 c4 c5 c6 .. cn
 *-  Or it can be paired up with a matching chracter to its right
 *           Let our string be
 *           0 1 2 3 4 5 6 7 8 <<indices
 *           1 x x x x 1 x 1 x
 *    So index 0 can be removed either on its own(case1) : in that case we have to deal with [1,8]
 *    or it can be removed along with index 5 or 7
 *    	- index 5 case : [1,4] + [6,8]
 *    	- index 7 case : [1,6] + [8,8]
 *
 *
 *
 * Formalization
 * Take a look at 
 * http://codeforces.com/predownloaded/d2/66/d26630b29782e070f335ec9d30c6af454c57a2cb.png
 */
