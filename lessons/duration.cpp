#include <iostream>
#include <cstdlib>
#include <ctime>
#include "duration.h"

using namespace std;

/* Fill in this part */
/*---------------------------------------------------------------------------------- */

// Test the Duration class
int main() {
  srand(static_cast<unsigned> (time(0)));

  // Create a few durations and display them;

  cout << endl << "Testing the basics: " << endl << endl;

  Duration d1(5, 10);
  cout << "d1 = " << d1 << endl;

  Duration d2(1, 2, 3);
  cout << "d2 = " << d2 << endl;

  Duration d3 = d2;
  cout << "d3 = " << d3 << endl;

  d3 = d1;
  cout << "d3 = " << d3 << endl;

  Duration d4; // By default, zero time
  cout << "d4 = " << d4 << endl;

  // Test arithmetical operations on durations

  cout << endl << "Testing arithmetic: " << endl << endl;

  Duration d5(50, 50, 50);
  Duration d6(55, 55, 55);
  Duration d7(0, 59, 59);
  d1 = d5 + d6;
  d2 = d5 - d6;
  d3 = (d6 - d5) * 20;
  d4 = d5 - d7;

  cout << "d1 = " << d1 << endl;
  cout << "d2 = " << d2 << endl;
  cout << "d3 = " << d3 << endl;
  cout << "d4 = " << d4 << endl;

  d2 = Duration(1, 35, 30); // Call constructor directly
  d3 = Duration(3, 11);

  cout << "d2 / d3 = " << d2 / d3 << endl;
  cout << "d3 / d2 = " << d3 / d2 << endl;

  // Test some unusual cases

  cout << endl << "Testing unusual cases: " << endl << endl;

  d1 = Duration(0, 0, 3601);
  cout << "d1 = " << d1 << endl;

  d1 = Duration(100, 0, -1);
  cout << "d1 = " << d1 << endl;

  d2 = Duration(-1, 0, 3601) * 5;
  cout << "d2 = " << d2 << endl;

  d3 = Duration(-1, 0, 0) - Duration(2, 0) + Duration(1);
  cout << "d3 = " << d3 << endl; // perhaps not what you would expect!

  // Generate some random durations!

  cout << endl << "Test the randomize function: " << endl << endl;

  // Display 10 random durations
  for (int i = 0; i < 10; i++) {
    d1.randomize();
    cout << "d1 = " << d1 << endl;
  }

  // Compute the average of 10,000 random durations
  Duration dsum;
  for (int i = 0; i < 10000; i++) {
    d1.randomize();
    dsum = dsum + d1;
  }
  cout << "Average of 10,000 random durations is: " << dsum / 10000;
}