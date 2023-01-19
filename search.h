// query.cpp
void Search (bool, vector<info> &);
void ShowSearch (vector<info> &);
//

// search.cpp
void SearchStr (char, string);
void NestedSearchStr (vector<info> &, char, string);
void SearchNum (char, float, float);
void NestedSearchNum (vector<info> &, char, float, float);
void SearchAvail (int);
void NestedSearchAvail (vector<info> &, int);
info SearchName (string);
//

#include "query.cpp"
#include "search.cpp"
