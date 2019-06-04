#pragma once
#include "MyHeader.h"

/*
	Text query program
	Input: a file
	Output: the number of times a word appears in a file and its line
*/

/*
	List Operation:
	1. read line by line
	2. Remember the line number of the word you are querying
*/

/*
	data structure
	+ vector<string> save the file user defined .the element of vector is the line of the file user defined
	+ Use istringstream to break each line into words
	+ Use set to save the line number of each word that appears in the input text
	+ Use map to associate each word with the line number set it appears in
*/

class QueryResult;

class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&)const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};


