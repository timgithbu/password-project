//
//  main.cpp
//  Testing_4A
//
//  Created by Timothy Ng on 1/20/16.
//  Copyright © 2016 Timothy Ng. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main ()
{
   string password;
   bool validated;
   char letter;
   int length;

   // Get password candidate from console, until it passes our tests
   validated = false;
   while (!validated)
   {
      // Get password candidate from user
      cout << "Enter a password, please ('q' to quit): ";
      getline(cin, password);

      length = password.length();

      // Test for quit first
      if ( length == 1 && ( password[0] == 'q' || password[0] == 'Q' ))
      {
         cout << "No password defined.\n";
         break; // From Loop
      }

      // Test for reasonable length
      if (length < 6 || length > 15)
      {
         cout << "Password must be between 6 and 15 characters.\n";
         continue;
      }

      validated = true; // Assume innocent entering loop
                        // Allow only letters and numbers
      for (int k = 0; k < length; k++)
      {
         letter = password[k]; // Store in local variable so we can reuse
         if (letter >= 'a' && letter <= 'z')
            continue; // The for loop, we have a good lower case letter
         else if (letter >= 'A' && letter <= 'Z')
            continue; // The for loop. we have a good upper case letter
         else if (letter >= '0' && letter <= '9')
            continue; // The For Loop, we have a good numeral
         else
         {
            // This letter is not one of the three legal types
            cout << "Use only A-Z, a-z or 0-9, please: ";
            validated = false;
            break; // From the for loop leaving validated as false
         }
      }

      // If the above loop yielded an error, we try again
      if (!validated)
         continue;

      // If we made it here, it is the proper length and has legal chars
      // But is the first charactera letter?
      letter = password[0];
      if (letter >= '0' && letter <= '9')
      {
         cout << "First character must a letter (non-numeric).\n";
         validated = false;
         continue;
      }
      else
      {
         // They passed the final test
         cout << "Your password " + password + " has been accepted.\n";
         break; // This is not needed but is safe
      }
   }

   cout << "\nGood bye. \n\n";
}




