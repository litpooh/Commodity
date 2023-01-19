using namespace std;

// Function: update the status of an item
// Input: item = the item
// Output: NA (the changed status)
void Status (info &item) {
  if (item.TotalStock() == 0)
    item.status = "OS";
  else if (item.TotalStock() <= 0.3 * item.demand)
    item.status = "LW";
  else if (item.TotalStock() > 1.3 * item.demand)
    item.status = "EC";
  else
    item.status = "NM";
}

// Function: export the demand, print reordering messages
// Input: list = the list of item(s) along with their demand
// Output: NA (the items being updated)
void DemandExport (vector<result> &list) {
  ifstream record = IFile("record.txt");
  ofstream temp = OFile("temp_record.txt", 0);
  string line;
  info record_item;
  int count = 1;

  // reordering messages
  cout << "The following items need reordering: " << endl;
  while (getline(record, line)) {
    bool found = 0;
    istringstream istr (line);
    record_item.FillInfo(istr);
    for (result item : list)
      if (AnyCaseTrue(record_item.name, item.name)) { // check for valid name
        found = 1;
        record_item.demand = item.demand; // update the demand
        Status(record_item); // update the status
        record_item.Export(temp); // print the item and its contents to a temp file
        if (record_item.status == "LW" || record_item.status == "OS")
          record_item.Reorder(count);
        break;
      }
    if (!found) { // for items that need no update
      temp << line << endl; // print the item
      if (record_item.status == "LW" || record_item.status == "OS") {
        record_item.Reorder(count); // print reordering message
      }
    }
  }
  Separate();
  record.close();
  temp.close();
  remove("record.txt");
  rename("temp_record.txt", "record.txt"); // overwrite the original file
}

// Function: perform demand Forecast
// Input: NA (the records)
// Output: NA (the records being updated)
void Forecast () {
  ifstream sale = IFile("sale.txt");
  string line;
  vector<result> list;
  while (getline(sale, line)) {
    data item = {};
    istringstream istr (line);
    item.FillData(istr, 1);
    list.push_back({item.name, item.WeightedMean()}); // push the name and forecasted demand
  }
  sale.close();
  DemandExport(list);
}
