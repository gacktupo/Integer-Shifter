/******************************************************************************
# Author:           Courtney T. 
# Lab:              Discussion #4
# Date:             July 20th, 2023
# Description:      This program prompts user for an amount of integers, enter the integers, index to shift from, shifts the integers and displays the modified integers. 
# Input:            length, index
# Output:           modified array, invalid message
# Sources:          None
#******************************************************************************/
#include <cstring>
#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

const int MAX_NUM = 100;

// function prototypes
bool isValidNum();
void readArray(int arr[], int length);
void shiftList(int arr[], int length, int index);

int main(void) {
  int length;
  int arr[MAX_NUM];
  int index;
  bool loop;

  do {
    loop = false;
    cout << "Enter number of values: ";
    cin >> length;
    if (cin.fail()) {
      loop = isValidNum();
    }
  } while (loop);

  readArray(arr, length);

  do {
    loop = false;
    cout << "\nEnter the index to start shifting from: ";
    cin >> index;
    if (cin.fail()) {
      loop = isValidNum();
    }
  } while (loop);

  shiftList(arr, length, index);

  return 0;
}

//Name:   isValidNum()
//Desc:   Input validation 
//input:  none
//output: invalid input message
//return: true
bool isValidNum() {
  cout << "\nInvalid input. Try again. 「(°ヘ°)/ \n" << endl;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return true;
}
//Name:   readArray()
//Desc:   read user input 
//input:  arr
//output: enter integers seperated by spaces
//return: void
void readArray(int arr[], int length) {
  string input;
  cout << "\nEnter " << length << " integers separated by spaces: ";
  cin.ignore(); // Ignore any leftover newline from previous input
  getline(cin, input);

  istringstream iss(input);
  for (int i = 0; i < length; ++i) {
    if (!(iss >> arr[i])) {
      isValidNum();
      --i;
    }
  }
}

//Name:   shiftList()
//Desc:   Modifies user input to display modified values
//input:  none
//output: modified values, arr[]
//return: void
void shiftList(int arr[], int length, int index) {
  int temp;
  for (int i = 0; i < index; i++) {
    temp = arr[0];
    for (int j = 0; j < length - 1; j++) {
      arr[j] = arr[j + 1];
    }
    arr[length - 1] = temp;
  }

  cout << endl << "Modified values: ";
  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
}
