using namespace std;

// for storing the entire record of a item from "record.txt"
struct info {
  string name;
  string tag; // additional description
  string manufacturer;
  float price;
  float return_rate; // expected return rate
  int availability[4]; // stocks per shop
  int demand;
  string status; // NA = No status, OS = Out-of-stock, LW = Low, NM = Normal, EC = Excess

  // Function: test whether the data structure is empty (an item should at least has a name)
  // Input: the content of the data structure (specifically name)
  // Output: 1 if empty; 0 otherwise
  bool empty () {
    return name.empty();
  }

  // Function: fill the contents of the data structure
  // Input: record = a line extracted from "record.txt"
  // Output: NA (the filled data structure)
  void FillInfo (istringstream & record) {
    record >> name >> tag >> manufacturer >> price >> return_rate;
    for (int i = 0; i < 4; ++i)
      record >> availability[i];
    record >> demand >> status;
  }

  // Function: Update the availability of the item
  // Input: the content of the data structure
  // Output: the total change of inventory
  int AvailabilityIO () {
    vector<float> list;
    bool done = 0;
    cout << "\nWhat are the respective change in stocks in different shops? ";
    while (!done) {
      bool error = 0;
<<<<<<< HEAD
      // get the correct availability
      if (CheckNum(4, list, "What are the respective change in stocks in different shops? ")) {
        for (int i = 0; i < 4; ++i)
          if (availability[i] + list[i] < 0) {
          // check that the stock level is normal (>= 0)
=======
      if (CheckNum(4, list, "What are the respective change in stocks in different shops? ")) {
        for (int i = 0; i < 4; ++i)
          if (availability[i] + list[i] < 0) {
>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
           cout << "Error! Stock level below 0. Please input the correct change: ";
           error = 1;
           break;
         }
<<<<<<< HEAD
        if (!error) // if everything's fine
=======
        if (!error)
>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
          done = 1;
      }
    }

    int change[4];
    for (int i = 0; i < 4; ++i)
<<<<<<< HEAD
      change[i] = list[i]; // cast any float value to int

    // Show the calculated availability
=======
      change[i] = list[i];

>>>>>>> 0cb6ff2e8faf7ce8ffc13ee86bad3f5354571dc8
    cout << "\n1st shop: " << availability[0] << " + " << change[0] << " = " << availability[0] + change[0] << endl;
    cout << "2nd shop: " << availability[1] << " + " << change[1] << " = " << availability[1] + change[1] << endl;
    cout << "3rd shop: " << availability[2] << " + " << change[2] << " = " << availability[2] + change[2] << endl;
    cout << "4th shop: " << availability[3] << " + " << change[3] << " = " << availability[3] + change[3] << endl;

    cout << "Are you certain that the current stocks are as above (Y/N)? ";
    char option = Option(YNcheck);
    if (option == 'Y') {
      int sum = 0;
      for (int i = 0; i < 4; ++i) {
        sum += change[i]; // find the total change of inventory
        availability[i] += change[i]; // actually change the availability of the item
      }
      return sum;
    }
    else
      return AvailabilityIO(); // for user to reject the previous change
  }

  // Function: calculate the total inventories
  // Input: the content of the data structure
  // Output: the sum of inventory
  int TotalStock () {
    return availability[0] + availability[1] + availability[2] + availability[3];
  }

  // Function: Display the content of the data structure
  // Input: the content of the data structure
  // Output: the message describing the item
  void ShowInfo () {
    cout << name << " (" << tag << ") from " << manufacturer << " at $" << price;
    cout << endl << "Expected Demand: " << demand << " | Sell this item at $";
    cout << price * return_rate << " for a Return Rate of "<< return_rate << endl;
    cout << "Stock Level: "<< status << " ——> Shop Inventory: #1 = " << availability[0];
    cout << "; #2 = " << availability[1] << "; #3 = " << availability[2] << "; #4 = " << availability[3] << "\n\n";
  }

  // Function: Export the data structure to a file
  // Input: temp = the output file
  // Output: NA (printed to the specified file)
  void Export (ofstream &temp) {
    temp << name << ' ' << tag << ' ' << manufacturer << ' ' << price << ' ' << return_rate;
    for (int i = 0; i < 4; ++i)
      temp << ' ' << availability[i];
    temp << ' ' << demand << ' ' << status << endl;
  }

  // Function: Display the reorder message (only show necessary info for reordering)
  // Input: count = a counter for easier reordering
  // Output: the reorder message
  void Reorder (int &count) {
    cout << count << ": " << endl;
    cout << name << " (" << tag << ") from " << manufacturer << " at Supply Price $" << price;
    cout << endl << "Expected Demand: " << demand << " | Stock Level: "<< status;
    cout << " ——> Total Inventory: " << TotalStock() << endl;
    cout << "You should reorder " << demand - TotalStock() << ' ' << name << "\n\n";
    ++count;
  }
};
