#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

pair<string, int> process(vector<string>& v)
{
	if (!v.empty())
	{
		return { v.back(),v.back().size() };
	}
	else
	{
		return pair<string, int>();
	}
}
void testPair()
{
	vector<string> v = { "hello","world" };
	pair<string, int> pa = process(v);
	cout << pa.first << pa.second << endl;
	cout << "test for vs git" << endl;
}
int main()
{
	set<int> iset = { 0,1,2,3,4,5 };
	set<int>::iterator set_it = iset.begin();//The two types of iterators of set are read-only
	while (set_it!=iset.end())
	{
		if (*set_it == 3)
		{
			//*set_it = 9; //you cannot assign to a variable that is const
			cout << "you cannot assign to a variable that is const" << endl;
		}
		cout << *set_it << endl;
		++set_it;
	}


	return 0;
}