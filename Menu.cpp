#include "Menu.h"
using namespace std;

void printmenu(string input){
  cout << "\033[2J\033[1;1H";
  cout << "\n";
  cout << "----------------------------====------------------------" << endl;
  cout << "                            MENU" << endl;
  cout << "----------------------------====------------------------" << endl;
  cout << endl;
  cout << "  A) Set Date" << endl;
  cout << "  B) Display Date (mm/dd/yy)" << endl;
  cout << "  C) Display Date (Weekday, Month day, Year)" << endl;
  cout << "  D) Display Future Date" << endl;
  cout << "  E) Display Past Date" << endl;
  cout << "  F) Number Of Days Passed In Current Year" << endl;
  cout << "  G) Number Of Days Remaining In Current Year" << endl;
  cout << "  H) Compares Dates" << endl;
  cout << "  I) Increment Current Date" << endl;
  cout << "  J) Decrement Current Date" << endl;
  cout << "  K) Display Current Monthly Calendar" << endl;
  cout << "  L) Display Holidays" << endl;
  cout << endl;
  cout << "  Z) Exit" << endl;
  cout << endl;
  cout << "----------------------------====------------------------" << endl << endl;
  cout << "  Enter your choice: "<<input<<endl<<endl;
  cout << "----------------------------====------------------------" << endl;
}

string menu() {
  string input;
  cout << "\033[2J\033[1;1H";
  cout << "\n";
  cout << "----------------------------====------------------------" << endl;
  cout << "                            MENU" << endl;
  cout << "----------------------------====------------------------" << endl;
  cout << endl;
  cout << "  A) Set Date" << endl;
  cout << "  B) Display Date (mm/dd/yy)" << endl;
  cout << "  C) Display Date (Weekday, Month day, Year)" << endl;
  cout << "  D) Display Future Date" << endl;
  cout << "  E) Display Past Date" << endl;
  cout << "  F) Number Of Days Passed In Current Year" << endl;
  cout << "  G) Number Of Days Remaining In Current Year" << endl;
  cout << "  H) Compares Dates" << endl;
  cout << "  I) Increment Current Date" << endl;
  cout << "  J) Decrement Current Date" << endl;
  cout << "  K) Display Current Monthly Calendar" << endl;
  cout << "  L) Display Holidays" << endl;
  cout << endl;
  cout << "  Z) Exit" << endl;
  cout << endl;
  cout << "----------------------------====------------------------" << endl << endl;
  cout << "  Enter your choice: ";
  cin >> input;
  return input;
}

bool formatBottom(string input) {
  cout << endl;
  cout << "----------------------------====------------------------" << endl;
  // Used as a delay so the user can see the date update
  while (input != "\0") {
    cout << endl;
    cout << "  Press ENTER to return to menu: ";
    getline(cin, input);
    cin.ignore();
  }
  return 0;
}

void formatTop() {
  cout << endl << "----------------------------====------------------------" << endl;
  cout << endl;
}