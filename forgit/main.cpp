#include <iostream>
#include <vector>
#include <utility>

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
int main()
{

	vector<string> v = { "hello","world" };
	pair<string, int> pa = process(v);
	cout << pa.first << pa.second << endl;
	cout << "test for vs git" << endl;

	return 0;
}