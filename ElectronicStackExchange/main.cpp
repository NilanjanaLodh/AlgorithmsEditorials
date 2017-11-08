#include <bits/stdc++.h>

using namespace std;
/**
You work in an electronic exchange. Throughout the day, you receive ticks (trading data) which consists of product name 
and its traded volume of stocks.
Eg: {name: vodafone, volume: 20}.
*You have to tell top k products traded by volume throughout the day
**/

class StackExchange
{
	int k;//how many top elements to keep track of
	map<string,pair<int,bool>> trade_record; //product_name --> <volume_traded , whether_included_in_top_k>
	set<pair<int,string>> top_k; //{(volume, product)}
public:
	StackExchange(int top_el);
	void trade(string &product , int volume);
	vector<string> get_top_traded();
};


StackExchange::StackExchange(int top_el)
{
	k = top_el;
}

void StackExchange::trade(string &product , int volume)
{

	if(trade_record.find(product)!=trade_record.end())
	{
		pair<int, bool> record = trade_record[product];
		trade_record[product].first += volume;
		if(record.second == true)//in top k
		{
			top_k.erase(top_k.find(pair<int,string>(record.first , product)));//erase old value
			top_k.insert(pair<int,string>(record.first + volume , product));// insert new value
			return;
		}
	}
	else
	{
		//no previous record for the product, so create a new entry
		trade_record[product] = pair<int,bool>(volume , false);
	}

	if(top_k.size() == k)
	{
		//make space if reqd
		const pair<int, string> &smallest = *(top_k.begin());
		if(smallest.first < trade_record[product].first)
        {
			trade_record[smallest.second].second = false;
			top_k.erase(top_k.begin());
        }

	}

	if(top_k.size() < k)
	{
	    trade_record[product].second = true;
		top_k.insert(pair<int,string>(trade_record[product].first , product));
	}
}

vector<string> StackExchange::get_top_traded()
{
	vector<string> top_products;
	for(const pair<int,string>&p : top_k)
	{
		top_products.push_back(p.second);
		cout<<p.second<<endl;
	}

	return top_products;
}

int main()
{
	/**
	 * to trade:
	 * T <company name> <volume>
	 *
	 * to get stats on top 4
	 * G
	 */
	StackExchange se(4);
	while(true)
	{
		char type;
		cin>>type;
		switch(type)
		{
			case 'T':
			{
				string product;
				int volume;
				cin>>product>>volume;
				se.trade(product, volume);
				break;
			}
			case 'G':
				se.get_top_traded();
		}
	}
}
