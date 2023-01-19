#include <cstdio>
// insert.cpp
void ExportInsert(vector<info> &);
bool CheckInsertList (string, vector<info> &);
void Insert ();
//

// update.cpp
void RecordExport (vector<info> &);
void SaleExport (vector<data> &);
void Update ();
void UpdateOther (info &, char);
void UpdateStr (info &, char, string);
void UpdateNum (info &, char, float);
//

// status.cpp
void Status (info &);
void DemandExport (vector<result> &);
void Forecast ();
//

// delete.cpp
void ItemDelete (vector<string> &, string);
bool CheckDeleteList (string, vector<string> &);
void DeleteCheck (info &, vector<string> &);
void Delete ();
//

#include "insert.cpp"
#include "update.cpp"
#include "status.cpp"
#include "delete.cpp"
