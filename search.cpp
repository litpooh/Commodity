#include <sstream> // istringstream
using namespace std;

// Function: Search the file by attribute of type string
// Input: filter = the attribute used as filter for the record
//        term = the search term, could be name, tag, etc.
// Output: Use ShowSearch() to print item(s) which attribute matches term
void SearchStr (char filter, string term) {
  ifstream record = IFile("record.txt");
  string line;
  vector<info> list;

  // include items that match the term
  while (getline(record, line)) {
    info item = {};
    istringstream istr (line);
    item.FillInfo(istr);
    switch (filter) {
      case 'N':
        if (AnyCaseTrue(item.name, term)) {
          list.push_back(item);
          break;
        } break;
      case 'T':
        if (AnyCaseTrue(item.tag, term))
          list.push_back(item); break;
      case 'M':
        if (AnyCaseTrue(item.manufacturer, term))
          list.push_back(item); break;
      case 'S':
        if (AnyCaseTrue(item.status, term))
          list.push_back(item); break;
    }
  }
  record.close();
  ShowSearch(list);
}

// Function: Perform nested search of a vector of item(s) by attribute of type string
// Input: list = the previously filtered item(s)
//        filter = the attribute used as filter for the record
//        term = the search term, could be name, tag, etc.
// Output: Use ShowSearch() to print the nested-found item(s) which attribute matches term
void NestedSearchStr (vector<info> &list, char filter, string term) {
  vector<info>::iterator itrbe = list.begin(), itren = list.end();

  // remove item that doesn't match the term
  while (itrbe != itren)
    switch (filter) {
      case 'N':
        if (!AnyCaseTrue(itrbe->name, term)) {
          list.erase(itrbe);
          --itren;
        }
        else
          ++itrbe; break;
      case 'T':
        if (!AnyCaseTrue(itrbe->tag, term)) {
          list.erase(itrbe);
          --itren;
        }
        else
          ++itrbe; break;
      case 'M':
        if (!AnyCaseTrue(itrbe->manufacturer, term)) {
          list.erase(itrbe);
          --itren;
        }
        else
          ++itrbe; break;
      case 'S':
        if (!AnyCaseTrue(itrbe->status, term)) {
          list.erase(itrbe);
          --itren;
        }
        else
          ++itrbe; break;
    }
  ShowSearch(list); // display the further-filtered list
}

// Function: Search the file by attribute of number type
// Input: filter = the attribute used as filter for the record
//        low = the lower bound of the search range
//        up = the upper bound of the search range
// Output: Use ShowSearch() to print item(s) which attribute is within low and up
void SearchNum (char filter, float low, float up) {
  ifstream record = IFile("record.txt");
  string line;
  vector<info> list;

  // include items that match the range
  while (getline(record, line)) {
    info item = {};
    istringstream istr (line);
    item.FillInfo(istr);
    switch (filter) {
      case 'P':
        if (item.price >= low && item.price <= up)
          list.push_back(item); break;
      case 'R':
        if (item.return_rate >= low && item.return_rate <= up)
          list.push_back(item); break;
      case 'D':
        if (item.demand >= low && item.demand <= up)
          list.push_back(item); break;
    }
  }
  record.close();
  ShowSearch(list);
}

// Function: Perform nested search of a vector of item(s) by attribute of number type
// Input: list = the previously filtered item(s)
//        filter = the attribute used as filter for the record
//        low = the lower bound of the search range
//        up = the upper bound of the search range
// Output: Use ShowSearch() to print the nested-found item(s) which attribute is within low and up
void NestedSearchNum (vector<info> &list, char filter, float low, float up) {
  vector<info>::iterator itrbe = list.begin(), itren = list.end();

  // remove item that doesn't match the range
  while (itrbe != itren)
    switch (filter) {
      case 'P':
        if (itrbe->price < low || itrbe->price > up) {
          list.erase(itrbe);
          --itren;
        }
        else
          ++itrbe; break;
      case 'R':
        if (itrbe->return_rate < low || itrbe->return_rate > up) {
          list.erase(itrbe);
          --itren;
        }
        else
          ++itrbe; break;
      case 'D':
        if (itrbe->demand < low || itrbe->demand > up) {
          list.erase(itrbe);
          --itren;
        }
        else
          ++itrbe; break;
    }
  ShowSearch(list);
}

// Function: Search the file for item(s) that are available in a specific shop
// Input: shop = the shop number from 1 to 4
// Output: Use ShowSearch() to print the nested-found item that are available in a specific shop
void SearchAvail (int shop) {
  ifstream record = IFile("record.txt");
  string line;
  vector<info> list;

  // include items that are in-stock in a certain shop
  while (getline(record, line)) {
    info item = {};
    istringstream istr (line);
    item.FillInfo(istr);
    if (item.availability[shop] > 0)
      list.push_back(item);
  }
  record.close();
  ShowSearch(list);
}

// Function: Perform nested search for item(s) that are available in a specific shop
// Input: list = the previously filtered item(s)
//        shop = the shop number from 1 to 4
// Output: Use ShowSearch() to print the nested-found item that are available in a specific shop
void NestedSearchAvail (vector<info> &list, int shop) {
  vector<info>::iterator itrbe = list.begin(), itren = list.end();

  // remove item that are out-of-stock in a certain shop
  while (itrbe != itren)
    if (itrbe->availability[shop] == 0) {
      list.erase(itrbe);
      --itren;
    }
    else
      ++itrbe;
  ShowSearch(list);
}

// Function: Search the file by name of a good
// Input: name = the name of the desired good
// Output: item (and its info) that matches the name; any empty item otherwise
info SearchName (string name) {
  ifstream record = IFile("record.txt");
  string line;
  info item = {};
  while (getline(record, line)) {
    if (AnyCaseTrue(line.substr(0, line.find(' ')), name)) { // find the item
      istringstream istr (line);
      item.FillInfo(istr);
      break;
    }
  }
  record.close();
  return item;
}
