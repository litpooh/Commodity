using namespace std;

// Function: append the items to be inserted to "record.txt"
// Input: list = the insert list
// Output: NA (records exported to the file)
void ExportInsert(vector<info> &list) {
  ofstream record = OFile("record.txt", 1);
  for (info item : list)
    if (!item.empty()) // check that no empty item is pushed
      item.Export(record);
  record.close();
}

// Function: Check if the item is already in the insert list
// Input: name = item name
//        list = the insert list
// Output: 1 if already in the insert list; 0 otherwise
bool CheckInsertList (string name, vector<info> &list) {
  for (info item : list)
    if (AnyCaseTrue(name, item.name)) {
      cout << "Error! " << name << " is already in the insert list" << endl;
      return 1;
    }
  return 0;
}

// Function: get the info of the item(s) to be inserted, then insert them
// Input: NA
// Output: NA (the item is inserted to the file)
void Insert () {
  char option;
  vector<info> list;

  // allow the user to return
  while (ClrScr(), InsertGuide(0), option = Option(CZcheck), option != 'Z') {
    info item;
    string term[3] = {};
    float number[2] = {};
    int shop[4] = {};
    InsertGuide(1); // Guidelines

    // check for valid name (not in "record.txt", not in insert list)
    while (InsertGuide(2), term[0] = CheckStr("Error! Please input 1 name only: "),
    item = SearchName(term[0]), CheckInsertList(term[0], list) || !item.empty())
      cout << "Input \'Z\' to return or input a new record here: ";
    // allow users to return
    if (term[0] != "Z") {
      InsertGuide(3); // input tag
      term[1] = CheckStr("Error! Please input 1 tag only: ");

      InsertGuide(4); // input manufacturer
      term[2] = CheckStr("Error! Please input 1 manufacturer only: ");

      vector<float> num_list;
      InsertGuide(5);
      while(!CheckNum(1, num_list, "Error! Please input the price: "));
      number[0] = num_list[0]; // input price

      InsertGuide(6);
      while(!CheckNum(1, num_list, "Error! Please input the return rate: "));
      number[1] = num_list[0]; // input return rate

      InsertGuide(7);
      while(!CheckNum(4, num_list, "Error! Please input the number of stocks: "));
      for (int i = 0; i < 4; ++i)
        shop[i] = num_list[i]; // input availabiliity

      item = {term[0], term[1], term[2], number[0], number[1],
        {shop[0], shop[1], shop[2], shop[3]}, 0, "NA"}; // construct the item
      list.push_back(item); // store the item in the insert list
      }
  }
  // append all the items to "record.txt"
  ExportInsert(list);
  ClrScr();
}
