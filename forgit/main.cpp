
#include "MyHeader.h"
#include "ClassQueryResult.h"
#include "ClassTextQuery.h"
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
void testSharedPtrCopy()
{

	auto p = make_shared<int>(42);//p point to the object of int 
	auto q(p);//q also point to the object of int
	auto xp = make_shared<int>(32);
	p = xp;
	cout << p.use_count();//2
	cout << q.use_count();//1
	cout << xp.use_count();//2
}
struct myList {
	vector<int> v;
	myList(initializer_list<int> l) :v(l) {};
	void append(initializer_list<int> l) {
 		v.insert(v.end(), l.begin(), l.end());
	}
	void traverlist()
	{
		for (auto i : v)
		{
			cout << i << " ";
		}
		
	}
};
void testSmartPointer()
{
	shared_ptr<int> sp1(new int(10));
	shared_ptr<int> sp2(sp1), sp3;
	sp3 = sp1;
	//一个典型的错误用法
	shared_ptr<int> sp4(sp1.get());
	cout << sp1.use_count() << " " << sp2.use_count() << " "
		<< sp3.use_count() << " " << sp4.use_count() << endl;
	//输出 3 3 3 1
	
}
//void testShared()
//{
//	int* p = new int(32);
//	shared_ptr<int> q1(p);
//	shared_ptr<int> q2(p);
//	shared_ptr<int> q3(p);
//	shared_ptr<int> q4(p);
//	cout << *p << endl;
//	cout << *q1 << endl;
//	cout << *q2 << endl;
//	cout << *q3 << endl;
//	cout << *q4 << endl;
//	
//	cout << q1.use_count() << endl;//1
//	cout << q2.use_count() << endl;//1
//	cout << q3.use_count() << endl;//1
//	cout << q4.use_count() << endl;//1
//}
unique_ptr<int> clone_unique_ptr(int p)
{
	return unique_ptr<int>(new int(p));
}
unique_ptr<int> clone_t(int p)
{
	unique_ptr<int> ret(new int(p));

	return ret;
}
void runQuery(ifstream& infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for , or q to quit";
		string s;
		if (!(cin>>s) || s == "q")
		{
			break;
		}
		print(cout, tq.query(s))<<endl;
	}
}
int main()
{
	ifstream is("C:\\Users\\tailiang\\Documents\\testcpp\\wordquery.txt");
	runQuery(is);
	return 0;
}
