#ifndef CALENDAR_H
#define CALENDAR_H

#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Date {
private:
  //A private data member month of type integer that holds the date’s month.
  int month;
  //A private data member day of type integer that holds the date’s day.
  int day;
  //A private data member year of type integer that holds the date’s year.
  int year;
  //A private data member nameofDay of type string that holds day's name.
  string nameofDay;
  //A privae data meber nameofMonth of type string that holds month's name.
  string nameofMonth;
public:  
  //used to find the day name
  vector<int> yearCode = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  //key = month number value = month name
  unordered_map<int, string> nameofMonthString = {
      {1, "January"},   {2, "February"}, {3, "March"},     {4, "April"},
      {5, "May"},       {6, "June"},     {7, "July"},      {8, "August"},
      {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}};
  //key = month number value = month days
  unordered_map<int, int> numberofDAYS = {
      {1, 31}, {2, 28}, {3, 31}, {4, 30},  {5, 31},  {6, 30},
      {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
  //key = week number value = day name
  unordered_map<int, string> nameofDayString = {
      {0, "Sunday"},   {1, "Monday"}, {2, "Tuesday"}, {3, "Wednesday"},
      {4, "Thursday"}, {5, "Friday"}, {6, "Saturday"}};
  //A function that tests whether a year is leap.
  void setLeapYear(int tempyear);
  //returns key of week number which gets the day name used in Calendar function
  int daynameIndex();
  //Check if date is valid
  bool validDate(int y, int m, int d);
  //A member function that returns the day name of a date (ex, Sunday, Monday …).
  string returnDayName(int year, int month, int day);
  //A default constructor that sets the date to January 1, 1753.
  Date();
  // Constructor
  Date(int m, int d, int y);
  void setMonth(int m);
  void setDay(int d);
  void setYear(int y);
  void setAll(int m, int d, int y);
  void setnameofDay(string n); // mutator
  void setnameofMonth(string m); // mutator
  int getMonth(); // accessor
  int getDay(); // accessor
  int getYear(); // accessor
  string getnameofDay(); // accessor
  string getnameofMonth();// accessor
  // Compares Class date to the inputted date 
  bool compareYears(int newyear, int newmonth, int newday);
  // B // A member function that prints on the screen a date in the form mm / dd / yyyy.
  void printDateFormatOne();
  // C // A member function that prints a date including the name of the day and the name of the month as strings.
  void printDateFormatTwo();
  //used to print the date in other functions(future date, past date,compares dates,...)
  void printDateFormatTwo(int tempyear, int tempmonth, int tempday);
  string printDateCalendar(int tempyear, int tempmonth, int tempday);
  // D // A function that calculates and prints a date by adding a fixed number of days to the current date.
  void printFutureDate();
  // E // A function that calculates and prints a date by subtracting a fixed number of days from the current date. 
  void printPastDate();
  // F // A function that returns the number of days passed in the current year.
  int returnPassedDays();
  // G //	A function that returns the number of days remaining in the current year.
  int returnRemainingDays();
  // H // The overloaded subtraction operator that returns an integer that is the difference in days between two Date objects.
  int operator-(const Date &other);
  // I // The overloaded increment operator that modifies the Date object so that it represents the next day.
  void operator++();
  // J //	The overloaded decrement operator that modifies the Date object so that it represents the previous day. 
  // J // The operator must not decrement dates prior to January 1, 1753.
  void operator--();
  // K //	A function that prints the calendar for the current month.
  void printMonthCalendar();
  //L // A function that prints the holidays of any year.
  void printHolidays();
};

#endif