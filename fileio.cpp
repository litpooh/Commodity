using namespace std;

// Function: create ifstream and check for error
// Input: filename = the filename
// Output: the checked ifstream
ifstream IFile (const char filename[]) {
  ifstream file (filename);
  if (file.fail()) { // check for failure
    cout << "Fail to open " << filename << endl;
    exit(1);
  }
  else
    return file;
}

// Function: create ofstream and check for error
// Input: filename = the filename
//        append = check if append flag should be used
// Output: the checked ofstream
ofstream OFile (const char filename[], bool append) {
  if (append) {
    ofstream Afile (filename, ios::app); // append
    if (Afile.fail()) {
      cout << "Fail to open " << filename << endl;
      exit(1);
    }
    else
      return Afile;
  }
  else {
    ofstream file (filename);
    if (file.fail()) {
      cout << "Fail to open " << filename << endl;
      exit(1);
    }
    else
      return file;
  }
}
