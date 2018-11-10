// Syed Taha Hasan
// Student ID: 1549267

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "Staticarray.h"
#include "Staticarray.h"	// ifndef test

int main()
{
	
 cout << "\nName: TAHA HASAN SYED";
 cout << "\nID: 1549267";
 cout << "\nFile Name: " << __FILE__<<"\n\n";
 
 Array <double , 100>ob;
 Array <double , 100>ab;						// Two double class objects.
 int loc,counter = 0, search;	// Location, counter and search variables
 double val; 					// Value varible
 string buf1, buf2,buf3;			// Buffer variables.
 
 //Setting the values from the user's input into the array.
 while(true)
 {
   cout << "\n\nInput an index and the value[Enter Q to quit]: ";
   cin >> buf1;
   if(buf1[0] == 'q' || buf1[0] == 'Q')
	   break;
   cin >> buf2;
   
   val = atof(buf2.c_str());		// Truns to floating point values
   loc = atoi(buf1.c_str());		// Turns to int values
   ob[loc] = val;
 }
 
 //Counting the number of unique entries using 2 arrays
 for(int i = 0; i < ob.capacity(); i++)
 {
	 ab[i] = ob[i];
	 if(ab[i] != 0)
	  counter++;
 }
 
 cout << "\nYou stored this many values: " << counter;
 cout << "\nThe index => value pairs are: \n";
 
 // Displaying the index-vlaues.
 for(int j = 0; j < ob.capacity(); j++)
 {
	 if(ab[j] != 0)
		 cout << j << " => " << ab[j] << endl;
 }
 
 // Loop to search for the index values given by the user.
 while(true)
 {
   cout << "\n\nInput an Index for me to look up [Q to quit]: ";
   cin >> buf3;
   if(buf3 == "q" || buf3 == "Q")
	   break;
   
   search = atoi(buf3.c_str());
   
   if(ab[search] != 0)
	   cout << "\nSearch Successful -- the value stored in " << search << " is " << ab[search];
   else 
	   cout << "\nSearch Failed... Unable to find results";
 }
}