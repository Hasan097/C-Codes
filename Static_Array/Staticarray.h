// Syed Taha Hasan
// Student ID: 1549267

#ifndef Staticarray_h
#define Staticarray_h

template <typename V, int CAP>	//Template for V and Capcity.

class Array
{
 V a[CAP];
 V dummy = V();
 
 public:
 Array();					// Constructor
 int capacity () const;		// Capcity of the array
 V operator[](int) const;	// Getter Operator
 V& operator[](int);		// Setter Operator
};

// Constructor assigns default value.
template <typename V, int CAP>
Array<V , CAP> :: Array()
{
 for(int i = 0; i < CAP; i++)
	 a[i] = V();
}

// Capacity function returns size of the array.
template <typename V, int CAP>
int Array<V , CAP> :: capacity() const
{
 return CAP;
}

// Setter tests the validity of the index then returns the array value.
template <typename V, int CAP>
V& Array <V , CAP> :: operator[](int index)
{
 if(index < 0)
	 return dummy;
 if(index >= CAP)
	 return dummy;
 return a[index];
}

// Getter operator
template <typename V, int CAP>
V Array <V , CAP> :: operator[](int index) const
{
 if(index < 0)	
	 return 0;
 if(index >= CAP)
	 return 0;
 return a[index];
}

#endif