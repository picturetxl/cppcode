#include "ClassQueryResult.h"

string make_plural(vector<string>::size_type size,string time,string times)
{
	return size > 0 ? time + times : time;
}

ostream& print(ostream& os, const QueryResult &qt)
{
	os<<qt.sought<<" occurs "<<qt.lines->size()<<" "
		<< make_plural( qt.lines->size(), " times", "s") << endl;

		for (auto num : *qt.lines) {
			os << "\t(line " << num + 1 << ")"
				<< *(qt.file->begin() + num) << endl;

		}

		return os;
}
