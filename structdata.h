#include <cmath>
using namespace std;

// for storing demand to update original record
struct result {
  string name;
  int demand;
};

// for storing sale record
struct data {
  string name;
  vector<int> buy;

  // Function: calculate the weighted mean, the weighting factors are designed in a
  //           way that older data is less important for the prediction
  // Input: The vector stored in the data structure
  // Output: the calculated weighted mean (forecasted demand)
  int WeightedMean ()  {
    float sum = 0;
    switch (buy.size()) {
      case 1:
        sum += buy[0]; break;
      case 2:
        sum += 0.6*buy[0] + 0.4*buy[1]; break;
      case 3:
        sum += 0.5*buy[0] + 0.3*buy[1] + 0.2*buy[2]; break;
      case 4:
        sum += 0.4*buy[0] + 0.25*buy[1] + 0.19*buy[2] + 0.16*buy[3]; break;
      case 5:
        sum += 0.4*buy[0] + 0.24*buy[1] + 0.16*buy[2] + 0.113*buy[3] + 0.087*buy[4]; break;
      case 6:
        sum += 0.35*buy[0] + 0.22*buy[1] + 0.147*buy[2] + 0.115*buy[3] + 0.09*buy[4];
        sum += 0.078*buy[5]; break;
      case 7:
        sum += 0.35*buy[0] + 0.22*buy[1] + 0.145*buy[2] + 0.101*buy[3] + 0.075*buy[4];
        sum += 0.06*buy[5] + 0.049*buy[6]; break;
      case 8:
        sum += 0.335*buy[0] + 0.213*buy[1] + 0.142*buy[2] + 0.098*buy[3] + 0.073*buy[4];
        sum += 0.057*buy[5] + 0.0453*buy[6] + 0.0367*buy[7]; break;
      case 9:
        sum += 0.325*buy[0] + 0.205*buy[1] + 0.138*buy[2] + 0.098*buy[3] + 0.073*buy[4];
        sum += 0.056*buy[5] + 0.044*buy[6] + 0.0343*buy[7] + 0.0267*buy[8]; break;
      case 10:
        sum += 0.31*buy[0] + 0.203*buy[1] + 0.138*buy[2] + 0.096*buy[3] + 0.07*buy[4];
        sum += 0.053*buy[5] + 0.041*buy[6] + 0.033*buy[7] + 0.029*buy[8] + 0.027*buy[9]; break;
    }
    return nearbyint(sum); // round the result to integer (assume quantity should be integer)
  }

  // Function: fill up the data structure
  // Input: data = a line extracted from "sale.txt"
  //        noname = indicate whether the name is filled already
  // Output: NA (the filled data structure)
  void FillData (istringstream & data, bool noname) {
    if (noname)
      data >> name;
    int temp;
    while (data >> temp) {
      buy.push_back(temp);
      if (buy.size() == 10) // only store a max. of 10 sale record
        break;
    }
  }

  // Function: print variable of the data structure to a file
  // Input: temp = the output file
  // Output: the contents (to the file)
  void Export (ofstream &temp) {
    temp << name;
    for (int i : buy)
      temp << ' ' << i;
    temp << "\n";
  }
};
