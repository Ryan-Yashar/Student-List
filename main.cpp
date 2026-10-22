#include <iostream>
#include <cstring>

using namespace std;

int main() {
  struct student {
	char firstName[21];
	char lastName[21];
	int id;
	float gpa;
  }
  void addCommand(char *student_list) {
  }
  void printCommand(char *student_list) {
  }
  void deleteCommand(char *student_list) {
  }
  char input[8];
  while (true) {
    cout << "Enter one of ADD, PRINT, DELETE, QUIT to continue. ADD prompts for a new student, PRINT prints the list of students, DELETE deletes one student from the list, and QUIT ends program execution. Input: ";
    cin.get(input, 8);
	while (cin.get() != 10) {}
    if (strlen(input) > 6 && !(strcmp(input, "ADD") || strcmp(input, "PRINT") || strcmp(input, "DELETE") || strcmp(input, "QUIT"))) {
      cout << "Invalid input. Try again.\n";
    } else {
      if (strcmp(input, "ADD")) {
	addCommand();
      } else if (strcmp(input, "PRINT")) {
	printCommand();
      } else if (strcmp(input, "DELETE")) {
	deleteCommand();
      } else if (strcmp(input, "QUIT")) {
	break;
      }
    }
  }
  return 0;
}
