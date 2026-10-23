#include <iostream>
#include <cstring>
#include <vector>
#include <variant> //allows for passing unknown of char pointer, int, and float into a function
#include <iomanip> //prints to 2 decimal places

using namespace std;

struct student {
  char firstName[21];
  char lastName[21];
  int id;
  float gpa;
};

bool verifyCorrect(variant<int, char*, float> valuetoprint) {
  while (true) {
    char correct;
    while (correct != 'y' && correct != 'n') {
      cout << "Is \"";
	    switch (valuetoprint.index()) {
	      case 0:
	        cout << get<0>(valuetoprint);
	        break;
	      case 1:
		      cout << get<1>(valuetoprint);
		      break;
	      case 2:
		      cout << fixed << setprecision(2) << get<2>(valuetoprint);
	    }
      cout << "\" correct? (y/n)";
      cin.get(correct);
      while (cin.get() != 10) {}
      if (correct == 'y') {
        return true;
      } else if (correct == 'n') {
	      cout << "Retrying...\n";
		    return false;
      } else {
	      cout << "You must enter y or n.\n";
      }
    }
  }
}
void addCommand(vector<student>& student_list) {
	student temp_student;
	bool correct;
	while (true) {
	  cout << "Enter the student's first name: ";
	  cin.get(temp_student.firstName, 21);
	  while (cin.get() != 10) {}
	  if (verifyCorrect(temp_student.firstName)) {
		  break;
	  }
	}
  while (true) {
    cout << "Enter the student's first name: ";
    cin.get(temp_student.lastName, 21);
    while (cin.get() != 10) {}
    if (verifyCorrect(temp_student.lastName)) {
      break;
    }
  }
}
void printCommand(vector<student>& student_list) {
}
void deleteCommand(vector<student>& student_list) {
}
int main() {
  vector<student> student_list;
  char input[8];
  while (true) {
    cout << "Enter one of ADD, PRINT, DELETE, QUIT to continue. ADD prompts for a new student, PRINT prints the list of students, DELETE deletes one student from the list, and QUIT ends program execution. Input: ";
    cin.get(input, 8);
	while (cin.get() != 10) {}
    if (strlen(input) > 6 && !(strcmp(input, "ADD") || strcmp(input, "PRINT") || strcmp(input, "DELETE") || strcmp(input, "QUIT"))) {
      cout << "Invalid input. Try again.\n";
    } else {
      if (!strcmp(input, "ADD")) {
	addCommand(student_list);
      } else if (!strcmp(input, "PRINT")) {
	printCommand(student_list);
      } else if (!strcmp(input, "DELETE")) {
	deleteCommand(student_list);
      } else if (!strcmp(input, "QUIT")) {
	break;
      }
    }
  }
  return 0;
}
