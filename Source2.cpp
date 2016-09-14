/*  Taylor Jenkins
	05-04-16
	CIT 213-875
	Assignment Ch. 7
	Part II: 25pts.
	Exercize 10 (Page 454)  */

/*
This program represents 2 weeks with 7 days available to work in 
a week. Each element in the 2D array represents the hours worked 
for that day of the week. This program will get the total of all 
the values, return the average of the values, return the total 
for each row, return the total for each column, display the highest
value in the row, and display the lowest value in the array using 
functions.
*/
#include <iomanip>
#include <iostream>
using namespace std;

// Global Constants:
const int NUM_DAYS = 7; //to hold the number of days in a week (Determines the # cols)
const int NUM_WEEKS = 2; //to hold the number of weeks used for calculation (Determines the # rows)

//Prototypes:
double getAverage(double[NUM_WEEKS][NUM_DAYS]);
double getTotal(double[NUM_WEEKS][NUM_DAYS]);
double getRowTotal(double[][NUM_DAYS], int);
double getColumnTotal(double[][NUM_DAYS], int);
double getHighestInRow(double[][NUM_DAYS], int);
double getLowestInRow(double[][NUM_DAYS], int);

//*****************************************/
//*This is the start of the main function.*/
//*****************************************/
int main()
{
	//Declare Variables:
	double totalHoursWorked = 0;
	double avgHoursWorked = 0;
	double weekTotal= 0;
	double dayTotal = 0;
	double wkHigh = 0;
	double wkLow = 0;

	// Array initialized with test data.
	double hoursWorked[NUM_WEEKS][NUM_DAYS] = { { 9, 8, 0, 8, 0, 5, 0 },
											  { 0, 8.5, 0, 7, 0, 0, 8 } };

	cout << endl  << "\t\tPay Period Information\n" << endl; //title

	//Runs and displays function getTotal
	totalHoursWorked = getTotal(hoursWorked);
	cout << fixed << showpoint << setprecision(2);
	cout << "The total hours worked for this pay period are: ";
	cout << totalHoursWorked << endl;

	//Runs and displays function getAverage
	avgHoursWorked = getAverage(hoursWorked);
	cout << fixed << showpoint << setprecision(2);
	cout << "The average hours worked for this pay period are: ";
	cout << avgHoursWorked << endl;

	//Runs and displays function getRowTotal
	weekTotal = getRowTotal(hoursWorked, 0); //selecting the first row
	cout << fixed << showpoint << setprecision(2);
	cout << "The hours worked for this week are: ";
	cout << weekTotal << endl;

	//Runs and displays function getColumnTotal
	dayTotal = getColumnTotal(hoursWorked, 3); //selecting Wednesdays (col 3)
	cout << fixed << showpoint << setprecision(2);
	cout << "The hours worked on this day for this pay period are: ";
	cout << dayTotal << endl;

	//Runs and displays function getHighestInRow
	wkHigh = getHighestInRow(hoursWorked, 0); //selecting the first row
	cout << fixed << showpoint << setprecision(2);
	cout << "The longest day you worked this week was ";
	cout << wkHigh << " hours." <<  endl;

	//Runs and displays function getLowestInRow
	wkLow = getLowestInRow(hoursWorked, 0); //selecting the first row
	cout << fixed << showpoint << setprecision(2);
	cout << "The shortest day you worked this week was ";
	cout << wkLow << " hours." << endl;

	cout << endl << endl; //for asthetics

	return 0;
}

//*********************************************/
//*This is the start of the function getTotal.*/
//*This function adds all of the elements in  */
//*the array first going down the row and then*/
//*moving to the next column.				  */
//*********************************************/
double getTotal(double hoursWorked[NUM_WEEKS][NUM_DAYS])
{
	int days; //used as counter
	int weeks; //used as counter
	double total = 0; 

	//Nested loop to add all the elements.
	for (weeks = 0; weeks < NUM_WEEKS; weeks++)
	{		
		for (days = 0; days < NUM_DAYS; days++)
		{
			total += hoursWorked[weeks][days];
		}
	}

	return total;
}

//***********************************************/
//*This is the start of the function getAverage.*/
//*This function adds all of the elements in    */
//*the array first going down the row and then  */
//*moving to the next column and then  returns  */
//*the total divided by the number of columns   */
//*multiplied by the number of rows to calculate*/
//*the average.									*/
//***********************************************/
double getAverage(double hoursWorked [NUM_WEEKS][NUM_DAYS])
{
	double average = 0; 
	int days; //used as counter
	int weeks; //used as counter
	
	//Nested loop to add all the elements.
	for (weeks = 0; weeks < NUM_WEEKS; weeks++)
	{
		for (days = 0; days < NUM_DAYS; days++)
		{
			average += hoursWorked[weeks][days];
		}
	}

	return average / (NUM_DAYS * NUM_WEEKS); 
	//divided by the multiplied columns and rows to 
	//get the total # of elements to calculate avg.
}

//***********************************************/
//*Start of the function getRowTotal			*/
//*This function adds all of the elements in    */
//*the array going down the row and returns		*/
//*the total									*/
//***********************************************/
double getRowTotal(double hoursWorked [][NUM_DAYS], int row )
{
	int days; //counter
	double total = 0;

	for (days = 0; days < NUM_DAYS; days++)
	{
		total += hoursWorked[row][days];
	}
	return total;
}

//***********************************************/
//*Start of the function getColTotal			*/
//*This function adds all of the elements in    */
//*the array going down the column and returns	*/
//*the total.									*/
//***********************************************/
double getColumnTotal(double hoursWorked[][NUM_DAYS], int cols )
{
	int weeks; //used as counter
	double total = 0;

	for (weeks = 0; weeks < NUM_WEEKS; weeks++)
	{
		total += hoursWorked[weeks][cols];
	}
	return total;
}

//***********************************************/
//*Start of the function getHighestInRow		*/
//*This function goes through the row selected  */
//*and stores the highest number it finds into 	*/
//*the highest variable.						*/
//***********************************************/
double getHighestInRow(double hoursWorked[][NUM_DAYS], int row)
{
	double highest = 0; 
	int days; //counter

	for (days = 0; days < NUM_DAYS; days++)
	{
		if(hoursWorked[row][days] > highest)
		{ 
			highest = hoursWorked[row][days];
		}
	}
	return highest;
}

//***********************************************/
//*Start of the function getLowestInRow		    */
//*This function goes through the row selected  */
//*and stores the lowest number it finds into 	*/
//*the lowest variable.						    */
//***********************************************/
double getLowestInRow(double hoursWorked[][NUM_DAYS], int row)
{
	double lowest = 8; //A typical work day is 8 hours.
	int days; //counter

	for (days = 0; days < NUM_DAYS; days++)
	{

		if (hoursWorked[row][days] < lowest)
		{
			lowest = hoursWorked[row][days];
		}
	}
	return lowest;
}

/* OUTPUT: */

/*
Pay Period Information

The total hours worked for this pay period are: 53.50
The average hours worked for this pay period are: 3.82
The hours worked for this week are: 30.00
The hours worked on this day for this pay period are: 15.00
The longest day you worked this week was 9.00 hours.
The shortest day you worked this week was 0.00 hours.


Press any key to continue . . .
*/