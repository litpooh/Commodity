#include <cctype>
#include <sstream>
using namespace std;

const vector<char> YNcheck = {'Y', 'N'}; // options of "Yes" and "No"
const vector<char> CZcheck = {'C', 'Z'}; // options of "Continue" and "Return"

// Note: A trick learnt from https://stackoverflow.com/questions/17335816/clear-screen-using-c
// Function: Clear Screen
// Input: NA
// Output: Clear Screen Command
void ClrScr () {
  cout << "\033[2J\033[1;1H"; // "a string that translates to the clear screen command"
}

// Function: Print a separating line
// Input: NA
// Output: A line
void Separate () {
  cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
}

// Function: Perform case insensitive comparasion for 2 strings
// Input: str_1, str_2 = Strings to be compared
// Output: False if they aren't equal, True otherwise
bool AnyCaseTrue (string str_1, string str_2) {
  int size = str_1.size(), pos = -1;
  if (str_1.size() != str_2.size()) // not equal if not of the same size
    return 0;
  while (++pos, pos < size) // check that the compared position hasn't reached the end
    if (!isalpha(str_1[pos]) && (str_1[pos] != str_2[pos])) // check symbol and number
      return 0;
    else if (tolower(str_1[pos]) != tolower(str_2[pos])) // ignore cases for alphabets
      return 0;
  return 1;
}

// Function: check for a valid string term
// Input: message = a message to be printed in case of error
// Output: the string from user input
string CheckStr (const char message[]) {
  string str = "";
  bool done = 0;
  while (!done) { // ensure a valid string is inputted
    string line;
    getline(cin, line);
    istringstream istr (line);
    int size = 0;
    if (line.size() != 0) {
      while (istr >> line) {
        str = line;
        ++size; // find the no. of input
      }
      if (size > 1)
        cout << message; // error as only 1 string is expected
      else
        done = 1;
    }
  }
  return str;
}

// Function: check that the string passed is a number (allow digits and negative no.)
// Input: str = the string to be checked
// Output: 1 for a number; 0 otherwise
bool AllNum (string &str) {
  int size = str.size();
  if (size != 0) { // exclude possible cin error
    if (str[0] == '-') { // consider negative number
      for (int i = 1; i < size; ++i)
        if (!isdigit(str[i]) && str[i] != '.') // consider digits
          return 0;
    }
    else {
      for (int i = 0; i < size; ++i)
        if (!isdigit(str[i]) && str[i] != '.')
          return 0;
    }
  }
  return 1;
}

// Function: Check for a range of valid number input
// Input: expected_size = the no. of number input to be expected
//        list (not really for input but output)
//        message = an error message
// Output: 1 for valid input; 0 otherwise;
//         list = the number(s) from user input
bool CheckNum (int expected_size, vector<float> &list, const char message[]) {
  list = {};
  bool done = 0;
  while (!done) { // ensure valid input
    string line;
    getline(cin, line);
    istringstream istr (line);
    int size = 0;
    if (line.size() != 0) {
      while (istr >> line)
        if (AllNum(line)) { // check that input is a number
          list.push_back(stof(line)); // store the string as float
          ++size; // count the number of input
        }
      if (size != expected_size) {
        cout << message; // error if more or fewer inputs than expected
        return 0;
      }
      else {
        done = 1;
        return 1;
      }
    }
  }
  return 1;
}

// Function: Ensure that the option is valid
// Input: list = list of allowed options (char)
// Output: correct char inputted by user
char Option (const vector<char> &list) {
  string choice;
  bool done = 0;
  while (!done) { // ensure a valid option is inputted
    getline(cin, choice); // get the input
    if (choice.size() != 0) { // ignore cin error
      if (choice.size() != 1) // check for size (char size = 1)
        cout << "Error! Please input a valid option: ";
      else {
        if (!isalpha(choice[0])) // check that the input is a char but not symbol or number
          cout << "Error! Please input a valid option: ";
        else {
          choice[0] = toupper(choice[0]); // get its uppercase for convenienve in comparasion
          for (char item : list)
            if (choice[0] == item) { // check that the item is a valid option
              done = 1;
              break;
            }
          if (!done)
            cout << "Error! Please input a valid option: ";
        }
      }
    }
  }
  return choice[0]; // return the char
}

// Function: print the main menu
// Input: NA
// Output: the menu
void Menu () {
  cout << "\'S\': Search item" << endl;
  cout << "\'I\': Insert new item" << endl;
  cout << "\'U\': Update item" << endl;
  cout << "\'D\': Delete item" << endl;
  cout << "\'E\': Exit" << endl;
  cout << "Input one of the options: ";
}

// Function: print the query for searching and to pass the input
// Input: filter = not really for input but for output
// Output: the chosen filter; searching instruction
void Query (char &filter) {
  cout << "Below are the filters for the record" << endl;
  cout << "\'N\' for Name\n\'T\' for Tag\n\'M\' for Manufacturer\n\'S\' for Status" << endl;
  cout << "\'P\' for Price\n\'R\' for Return Rate\n\'A\' for Availability" << endl;
  cout << "Or \'Z\' to return; What is your choice? ";

  vector<char> check = {'N', 'T', 'M', 'S', 'P', 'R', 'D', 'A', 'Z'};
  filter = Option(check); // check for input validity

  ClrScr();
  if (filter == 'P' || filter == 'R' || filter == 'D')
    cout << "Please input the lower, upper bound in order" << endl;

  switch (filter) {
    case 'N':
      cout << "What is the name of the item? "; break;
    case 'T':
      cout << "What is the tag for the item(s)? "; break;
    case 'M':
      cout << "Who is the manufacturer of the item(s)? "; break;
    case 'S': {
      cout << "OS = Out-of-stock, LW = Low, NM = Normal, EC = Excess" << endl;
      cout << "What is the status of the item(s)? "; break;
    }
    case 'P':
      cout << "What is the price range of the item(s)? "; break;
    case 'R':
      cout << "What is the return rate range of the item(s)? "; break;
    case 'D':
      cout << "What is the demand range of the item(s)? "; break;
    case 'A':
      cout << "Which shop (1 to 4) do you want to search? "; break;
  }
}

// Function: guide users to insert new item
// Input: choice = programmer-decided choice (the guide to display)
// Output: the guide
void InsertGuide (int choice) {
  switch (choice) {
    case 0:
      cout << "(\'Z\' to return) Input \'C\' to continue insert: "; break;
    case 1:
      cout << "Please input the information accordingly to insert new item to record" << endl; break;
    case 2:
      cout << "Name: "; break;
    case 3:
      cout << "Tag: "; break;
    case 4:
      cout << "Manufacturer: "; break;
    case 5:
      cout << "Supply Price: $"; break;
    case 6:
      cout << "Expected Return Rate: "; break;
    case 7:
      cout << "Stock Number in the 4 Shops in order: "; break;
  }
}

// Function: guide users to update items
// Input: choice = programmer-decided choice (the guide to display)
// Output: the guide
void UpdateGuide (int choice) {
  switch (choice) {
    case 0:
      cout << "(\'Z\' to return) Input \'C\' to continue update: "; break;
    case 1: {
      cout << "Please input in order (1 to 4)" << endl;
      cout << "Zero means no change in stock level" << endl;
      cout << "Positive value for procurement or any stock increase" << endl;
      cout << "Negative value for sold quantity or any stock decrease" << endl; break;
    }
    case 2: {
      cout << "\n\'N\' for Name / \'T\' for Tag / \'M\' for Manufacturer" << endl;
      cout << "\'P\' for Price / \'R\' for Return Rate / \'A\' for Availability" << endl;
      cout << "\'Z\' to return; What is your choice? "; break;
    }
  }
}

// Function: get the update choiec from user
// Input: NA
// Output: the choice inputted by user
char UpdateChoice () {
  vector<char> check = {'N', 'T', 'M', 'P', 'R', 'Z'};
  char option = Option(check); // check for input validity

  switch (option) {
    case 'N':
      cout << "What is the new name? "; break;
    case 'T':
      cout << "What is the new tag? "; break;
    case 'M':
      cout << "Who is the new manufacturer? "; break;
    case 'P':
      cout << "What is the new price? "; break;
    case 'R':
      cout << "What is the new return rate? "; break;
  }
  return option;
}

// Function: guide users to delete items
// Input: NA
// Output: the guide
void DeleteGuide () {
  cout << "(\'Z\' to return) Input \'C\' to continue delete: ";
}
