// http://codeforces.com/contest/340/problem/D
// At first this looks like a complicated problem, but it eventually boils down to simple LIS (to be done in nlogn time)
// read the editorial below or at http://codeforces.com/blog/entry/8755 to see how.
// This will also be useful if you want to see aan nlogn implementation of the longest increasing subsequence problem

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli, int> pli;
typedef vector<lli> vli;



int lis(const vi &a)
{
	int n = a.size();

	vi lis_predecessor;	
	for(int x : a)
	{
		auto pos = upper_bound(lis_predecessor.begin(), lis_predecessor.end() , x);
		if(pos == lis_predecessor.end())
			lis_predecessor.push_back(x);
		else
			*pos = x;
	}
	return lis_predecessor.size();
	
}
int main()
{
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<lis(a)<<endl;
}
 
