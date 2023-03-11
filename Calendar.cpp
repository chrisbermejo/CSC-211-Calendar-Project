#include "Calendar.h"

void Date::setLeapYear(int tempyear){
  if (tempyear % 400 == 0 || (tempyear % 4 == 0) && (tempyear % 100 != 0)) {
      numberofDAYS[2] = 29;
    } 
    else {
      numberofDAYS[2] = 28;
    }
}

int Date::daynameIndex() {
  int tempyear = year;
  tempyear -= month < 3;
  return (tempyear + tempyear / 4 - tempyear / 100 + tempyear / 400 +
          yearCode[month - 1] + 1) % 7;
}

bool Date::validDate(int y, int m, int d){
  setLeapYear(y);
  if( (d > 0) && (d <= numberofDAYS[m]) && (y >= 1753) && (m > 0) && (m < 13)){
    return true;
  }
  return false;
}

string Date::returnDayName(int year, int month, int day) {
  int tempyear = year;
  tempyear -= month < 3;
  int index = (tempyear + tempyear / 4 - tempyear / 100 + tempyear / 400 + yearCode[month - 1] + day) % 7;
  return nameofDayString[index];
}

Date::Date() {
  month = 1;
  day = 1;
  year = 1753;
  nameofDay = returnDayName(year,month,day);
  nameofMonth = nameofMonthString[month];
};

Date::Date(int m, int d, int y) {
  month = m;
  day = d;
  year = y;
  nameofDay = returnDayName(year,month,day);
  nameofMonth = nameofMonthString[month];
};

void Date::setMonth(int m) { month = m; } 

void Date::setDay(int d) { day = d; }

void Date::setYear(int y) { year = y; } 

void Date::setAll(int m, int d, int y) {
  year = y;
  month = m;
  day = d;
  nameofDay = returnDayName(year,month,day);
  nameofMonth = nameofMonthString[month];
}


void Date::setnameofDay(string n) { nameofDay = n; } 

void Date::setnameofMonth(string m) { nameofMonth = m; } 

int Date::getMonth() { return month; } 

int Date::getDay() { return day; } 

int Date::getYear() { return year; } 

string Date::getnameofDay() { return nameofDay; } 

string Date::getnameofMonth() { return nameofMonth; } 

bool Date::compareYears(int newyear, int newmonth, int newday){
  if ((newyear > year) || (newyear == year && newmonth > month) || ((newyear == year) && (newmonth == month) && (newday > day))){
    return true;
    }
  else if (newyear < year || (newyear == year && newmonth < month) || ((newyear == year) && (newmonth == month) && (newday < day))) {
    return false;
  }
  return -1;
}

void Date::printDateFormatOne() {
    int tempmonth = month, tempyear = year, tempday = day;
    cout<<right<<setfill('0')<<setw(2)<<tempmonth<<"/"<<setw(2)<<tempday<< "/" << tempyear << setfill(' ');
}

void Date::printDateFormatTwo() {
    cout << nameofDay << ", " << nameofMonth << " " << day << ", " << year << endl;
  }

void Date::printDateFormatTwo(int tempyear, int tempmonth, int tempday){
  cout<<returnDayName(tempyear,tempmonth,tempday)<<", "          
  <<nameofMonthString[tempmonth]<<" "<<tempday<<", "<<tempyear<<"."<<endl;
}

string Date::printDateCalendar(int tempyear, int tempmonth, int tempday){
  return returnDayName(tempyear,tempmonth,tempday)+", "+nameofMonthString[tempmonth]+" "+to_string(tempday);
}

void Date::printFutureDate() {
  int tempyear = year;
  int tempmonth = month;
  int tempday = day;
  int totaldays;
  cout << "  Enter the number days to add: ";
  cin >> totaldays;
  int temptotaldays = totaldays;
  totaldays += day;
  while(numberofDAYS[tempmonth] < totaldays){
    setLeapYear(tempyear);
    if(tempmonth == 12){
      totaldays -= numberofDAYS[tempmonth];
      tempmonth = 1;
      tempyear++;
    }
    else if(tempmonth < 12){
      totaldays -= numberofDAYS[tempmonth];
      tempmonth++;
    }
  }
  tempday = totaldays;
  cout << endl << "  " << temptotaldays << " days from now, the date will be: " << endl << "  ";
  printDateFormatTwo(tempyear,tempmonth,tempday);
}

void Date::printPastDate() {
  int tempyear = year;
  int tempmonth = month;
  int tempday = day;
  int totaldays;
  cout << "  Enter the number days to subtract: ";
  cin >> totaldays;
  int temptotaldays = totaldays;
  totaldays -= day;
  if(tempmonth == 1){
    tempmonth = 12;
    tempyear--;
  }else{
    tempmonth--;
  }
  while(numberofDAYS[tempmonth] < totaldays){
    setLeapYear(tempyear);
    if(tempmonth == 1){
      totaldays -= numberofDAYS[tempmonth];
      tempmonth = 12;
      tempyear--;
    }
    else if(tempmonth > 1){
      totaldays -= numberofDAYS[tempmonth];
      tempmonth--;
    }
  }
  tempday = totaldays;
  cout << endl;
  int finalday = numberofDAYS[tempmonth]-tempday;
  if(finalday == 0){
    tempmonth--;
    finalday = numberofDAYS[tempmonth];
  }
  cout << "  " << temptotaldays << " days ago, the date was: " << endl << "  ";
  printDateFormatTwo(tempyear,tempmonth,tempday);
}

int Date::returnPassedDays() {
  int answer = 0;
  int tempday = 01;
  int tempmonth = 01;
  int tempyear = year;
  
  setLeapYear(tempyear);
  
  while(tempmonth < month + 1){
    if (tempmonth == month) {
      answer += day;
      tempmonth++;
    }
    if (tempmonth < month) {
      answer += numberofDAYS[tempmonth];
      tempmonth++;
    } 
  }
  return answer;
}

int Date::returnRemainingDays() {
  bool flag = true;
  int tempyear = year;
  int tempmonth = month;
  int remainingdays = 0;

  setLeapYear(tempyear);
  
  while(flag){
    if (month == 12) {
      remainingdays = 31 - day;
      flag = false;
    }
    else if(tempmonth == month){
      remainingdays += numberofDAYS[tempmonth] - day;
      tempmonth++;
    }
    else if(tempmonth == 12){
      remainingdays += numberofDAYS[tempmonth];
      flag = false;
    }
    else if(tempmonth < 12){
      remainingdays += numberofDAYS[tempmonth];
      tempmonth++;
    }      
  }
  return remainingdays;
}

int Date::operator-(const Date &other) {
  int newyear = other.year;
  int newmonth = other.month;
  int newday = other.day;
  int answer = 0;
  int tempday = day;
  int tempmonth = month;
  int tempyear = year;
  int yearpluscounter = 0;
  if(compareYears(newyear,newmonth,newday)){
    answer = 0;
    tempday = day;
    tempmonth = month;
    tempyear = year;
    yearpluscounter = 0;
    while (tempyear < newyear) {
      setLeapYear(tempyear);

      if (tempmonth == month && tempyear == year && month == 12) {
        answer += numberofDAYS[tempmonth] - day;
        tempmonth = 1;
        tempyear++;
        yearpluscounter++;
      }
      else if (tempmonth == month && tempyear == year) {
        answer += numberofDAYS[tempmonth] - day;
        tempmonth++;
      } 
      else if (tempmonth < 12) {
        answer += numberofDAYS[tempmonth];
        tempmonth++;
      } 
      else if (tempmonth == 12) {
        answer += numberofDAYS[tempmonth];
        tempmonth = 1;
        tempyear++;
        yearpluscounter++;
      }
    }
    while (tempyear == newyear && tempmonth <= newmonth) {
      setLeapYear(tempyear);
      if (month == newmonth && yearpluscounter == 0 && newday >= day) {
        answer += newday - day;
        tempmonth++;
      }
      else if (tempmonth == month && yearpluscounter == 0) {
        answer += numberofDAYS[tempmonth] - day;
        tempmonth++;
      }
      else if (tempmonth < newmonth) {
        answer += numberofDAYS[tempmonth];
        tempmonth++;
      } 
      else if (tempmonth == newmonth) {
        answer += newday;
        tempmonth++;
      }
    }
  }
  else if (!(compareYears(newyear,newmonth,newday))){
    answer = 0;
    tempday = other.day;
    tempmonth = other.month;
    tempyear = other.year;
    yearpluscounter = 0;
    while (tempyear < year) {
      setLeapYear(tempyear);
      if (tempmonth == newmonth && tempyear == newyear && newmonth == 12) {
        answer += numberofDAYS[tempmonth] - newday;
        tempmonth = 1;
        tempyear++;
        yearpluscounter++;
      }
      else if (tempmonth == newmonth && tempyear == newyear) {
        answer += numberofDAYS[tempmonth] - newday;
        tempmonth++;
      } 
      else if (tempmonth < 12) {
        answer += numberofDAYS[tempmonth];
        tempmonth++;
      } 
      else if (tempmonth == 12) {
        answer += numberofDAYS[tempmonth];
        tempmonth = 1;
        tempyear++;
        yearpluscounter++;
      }
    }
    while (tempyear == year && tempmonth <= month) {
      setLeapYear(tempyear);
      if (month == newmonth && yearpluscounter == 0 && tempday <= day) {
        answer += day-tempday;
        tempmonth++;
      }
      else if (tempmonth == newmonth && yearpluscounter == 0) {
        answer += numberofDAYS[tempmonth] - newday;
        tempmonth++;
      }
      else if (tempmonth < month) {
        answer += numberofDAYS[tempmonth];
        tempmonth++;
      } 
      else if (tempmonth == month) {
        answer += day;
        tempmonth++;
      }
    }
  }
  return answer;
}

void Date::operator++() { 
  day++;
  setLeapYear(year);
  if(day > numberofDAYS[month] && month == 12){
    setAll(1,1,++year);
  }
  else if(day > numberofDAYS[month]){
    setAll(++month,1,year);
  }
}

void Date::operator--(){
  if(month == 1 && day == 1 && year == 1753){
    cout << "  UNABLE TO INCREMENT" << endl;
  }else{
    day--;
    setLeapYear(year);
    if(month == 1 && day == 1 && year == 1753){
      cout << "  Date decremented!" << endl << endl << "  ";
      printDateFormatTwo();
    }
    else if(day == 0 && month == 1){
      setAll(12, numberofDAYS[12], --year);
    }
    else if(day == 0){
      setAll(--month,numberofDAYS[month],year);
    }
  }
}

void Date::printMonthCalendar() {
  setLeapYear(year);
  int amountofspaces = daynameIndex();
  if (month <= 3 && month >= 6) {
    cout << "          " << nameofMonth << " " << year << "           "
         << endl;
  } else {
    cout << "             " << nameofMonth << " " << year << "           "
         << endl;
  }
  cout << "  ---------------------------------" << endl;
  cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
  int counter;
  for (counter = 0; counter < amountofspaces; counter++) { 
    cout << "     ";
  }
  for (int daynumber = 1; daynumber <= numberofDAYS[month]; daynumber++) {
    //cout << setw(5)<< ix; print correctly when used before pritning Display Holiday
    //when used after messes up the format
    printf("%5d",daynumber);
    ++counter;
    if (counter > 6) {
      counter = 0;
      cout << endl;
    }
  }
  cout << endl;
}

void Date::printHolidays(){
  int lastmonday;
  int tempyear;
  cout<<"  Enter the year: ";
  cin>>tempyear;
  int tempmonth = 1;
  int tempday = 1;
  cout<<endl;
  string printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- New Year's Day"<<endl;
  while(returnDayName(tempyear,tempmonth,tempday) != "Monday"){
    tempday++;
  }
  tempday+=14;
  printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- Martin Luther King, Jr. Day" 
  <<endl;
  tempmonth = 2;
  tempday = 1;
  while(returnDayName(tempyear,tempmonth,tempday) != "Monday"){
    tempday++;
  }
  tempday+=14;
  printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- President's Day" 
  <<endl;
  tempmonth = 5;
  tempday = 15;
  while(tempday <= numberofDAYS[tempmonth]){
    if(returnDayName(tempyear,tempmonth,tempday) == "Monday"){
      lastmonday = tempday;
    }
    tempday++;
  }
  printthing = printDateCalendar(tempyear,tempmonth,lastmonday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- Memorial Day" 
  <<endl;
  tempmonth = 7;
  tempday = 4;
  printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- Independence Day" 
  <<endl;
  tempmonth = 9;
  tempday = 1;
  while(returnDayName(tempyear,tempmonth,tempday) != "Monday"){
    tempday++;
  }
  printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- Labor Day" 
  <<endl;
  
  tempmonth = 10;
  tempday = 1;
  while(returnDayName(tempyear,tempmonth,tempday) != "Monday"){
    tempday++;
  }
  tempday+=7;
  printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- Columbus Day" 
  <<endl;

  tempmonth = 11;
  tempday = 11;
  printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- Veterans Day" 
  <<endl;

  tempmonth = 11;
  tempday = 1;
  while(returnDayName(tempyear,tempmonth,tempday) != "Thursday"){
    tempday++;
  }
  tempday+=21;
  printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- Thanksgiving Day" 
  <<endl;

  tempmonth = 12;
  tempday = 25;
  printthing = printDateCalendar(tempyear,tempmonth,tempday);
  cout<<"  "<<left<<setw(23)<<printthing;
  cout<<"- Christmas Day" 
  <<endl;
}