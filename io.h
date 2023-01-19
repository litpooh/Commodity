#include <string>
#include <fstream>
using namespace std;
// stdio.cpp
void ClrScr ();
void Separate ();
bool AnyCaseTrue (string, string);
string CheckStr (const char []);
bool AllNum (string &str);
bool CheckNum (int, vector<float> &, const char []);
char Option ();
void Menu ();
void Query (char &);
void InsertGuide (int);
void UpdateGuide (int);
char UpdateChoice ();
void DeleteGuide ();
//

// fileio.cpp
ifstream IFile (const char []);
ofstream OFile (const char [], bool);
//

#include "stdio.cpp"
#include "fileio.cpp"
