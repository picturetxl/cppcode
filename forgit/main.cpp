#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
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
void testSet2()
{
	set<int> iset = { 0,1,2,3,4,5 };
	set<int>::iterator set_it = iset.begin();//The two types of iterators of set are read-only
	while (set_it != iset.end())
	{
		if (*set_it == 3)
		{
			//*set_it = 9; //you cannot assign to a variable that is const
			cout << "you cannot assign to a variable that is const" << endl;
		}
		cout << *set_it << endl;
		++set_it;
	}
}
void testSetFindAndCount()
{
	set<int> iset = { 0,1,2,3 };
	cout << *iset.find(1) << endl;
	cout << *iset.find(3) << endl;
	cout << iset.count(1) << endl;
	cout << iset.count(31) << endl;


}
/*
	Given a string, convert it to another string
	The first file holds some rules for converting the text in the second file.
	input : two files
	The first file:
		brb be right back
		k okay?
		y why
		r are
		u you
		pic picture
		thk thanks!
		18r later
	The second file:
		where r u
		y dont u send me a pic
		k thk 18r

	output:
		where are you
		why dont you send me a picture
		okay?thanks!later
*/
//Establish a conversion map
map<string, string> buildMap(ifstream& map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
		{
			trans_map[key] = value.substr(1);//Remove leading spaces
		}
		else
		{
			throw runtime_error("no rule for " + key);
		}
	}
	return trans_map;
}
const string& transform(const string& s, const map<string, string>& m)
{
	auto map_it = m.find(s);
	if (map_it !=m.cend())
	{
		return map_it->second;//Use replacement phrase
	}
	else
	{
		return s;//Return the original string 
	}
}
void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = buildMap(map_file);//save conversion rules
	string text;
	while (getline(input,text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream>>word)
		{
			//Print spaces between words
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main()
{
	
	ifstream map_file("C:\\Users\\xxx\\Documents\\testcpp\\map_file.txt",ios::in);
	ifstream trans_file("C:\\Users\\xxx\\Documents\\testcpp\\trans_file.txt",ios::in);

	word_transform(map_file,trans_file);
	return 0;
}