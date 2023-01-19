using namespace std;

// Function: export the updated items to "record.txt"
// Input: list = the update list
// Output: NA (the records being updated)
void RecordExport (vector<info> &list) {
  ifstream record = IFile("record.txt");
  ofstream temp = OFile("temp_record.txt", 0);
  string line;
  while (getline(record, line)) {
    bool found = 0;
    for (info item : list)
<<<<<<< HEAD
      if (AnyCaseTrue(line.substr(0, line.find(' ')), item.name)) { // ensure valid name
=======
      if (AnyCaseTrue(line.substr(0, line.find(' ')), item.name)) {
>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
        found = 1;
        item.Export(temp);
        break;
      }
    if (!found)
      temp << line << endl; // pass unaffected lines
  }
  record.close();
  temp.close();
  remove("record.txt");
  rename("temp_record.txt", "record.txt"); // overwrite
}

// Function: export the updated items to "sale.txt"
// Input: list = the update list
// Output: NA (the records being updated)
void SaleExport (vector<data> &list) {
  ifstream sale = IFile("sale.txt");
  ofstream temp = OFile("temp_sale.txt", 0);
  string line;
  while (getline(sale, line)) {
    bool found = 0;
    for (data item : list)
<<<<<<< HEAD
      if (AnyCaseTrue(line.substr(0, line.find(' ')), item.name)) { // ensure valid name
=======
      if (AnyCaseTrue(line.substr(0, line.find(' ')), item.name)) {
>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
        found = 1;
        line.replace(0, line.find(' ') + 1, "");
        istringstream istr (line);
        item.FillData(istr, 0); // load the past sale data
        item.Export(temp); // output to temp file
        break;
      }
    if (!found)
      temp << line << endl; // pass the unaffected lines
  }
  sale.close();
  temp.close();
  remove("sale.txt");
  rename("temp_sale.txt", "sale.txt"); // overwrite
}

// Function: update any item
// Input: NA (the user input e.g. name)
// Output: NA (the record being updated)
void Update () {
  info recorditem;
  vector<info> recordlist;
  vector<data> salelist;
  char option;
<<<<<<< HEAD

  // allow users to return
=======
>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
  while (ClrScr(), UpdateGuide(0), option = Option(CZcheck), option != 'Z') {
    cout << "Please input the name of the commodity: ";
    bool done = 0;
    // ensure a valid name from user input
    while (!done) {
      recorditem = SearchName(CheckStr("Error! Please input 1 name only: "));
      if (recorditem.empty())
        cout << "Please input a valid name: ";
      else
        done = 1;
    }

    // check if an item is already in the update list
    for (info item : recordlist)
      if (AnyCaseTrue(item.name, recorditem.name)) // support all cases
        recorditem = item;

    // print the item info
    ClrScr();
    Separate();
    recorditem.ShowInfo();
    Separate();

    UpdateGuide(1);
    int totalchange = recorditem.AvailabilityIO();
    bool found = 0;
    for (data item : salelist)
      if (AnyCaseTrue(item.name, recorditem.name)) {
        found = 1;
        item.buy[0] += -totalchange; // update stock change for re-updated item
        break;
      }
    if (totalchange < 0 && !found)
      salelist.push_back({recorditem.name, {-totalchange}}); // push sale record

    // check for return
    char choice = 'Y';
    while (choice != 'N') {
      cout << "Do you want to update other attributes (Y/N)? ";
      choice = Option(YNcheck);
<<<<<<< HEAD
      if (choice == 'Y') { // allow to update other attributes
=======
      if (choice == 'Y') {
>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
        ClrScr();
        Separate();
        recorditem.ShowInfo();
        Separate();
        UpdateGuide(2);
        char attribute = UpdateChoice();
        if (attribute == 'Z')
          choice = 'N'; // allow return
        else
          UpdateOther(recorditem, attribute);
      }
    }
    recordlist.push_back(recorditem);
  }
  // actually update the items in file
  RecordExport(recordlist);
  SaleExport(salelist);
  ClrScr();
}

// Function: passing user input for update
// Input: item = the item to be updated
//        attribute = the attribute to be updated
// Output: NA (the data structure of the items being updated)
void UpdateOther (info &item, char attribute) {
  if (attribute == 'N' || attribute == 'T' || attribute == 'M') {
<<<<<<< HEAD
    // ensure valid sting term
=======
>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
    string term = CheckStr("Error! Please input a valid term: ");
    UpdateStr(item, attribute, term);
  }
  else if (attribute == 'P' || attribute == 'R') {
    vector<float> num_list;
<<<<<<< HEAD
    // get the valid number
=======
>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
    while (!CheckNum(1, num_list, "") || num_list[0] <= 0)
      cout << "Error! Please input a valid number (>0): ";
    UpdateNum(item, attribute, num_list[0]);
  }
}

// Function: update name, tag or manufacturer
// Input: item = the item to be updated
//        attribute = the attribute to be updated
//        term = the updated term
// Output: NA (the item being updated)
void UpdateStr (info &item, char attribute, string term) {
  switch (attribute) {
    case 'N':
      item.name = term; break;
    case 'T':
      item.tag = term; break;
    case 'M':
      item.manufacturer = term; break;
  }
}

// Function: update price or return rate
// Input: item = the item to be updated
//        attribute = the attribute to be updated
//        number = the updated number
// Output: NA (the item being updated)
void UpdateNum (info &item, char attribute, float number) {
  switch (attribute) {
    case 'P':
      item.price = number; break;
    case 'R':
      item.return_rate = number; break;
  }
}
