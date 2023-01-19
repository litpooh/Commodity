#include <iostream>
#include <vector>
#include "io.h"
#include "structinfo.h"
#include "structdata.h"
#include "search.h"
#include "record.h"
using namespace std;

// Note: This program is only tested on Ubuntu and macOS
int main () {
  Forecast(); // push reordering alert after updating the demand and status
  cout << "Do you want to manage your record (Y/N)? "; // option for those only want to check for procurement
  char choice = Option(YNcheck); // get the choice
  if (choice == 'Y') { // start the management page
    ClrScr();
    char option;
    vector<char> check = {'E', 'S', 'I', 'U', 'D'}; // the allowed options
    while (Menu(), option = Option(check), option != 'E') // get the option and check for exit
      switch (option) {
        case 'S': {
          vector<info> list; // a empty value that is not used
          Search(0, list); break; // start searching
        }
        case 'I':
          Insert(); break; // insert new item to record
        case 'U':
          Update(); break; // update existing item
        case 'D':
          Delete(); break; // delete item from record
      }
  }
  return 0;
}
