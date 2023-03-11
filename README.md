# Date Class Project

This project is a calendar application that utilizes a custom Date class to perform various operations related to dates and time. The Date class includes various member functions and operators, including:

- Accessors and mutators for the month, day, and year
- A function to print the date in the form of "mm / dd / yyyy"
- A function to return the day of the week for a given date
- A function to print the date in the form of "Weekday, Month day, year"
- An overloaded subtraction operator (-) to return the difference in days between two Date objects
- An overloaded increment operator (++) to modify the Date object to represent the next day
- An overloaded decrement operator (--) to modify the Date object to represent the previous day, with a limit of January 1, 1753

In addition to the Date class, this project also includes several functions to test and manipulate dates, including:

- A function to test if a year is a leap year
- A function to add a fixed number of days to a given date
- A function to subtract a fixed number of days from a given date
- A function to return the number of days passed in the current year
- A function to return the number of days remaining in the current year
- A function to print the calendar for the current month
- A function to print the holidays for any given year, based on the US federal holidays

To use this application, simply run the program and choose from the menu of options to set and display dates, perform calculations, and view calendars and holidays.

## Rules for Determining Leap Years

Leap years are any year that can be exactly divided by 4 (such as 2016, 2020, 2024, etc), except if it can be exactly divided by 100, then it isn't (such as 2100, 2200, 2300, etc), except if it can be exactly divided by 400, then it is (such as 2000, 2400, 2800, etc).

## List of US Federal Holidays

- New Year's Day - January 1st
- Martin Luther King, Jr. Day - Third Monday of January
- President's Day - Third Monday of February
- Memorial Day - Last Monday of May
- Independence Day - July 4th
- Labor Day - First Monday of September
- Columbus Day - Second Monday of October
- Veterans Day - November 11th
- Thanksgiving Day - Fourth Thursday of November
- Christmas Day - December 25th
