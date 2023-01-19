using namespace std;

// Function: delete the item from files
// Input: list = the list of items to be deleted
//        filename = the file to delete the record
// Output: NA (the records being deleted)
void ItemDelete (vector<string> &list, string filename) {
  ifstream file = IFile(filename.c_str());
  string temp_filename = "temp_" + filename; // create a temp filename
  ofstream temp = OFile(temp_filename.c_str(), 0);
  string line;
  while (getline(file, line)) {
    bool found = 0;
    for (string name : list)
      if (AnyCaseTrue(line.substr(0, line.find(' ')), name)) { // ensure valid item
        found = 1;
        break;
      }
    if (!found)
      temp << line << endl; // pass the unaffected lines
  }
  file.close();
  temp.close();
  remove(filename.c_str());
  rename(temp_filename.c_str(), filename.c_str()); // overwrite original file
}

// Function: check if a item is already in the delete list
// Input: name = item name
//        list = delete list
// Output: 1 if in delete list; 0 otherwise
bool CheckDeleteList (string name, vector<string> &list) {
  for (string name_list : list)
    if (AnyCaseTrue(name_list, name)) {
      cout << "Error! " << name << " is already in the delete list" << endl;
      return 1;
    }
  return 0;
}

// Function: get the item(s) to be deleted, then delete them
// Input: NA (user input)
// Output: NA (the items being deleted)
void Delete () {
  vector<string> list;
  info item;
  char option;
  // allow users to return
  while (ClrScr(), DeleteGuide(), option = Option(CZcheck), option != 'Z') {
    cout << "(\'Z\' to return) Please input the name of the commodity: ";

    bool leave = 0;
    bool done = 0;
    while (!done) {
      string name;
      cin >> name;
      // check for return
      if (name.size() == 1 && toupper(name[0]) == 'Z') {
        leave = 1;
        break;
      }
      // check for a valid name (in file but not in delete list)
      item = SearchName(name);
      if (CheckDeleteList(name, list) || item.empty())
        cout << "Please input a valid name: ";
      else
        done = 1;
    }
    if (leave)
      break;

    // display the info of the item
    Separate();
    item.ShowInfo();
    Separate();

    int stock = item.TotalStock();
    char choice = 'Y';
    while (choice != 'N') {
      // alert users if an item is still in-stock
      if (stock > 0)
        cout << "There are still " << stock << " " << item.name << " in stock!" << endl;
      // confirmation
      cout << "Do you want to delete the record for " << item.name << " (Y/N)? ";
      choice = Option(YNcheck);
      if (choice == 'Y') {
        list.push_back(item.name);
        break;
      }
    }
  }
  // actually delete the item(s) from both files
  string record = "record.txt", sale = "sale.txt";
  ItemDelete(list, record);
  ItemDelete(list, sale);
  ClrScr();
}
