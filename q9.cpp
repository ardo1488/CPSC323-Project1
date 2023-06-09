#include <iostream>

using namespace std;

int main() {
  int transition_table[4][2] = {{2, 0}, {3, 2}, {4, 3}, {0, 4}};

  cout << "Enter a string to check. Use only 'a' and 'b', then end the string "
          "with '$': ";

  const int starting_state = 0;
  int current_state = starting_state;

  int c;
  while ((c = getchar()) != '$' && current_state != -1) {
    int column;
    //cout << "c = " << c << endl;
    if (c == 'a') {
      column = 0;
      //cout << "column = " << column << endl;
    } else if (c == 'b') {
      column = 1;
      //cout << "column = " << column << endl;
    } else {
      cout << "Invalid input, please use only 'a' 'b' or '$'. Try again: ";
      current_state = starting_state;
    }
    current_state = transition_table[current_state][column];
    // Correct for zero-based array indexing.
    --current_state;
    //cout << "Current state = " << current_state << endl << endl;
  }

  if (current_state == 2 || current_state == 3) {
    //cout << "State = " << current_state << " String accepted." << endl;
    cout << "YES" << endl;
  } else {
    //cout << "State = " << current_state << " String rejected." << endl;
    cout << "NO" << endl;
  }

  return 0;
}
