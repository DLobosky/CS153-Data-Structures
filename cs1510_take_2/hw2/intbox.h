/* @file: intbox.h
 * Definition of class IntBox
 * @C - Galaxy Express Softworks 
 * 
 * Version 14.3.0
 
 */

#ifndef INTBOX_H
#define INTBOX_H

#include <iostream>


/* _________________
  /                 \
  |  IntBox  Class  |
  \_________________/
   
    Purpose: Implements an Integer Box, as required by the Emperor Lrrr

    An Integer-Box is a class that encapsulates an array of Integers
    The size of the array is specified at declaration.

*/

// ---------------  Class IntBox Declarations
class IntBox
{ 
public:  
  int* m_ints;                        // Array of Integers
  int m_boxsize;                      // number of Integers in this box       


public:
  // Purpose: Constructs an Integer Box
	// Preconditions:
	//     's' is greater than 0;
  // Postconditions: 
  //     m_ints points to a dynamically allocated array of size 's'
  //     all elements of m_ints[] are initiallized to 'a'.
  
  IntBox(int s, int a);


  /* 
   * --------- Big 3 Member Functions -----------
   */

  // Purpose: Destructor
  // Postconditions: m_ints[] deallocated
  ~IntBox();

  // Purpose: Operator=, performs a deep copy of 'rhs' into 'this' IntBox
  // Parameters: rhs, IntBox to be copied
  // Returns: *this
  // Postconditions: *this == rhs
  const IntBox& operator=(const IntBox& rhs);

  // Purpose: Copy Constructor
  // Parameters: rhs - IntBox to be copied
  // Postconditions:  *this == rhs
  IntBox(const IntBox& rhs);


  /* 
   * ----- Simple Accessor Operations ----- 
   */

  // Purpose: Sets a value in the IntBox
  // Parameters: 'i' location to set
  //             'x' value to store
  // PreConditions: 'i' is between the boundaries of the IntBox 
  // Postconditions:  element 'i' in the IntBox is set to 'x'
	void set( int i, int x);


  /* 
   * ----- Complex Accessor Operations ----- 
   */
  
  // Purpose: prints the IntBox
  friend std::ostream& operator<< (std::ostream& out, 
                                   const IntBox& box);
}; // IntBox





#endif
