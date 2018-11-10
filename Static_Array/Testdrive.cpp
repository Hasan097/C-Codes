// Syed Taha Hasan
// Student ID: 1549267

#include <iostream>
#include <string>
using namespace std;

#include <cassert>
#include <cstdlib>

#include "Staticarray.h"
#include "Staticarray.h"	// ifndef test

int main()
{
 cout << "\nName: TAHA HASAN SYED";
 cout << "\nID: 1549267";
 cout << "\nFile Name: " << __FILE__<<"\n\n";
 
//================================ int test ==============================
    Array <int , 100> ob;
	cout << "\n===== TESTING int VALUES ===== \n";
   // Array <double , 100> ob;
   // Array <char , 100> ob;
   // Array <string , 100> ob;
 
   // Check for capacity
   cout << "\nTesting the Array::capacity\n";
   cout << "EPECTED : 100\n";
   cout << "ACTUAL : " << ob.capacity() << endl;
   assert(100 == ob.capacity());
   cout << "PASS...";
 
   //Testing constructor array::array
   cout << "\n\nTesting Array::Array";
   for(int i = 0; i < ob.capacity(); i++)
 	 assert(ob[i] == 0);
   cout << "\nPASS...\n";
 
   // Test for Array::operator[ ] setter
   ob[6] = 12;
   ob[7] = 75;
   cout << "\nTesting Array::operator[ ] setter\n";
   cout << "EXPECTED: 12 for ob[6]\n";
   cout << "ACTUAL: " << ob[6] << endl;
   assert(12 == ob[6]);
   cout << "EXPECTED: 75 for ob[7]\n";
   cout << "ACTUAL: " << ob[7] << endl;
   assert(75 == ob[7]);
   ob[-1000] = 23;
   cout << "EXPECTED: 23 for ob[-1000]\n";
   cout << "ACTUAL: " << ob[-1000] << endl;
   assert(23 == ob[-1000]);
   ob[1000] = 35;
   cout << "EXPECTED: 35 for ob[1000]\n";
   cout << "ACTUAL: " << ob[1000] << endl;
   assert(35 == ob[1000]);
   cout << "PASS...\n";
   
   // Test for Array::operator[] getter
   cout << "\nTesting the Array::operator[] getter \n";
   const Array<int ,100> b = ob;
   for(int i = 0; i < 100; i++)
	 assert(ob[i] == b[i]);
    cout << "PASS...\n";
 
   cout << "\nPress enter to continue...";
   cin.get();
   
   //================================ double test ==============================
   Array <double , 100> ab;
   cout <<"\n\n===== TEST FOR double VALUES ===== \n";
   // Check for capacity
   cout << "\nTesting the Array::capacity\n";
   cout << "EPECTED : 100\n";
   cout << "ACTUAL : " << ab.capacity() << endl;
   assert(100 == ab.capacity());
   cout << "PASS...";
 
   //Testing constructor array::array
   cout << "\n\nTesting Array::Array";
   for(int i = 0; i < ab.capacity(); i++)
 	 assert(ab[i] == 0);
   cout << "\nPASS...\n";
 
   // Test for Array::operator[ ] setter
   ab[6] = 12.01;
   ab[7] = 75.23;
   cout << "\nTesting Array::operator[ ] setter\n";
   cout << "EXPECTED: 12.01 for ab[6]\n";
   cout << "ACTUAL: " << ab[6] << endl;
   assert(12.01 == ab[6]);
   cout << "EXPECTED: 75.23 for ab[7]\n";
   cout << "ACTUAL: " << ab[7] << endl;
   assert(75.23 == ab[7]);
   ab[-1000] = 23.1;
   cout << "EXPECTED: 23.1 for ab[-1000]\n";
   cout << "ACTUAL: " << ab[-1000] << endl;
   assert(23.1 == ab[-1000]);
   ab[1000] = 3.5;
   cout << "EXPECTED: 3.5 for ab[1000]\n";
   cout << "ACTUAL: " << ab[1000] << endl;
   assert(3.5 == ab[1000]);
   cout << "PASS...\n";
   
   // Test for Array::operator[] getter
   cout << "\nTesting the Array::operator[] getter \n";
   const Array<double ,100> c = ab;
   for(int i = 0; i < 100; i++)
	 assert(ab[i] == c[i]);
    cout << "PASS...\n";
 
   cout << "\nPress enter to continue...";
   cin.get();

   
   // ============================= char test =============================
   Array <char , 100> bb;
   cout <<"\n\n===== TEST FOR char VALUES ===== \n";
   // Check for capacity
   cout << "\nTesting the Array::capacity\n";
   cout << "EPECTED : 100\n";
   cout << "ACTUAL : " << bb.capacity() << endl;
   assert(100 == bb.capacity());
   cout << "PASS...";
 
   //Testing constructor array::array
   cout << "\n\nTesting Array::Array";
   for(int i = 0; i < bb.capacity(); i++)
 	 assert(bb[i] == 0);
   cout << "\nPASS...\n";
 
   // Test for Array::operator[ ] setter
   bb[6] = 'a';
   bb[7] = 'b';
   cout << "\nTesting Array::operator[ ] setter\n";
   cout << "EXPECTED: 'a' for bb[6]\n";
   cout << "ACTUAL: " << bb[6] << endl;
   assert('a' == bb[6]);
   cout << "EXPECTED: 'b' for bb[7]\n";
   cout << "ACTUAL: " << bb[7] << endl;
   assert('b' == bb[7]);
   bb[-1000] = 'x';
   cout << "EXPECTED: 'x' for bb[-1000]\n";
   cout << "ACTUAL: " << bb[-1000] << endl;
   assert('x' == bb[-1000]);
   bb[1000] = 'X';
   cout << "EXPECTED: 'X' for bb[1000]\n";
   cout << "ACTUAL: " << bb[1000] << endl;
   assert('X' == bb[1000]);
   cout << "PASS...\n";
   
   // Test for Array::operator[] getter
   cout << "\nTesting the Array::operator[] getter \n";
   const Array<char ,100> d = bb;
   for(int i = 0; i < 100; i++)
	 assert(bb[i] == d[i]);
    cout << "PASS...\n";
 
   cout << "\nPress enter to continue...";
   cin.get();
   
   //================================ string test ==============================

   Array <string , 100> st;
   cout <<"\n\n===== TEST FOR string VALUES ===== \n";
   // Check for capacity
   cout << "\nTesting the Array::capacity\n";
   cout << "EPECTED : 100\n";
   cout << "ACTUAL : " << st.capacity() << endl;
   assert(100 == st.capacity());
   cout << "PASS...";
 
   //Testing constructor array::array
   cout << "\n\nTesting Array::Array";
   for(int i = 0; i < st.capacity(); i++)
 	 assert(st[i] == "\0");
   cout << "\nPASS...\n";
 
   // Test for Array::operator[ ] setter
   st[6] = "six";
   st[7] = "seven";
   cout << "\nTesting Array::operator[ ] setter\n";
   cout << "EXPECTED: 'six' for st[6]\n";
   cout << "ACTUAL: " << st[6] << endl;
   assert("six" == st[6]);
   cout << "EXPECTED: 'seven' for st[7]\n";
   cout << "ACTUAL: " << st[7] << endl;
   assert("seven" == st[7]);
   st[-1000] = "dummy";
   cout << "EXPECTED: 'dummy' for st[-1000]\n";
   cout << "ACTUAL: " << st[-1000] << endl;
   assert("dummy" == st[-1000]);
   st[1000] = "dummy";
   cout << "EXPECTED: 'dummy' for st[1000]\n";
   cout << "ACTUAL: " << st[1000] << endl;
   assert("dummy" == st[1000]);
   cout << "PASS...\n";
   
   // Test for Array::operator[] getter
   cout << "\nTesting the Array::operator[] getter \n";
   const Array<string ,100> s = st;
   for(int i = 0; i < 100; i++)
	 assert(st[i] == s[i]);
    cout << "PASS...\n";
 
   cout << "\nPress enter to Quit";
   cin.get();
}