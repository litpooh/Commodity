using namespace std;

// Function: Ask for a filter to apply, then based on the search condition
//           (initial/nested) to perform the search
// Input: nested = indicate whether it's a nested search
//        list = input for nested search (unused for initial search)
// Output: Searching instruction, search result
void Search (bool nested, vector<info> &list) {
  ClrScr();
  char filter;
  Query(filter); // choose a filter

  if (filter == 'N' || filter == 'T' || filter == 'M' || filter == 'S') { // attribute of type string
    string term;
    cin >> term; // get the search term
    if (!nested)
      SearchStr(filter, term); // trigger initial search on string
    else
      NestedSearchStr(list, filter, term); // trigger nested search on string
  }
  else if (filter == 'P' || filter == 'R' || filter == 'D') {
    float low, up;
    while (cin >> low >> up, low > up) // get the range while ensuring input is in order
      cout << "Error! Please input the lower, upper bound in order: "; // prompt user for re-input
    if (!nested)
      SearchNum(filter, low, up); // trigger initial search on number
    else
      NestedSearchNum(list, filter, low, up); // trigger nested search on number
  }
  else if (filter == 'A') {
    int shop;
    while (cin >> shop, shop < 1 || shop > 4) // get the shop number (1 but not 0 to be user-friendly)
      cout << "Error! Please input a valid shop (1 to 4): "; // prompt user for re-input
    if (!nested)
      SearchAvail(shop-1); // trigger initial search on availability
    else
      NestedSearchAvail(list, shop-1); // trigger nested search on availability
  }
  else if (filter == 'Z') // return to previous step
    return;

  if (!nested) {
    cout << "Do you want to search for other items (Y/N)? "; // prompt user for more search
    char option = Option(YNcheck); // get an option
    if (option == 'Y') {
      vector<info> temp;
      Search(0, temp); // start a new search if user agrees
    }
    else
      ClrScr(); // clear screen and return
  }
}

// Function: Display the search result, then perform further action (leave/nested search)
// Input: list = contents to be displayed and (maybe) for nested search
// Output: the search result
void ShowSearch (vector<info> &list) {
  // Display the search result(s)
  Separate();
  int count = 1;
  if (list.empty()) {
    cout << "No item found" << endl;
    Separate();
    return;
  }
  for (info item : list) {
    cout << count << ": " << endl;
    item.ShowInfo();
    ++count;
  }
  Separate();

  // Further action after searching (nested search or leave)

  cout << "Do you want to perform nested search (Y/N)? ";
  char option = Option(YNcheck);
  if (option == 'Y')
    Search(1, list);
  else if (option == 'N')
    return;
}
