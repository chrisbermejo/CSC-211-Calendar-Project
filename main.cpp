#include "Calendar.h"
#include "Menu.h"


int main() {
  string input = "0";
  Date DateOne;
  while ((input != "Z") && (input != "z")) {
    input = menu();
    if ((input == "A") || (input == "a")) {
      formatTop();
      int month = 13, day = 0, year = 1752;
      cout << "  Input date in this format (mm/dd/yyyy)" << endl << endl;
      while(!DateOne.validDate(year,month,day)){
        cout << "  Enter Month: ";
        cin >> month;
        cout << "  Enter Day: ";
        cin >> day;
        cout << "  Enter Year: ";
        cin >> year;
        if(!DateOne.validDate(year,month,day)){
          printmenu(input);
          cout << endl << "  Input date in this format (mm/dd/yyyy)" << endl << endl;
          cout << "  Enter Valid Date!" << endl << endl;
        }
      }
      DateOne.setAll(month, day, year);
      cout << endl;
      cout << "  New Date is ";
      DateOne.printDateFormatOne();
      cout << "." << endl;
      input = formatBottom(input);
    } 
    else if ((input == "B") || (input == "b")) {
      formatTop();
      cout << "  The Date is ";
      DateOne.printDateFormatOne();
      cout << "." << endl;
      input = formatBottom(input);
    } 
    else if ((input == "C") || (input == "c")) {
      formatTop();
      cout << "  The Date is ";
      DateOne.printDateFormatTwo();
      input = formatBottom(input);
    } 
    else if ((input == "D") || (input == "d")) {
      formatTop();
      DateOne.printFutureDate();
      input = formatBottom(input);
    } 
    else if ((input == "E") || (input == "e")) {
      formatTop();
      DateOne.printPastDate();
      input = formatBottom(input);
    } 
    else if ((input == "F") || (input == "f")) {
      formatTop();
      cout<<"  "<< DateOne.returnPassedDays() - 1 <<" days have passed this year."<< endl;
      input = formatBottom(input);
    } 
    else if ((input == "G") || (input == "g")) {
      formatTop();
      cout << "  There are " << DateOne.returnRemainingDays()  <<" days remaining."<< endl;
      input = formatBottom(input);
    } 
    else if ((input == "H") || (input == "h")) {
      formatTop();
      
      int newmonth = 13, newday = 0, newyear = 1752, answer = 0;
      cout << "  Input date in this format (mm/dd/yyyy)" << endl << endl;
      while(!DateOne.validDate(newyear,newmonth,newday)){
        cout << "  Enter Month: ";
        cin >> newmonth;
        cout << "  Enter Day: ";
        cin >> newday;
        cout << "  Enter Year: ";
        cin >> newyear;
        if(!DateOne.validDate(newyear,newmonth,newday)){
          printmenu(input);
          cout << endl << "  Input date in this format (mm/dd/yyyy)" << endl << endl;
          cout << "  Enter Valid Date!" << endl << endl;
        }
      }
      Date DateTwo(newmonth, newday, newyear);
      answer = DateOne - DateTwo;
      if(DateOne.compareYears(newyear,newmonth,newday)){
        cout << endl << "  The date entered will reach in " << answer <<" days!"<<endl;
      }
      else if(!(DateOne.compareYears(newyear,newmonth,newday))){
        cout << endl << "  The date entered has passed " << answer <<" days ago!"<<endl;
      }
      
      input = formatBottom(input);
    }
    else if ((input == "I") || (input == "i")) {
      formatTop();
      ++DateOne;
      cout << "  Date incremented!" << endl << endl << "  ";
      DateOne.printDateFormatTwo();
      input = formatBottom(input);
    } 
    else if ((input == "J") || (input == "j")) {
      formatTop();
      --DateOne;
      //WONT GO LOWER THAN 01/01/1753
      if(DateOne.getDay() != 1 && DateOne.getMonth() != 1 && DateOne.getYear() != 1753){
        cout << "  Date decremented!" << endl << endl << "  ";
        DateOne.printDateFormatTwo();
      }
      input = formatBottom(input);
    } 
    else if ((input == "K") || (input == "k")) {
      formatTop();
      DateOne.printMonthCalendar();
      input = formatBottom(input);
    } 
    else if ((input == "L") || (input == "l")) {
      formatTop();
      DateOne.printHolidays();
      input = formatBottom(input);
    }
  }
  cout << endl << "----------------------------====------------------------" << endl << endl << "  Program Closed";
  return 0;
}