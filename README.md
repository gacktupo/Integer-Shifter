# Integer-Shifter

This program prompts user for an amount of integers, enter the integers, index to shift from, shifts the integers and displays the modified integers.

SAMPLE RUN:

Enter number of values: g

Invalid input. Try again. 「(°ヘ°)/ 

Enter number of values: 6 

Enter 6 integers separated by spaces: 2 4 6 8 10 12

Enter the index to start shifting from: 4

Modified values: 10 12 2 4 6 8 

===========================================================
DESIGN:

a) Inputs

length - int
index - int

-----------------------------------------------------------
b) Outputs

If invalid input is provided for length, index, or the array values, the program displays an error message.

After reading the array and shifting it, the program displays the modified array.

-----------------------------------------------------------
c) Calculations

takes user input for the number of values and the array elements, performs input validation to handle invalid entries, and then shifts the array elements based on the provided index then it displays the modified array as the output.

-----------------------------------------------------------
d) Pseudocode
Initialize constants:
  MAX_NUM = 100

Function isValidNum():
  Print "Invalid input. Try again. 「(°ヘ°)/ "
  Clear cin's error flags
  Ignore any remaining input until newline

Function readArray(arr[], length):
  Print "Enter length integers separated by spaces: "
  Read a line of input from the user and store it in a string variable 'input'
  Create a stringstream 'iss' using 'input'
  Loop from i = 0 to length - 1:
    Read an integer from 'iss' and store it in arr[i]
    If the read fails (e.g., non-integer input):
      Call isValidNum()
      Decrement i to re-read the current value

Function shiftList(arr[], length, index):
  For i from 0 to index - 1:
    Store arr[0] in a temporary variable 'temp'
    Shift all elements in 'arr' one position to the left
    Set the last element of 'arr' to 'temp'
  Print "Modified values: "
  For i from 0 to length - 1:
    Print arr[i], followed by a space
  Print a new line

Main program:
  Declare variables:
    length, arr[MAX_NUM], index, loop

  Do the following until a valid length is entered:
    Set loop to false
    Print "Enter number of values: "
    Read 'length' from the user
    If cin fails (e.g., non-integer input):
      Set loop to true
      Call isValidNum()

  Call readArray(arr, length)

  Do the following until a valid index is entered:
    Set loop to false
    Print "Enter the index to start shifting from: "
    Read 'index' from the user
    If cin fails (e.g., non-integer input):
      Set loop to true
      Call isValidNum()

  Call shiftList(arr, length, index)

  End of the program
