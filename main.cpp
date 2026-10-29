/*
Student List by Ryan Yashar
Function: Maintains a list of students with their first and last name, student ID, and GPA. Allows for adding and deleting students, as well as printing the list.
  */
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

struct student {
  char firstName[21];
  char lastName[21];
  int id;
  float gpa;
};

bool verifyCorrect(char* valuetoprint) {
  while (true) {
    char correct;
    while (correct != 'y' && correct != 'n') {
      cout << "Is \"" << valuetoprint << "\" correct? (y/n)";
      cin.get(correct);
      while (cin.get() != '\n') {}
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
//determines whether a value is int, float or neither... well sorta
int numType(char* input) {
  int dotcount = 0;
  for (int i=0; input[i]!='\0'; i++) {
    //is the input a numerical value
    if (!('0' <= input[i] && '9' >= input[i])) {
      //is it a dot
      if (input[i] == '.') {
        dotcount += 1;
      } else {
        return 0; //neither int nor float
      }
    }
  }
  if (dotcount == 0) {
    return 1; //int
  } else if (dotcount == 1) {
    return 2; //is float
  } else {
    return 0; //neither int nor float
  }
}
void addCommand(vector<student>& student_list) {
	student temp_student;
	bool correct;
	while (true) {
	  cout << "Enter the student's first name: ";
	  cin.get(temp_student.firstName, 21);
	  while (cin.get() != '\n') {}
	  if (verifyCorrect(temp_student.firstName)) {
		  break;
	  }
	}
  while (true) {
    cout << "Enter the student's last name: ";
    cin.get(temp_student.lastName, 21);
    while (cin.get() != '\n') {}
    if (verifyCorrect(temp_student.lastName)) {
      break;
    }
  }
  char id[21];
  while (true) {
    cout << "Enter the student's ID number: ";
    cin.get(id, 21);
    while (cin.get() != '\n') {}
    if (numType(id) == 1) {
      bool found = false;
      for (student student:student_list) {
        if (student.id == stoi(id)) {
          found = true;
          break;
        }
      }
      if (found) {
        cout << "Error - this ID already exists in the database. Try again.\n";
      } else {
        if (verifyCorrect(id)) {
          temp_student.id = stoi(id);
          break;
        }
      }
    } else {
      cout << "Error - you must enter a positive integer. Try again.\n";
    }
  }
  char gpa[21];
  while (true) {
    cout << "Enter the student's GPA: ";
    cin.get(gpa, 21);
    while (cin.get() != '\n') {}
    if (numType(gpa) != 0) {
      if (verifyCorrect(gpa)) {
        temp_student.gpa = stof(gpa);
        break;
      }
    } else {
      cout << "Error - you must enter a positive number. Try again.\n";
    }
  }
  student_list.push_back(temp_student);
}
bool printCommand(vector<student>& student_list) {
  if (student_list.size()) {
    cout << "Students:\n";
    for (student student : student_list) {
      cout << student.firstName << ' ' << student.lastName << ", ID " << student.id << ", GPA " << student.gpa << '\n';
    }
	return true; //list contains students
  } else {
    cout << "The list is currently empty.\n";
  }
  return false; //list does not contain students
}
void deleteCommand(vector<student>& student_list) {
  if (printCommand(student_list)) {
    char id[21];
    while (true) {
      cout << "Select a student ID to delete: ";
      cin.get(id, 21);
      while (cin.get() != '\n') {}
      if (numType(id) != 1) {
        cout << "You must enter an integer value. Try again.\n";
      } else {
        break;
      }
    }
    int idAt = -1;
    for (int i = 0; i<student_list.size(); i++) {
      if ((student_list[i]).id == stoi(id)) {
        idAt = i;
        break;
      }
    }
    if (idAt != -1) {
      student_list.erase(student_list.begin()+idAt);
      cout << "Student " << id << " deleted.\n";
    } else {
      cout << "Student " << id << " not found.\n";
    }
  }
}
int main() {
  vector<student> student_list;
  char input[8];
  cout << fixed << setprecision(2); //print floats to 2 decimals
  while (true) {
    cout << "Enter one of ADD, PRINT, DELETE, QUIT to continue. ADD prompts for a new student, PRINT prints the list of students, DELETE deletes one student from the list, and QUIT ends program execution. Input: ";
    cin.get(input, 8);
	  while (cin.get() != '\n') {}
    for (int i=0; input[i] != '\0'; i++) {
      if ('a' <= input[i] && 'z' >= input[i]) {
        input[i] -= 32; //capitalize everything
      }
    }
    if (!strcmp(input, "ADD")) {
	    addCommand(student_list);
    } else if (!strcmp(input, "PRINT")) {
	    printCommand(student_list);
    } else if (!strcmp(input, "DELETE")) {
	    deleteCommand(student_list);
    } else if (!strcmp(input, "QUIT")) {
      cout << "Quitting...\n";
	    break;
    } else {
      cout << "Command \"" << input << "\" not found. Try again.\n";
    }
  }
  return 0;
}
