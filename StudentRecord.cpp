#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int choice;
int deleteID;
int searchID;

void displayMenu()
{
   cout << "\n==========STUDENT RECORDS==========\n"
        << endl;
   cout << "What would you like to do? Please type a number to proceed" << endl;
   cout << "1. Add a student" << endl;
   cout << "2. Display the student record" << endl;
   cout << "3. Delete a student record" << endl;
   cout << "4. Search Student" << endl;
   cout << "5. Update A Student" << endl;
   cout << "6. Exit" << endl;
}
void getchoice()
{
   cin >> choice;
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid Answer, Please Pick A Number!" << endl;
   }
}

struct student
{
   string name;
   int id;
   string address;
   int age;
   int exam_score;
   int quiz_score;
   string quiz_result;
   string exam_result;
};

void getstudent_age(student &temp)
{
   while (true)
   {
      cin >> temp.age;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid Answer, Please Type A Number!" << endl;

         continue;
      }

      if (temp.age <= 17 || temp.age >= 26)
      {
         cout << "Only 18 to 25 years old are valid" << endl;
         continue;
      }
      break;
   }
}
void getstudent_quizscore(student &temp)
{
   while (true)
   {
      cin >> temp.quiz_score;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid Answer, Please Type A Number!" << endl;

         continue;
      }
      if (temp.quiz_score > 50 || temp.quiz_score < 0)
      {
         cout << "Invalid Answer! Only 50 items in Quiz is taken. Please try again: ";
         continue;
      }
      break;
   }
   if (temp.quiz_score >= 38)
   {
      temp.quiz_result = "Passed";
   }
   else
      temp.quiz_result = "Failed";
}

void getstudent_examscore(student &temp)
{
   while (true)
   {
      cin >> temp.exam_score;

      if (cin.fail())
      {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid Answer, Please Type A Number!" << endl;
         continue;
      }
      if (temp.exam_score > 100 || temp.exam_score < 0)
      {
         cout << "Invalid Answer! Only 100 items in Exam is taken Please try again: ";
         continue;
      }
      break;
   }
   if (temp.exam_score >= 80)
   {
      temp.exam_result = "Passed";
   }
   else
      temp.exam_result = "Failed";
}

void getstudentID(student &temp, vector<student> &students)
{
   bool idexist = false;

   do
   {
      while (true)
      {
         cin >> temp.id;
         if (cin.fail())
         {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Answer, Please Type A 4 Digit Number!" << endl;
            continue;
         }
         if (temp.id < 1000 || temp.id > 9999)
         {
            cout << "Invalid answer, only put A 4 Digit Number!" << endl;
            continue;
         }
         break;
      }

      idexist = false;
      for (int i = 0; i < students.size(); i++)
      {
         if (students[i].id == temp.id)
         {
            idexist = true;
            cout << "ID already exist, Please try again" << endl;
            break;
         }
      }
   } while (idexist);
}

void searchstudentID(vector<student> &students)
{
   cout << "Please type the student's ID to find and display his/her information: ";
   while (true)
   {
      cin >> searchID;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid Answer, Please Type A 4 Digit Number!" << endl;
         continue;
      }
      break;
   }

   bool found = false;
   for (int i = 0; i < students.size(); i++)
   {
      if (searchID == students[i].id)
      {
         cout << "Student's Record #" << i + 1 << endl;
         cout << "Student #" << i + 1 << endl;
         cout << "Name: " << students[i].name << endl;
         cout << "Age: " << students[i].age << endl;
         cout << "ID: " << students[i].id << endl;
         cout << "Address: " << students[i].address << endl;
         cout << "Quiz Score: " << students[i].quiz_score << endl;
         cout << "Quiz Result: " << students[i].quiz_result << endl;
         cout << "Exam Score: " << students[i].exam_score << endl;
         cout << "Exam Result: " << students[i].exam_result << endl;
         cout << endl;
         found = true;
         break;
      }
   }
   if (!found)
   {
      cout << "ID Not Found!" << endl;
   }
}
void updateID(student &temp)
{
   while (true)
   {
      cin >> temp.id;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid Answer, Please Type A 4 Digit Number!" << endl;
         continue;
      }
      if (temp.id < 1000 || temp.id > 9999)
      {
         cout << "Invalid answer, only put a 4 Digit Number!" << endl;
         continue;
      }
      break;
   }
}
void updatestudent(vector<student> &students)
{
   cout << "To update a student's information, enter His/Her ID: " << endl;
   while (true)
   {
      cin >> searchID;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid Answer, Please Type A 4 Digit Number!" << endl;
         continue;
      }
      break;
   }
   bool found = false;
   for (int i = 0; i < students.size(); i++)
   {
      if (searchID == students[i].id)
      {
         cout << "Student's Record #" << i + 1 << endl;
         cout << "Student #" << i + 1 << endl;
         cout << "Name: " << students[i].name << endl;
         cout << "Age: " << students[i].age << endl;
         cout << "ID: " << students[i].id << endl;
         cout << "Address: " << students[i].address << endl;
         cout << "Quiz Score: " << students[i].quiz_score << endl;
         cout << "Quiz Result: " << students[i].quiz_result << endl;
         cout << "Exam Score: " << students[i].exam_score << endl;
         cout << "Exam Result: " << students[i].exam_result << endl;
         cout << endl;
         found = true;

         cout << "Updating the information, Please provide the following: " << endl;
         cout << "Enter a Student Name: ";
         cin.ignore(1000, '\n');
         getline(cin, students[i].name);
         cout << "Enter the Student's Age: ";
         getstudent_age(students[i]);
         cout << "Enter ID: ";
         updateID(students[i]);
         cout << "Enter Address: ";
         cin.ignore(1000, '\n');
         getline(cin, students[i].address);
         cout << "Enter Quiz Score (Over 50): ";
         getstudent_quizscore(students[i]);
         cout << "Enter Exam Score (Over 100): ";
         getstudent_examscore(students[i]);
         break;
      }
   }
   if (!found)
   {
      cout << "ID Not Found!" << endl;
   }
}


int main()
{
   vector<student> students;

   do
   {
      displayMenu();
      getchoice();
      cout << endl;

      if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
      {
         cout << "INVALID ANSWER. PICK A NUMBER AGAIN" << endl;
         cout << endl;
      }

      switch (choice)
      {
      case 1:
      {
         student temp;
         cout << "Enter a Student Name: ";
         cin.ignore(1000, '\n');
         getline(cin, temp.name);

         cout << "Enter the Student's Age: ";
         getstudent_age(temp);

         cout << "Enter ID: ";
         getstudentID(temp, students);

         cout << "Enter Address: ";
         cin.ignore(1000, '\n');
         getline(cin, temp.address);

         cout << "Enter Quiz Score (Over 50): ";
         getstudent_quizscore(temp);

         cout << "Enter Exam Score (Over 100): ";
         getstudent_examscore(temp);

         students.push_back(temp);
         break;
      }

      case 2:
      {
         cout << "\nStudent Records\n"
              << endl;

         for (int i = 0; i < students.size(); i++)
         {
            cout << "Student #" << i + 1 << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Address: " << students[i].address << endl;
            cout << "Quiz Score: " << students[i].quiz_score << endl;
            cout << "Quiz Result: " << students[i].quiz_result << endl;
            cout << "Exam Result: " << students[i].exam_result << endl;
            cout << "Exam Score: " << students[i].exam_score << endl;
            cout << endl;
         }
         break;
      }
      case 3:
      {
         cout << "Please type the student's ID to delete his/her record: ";
         while (true)
         {
            cin >> deleteID;
            if (cin.fail())
            {
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               cout << "Invalid Answer, Please Type A 4 Digit Number!" << endl;
               continue;
            }
            break;
         }

         bool found = false;
         for (int i = 0; i < students.size(); i++)
         {
            if (deleteID == students[i].id)
            {
               students.erase(students.begin() + i);
               found = true;
               cout << "Student's Record #" << i + 1 << " is Deleted Successfuly" << endl;
               break;
            }
         }
         if (!found)
         {
            cout << "ID Not Found!" << endl;
         }
      }
      break;
      case 4:
      {
         searchstudentID(students);
      }
      break;
      case 5:
      {
         updatestudent(students);
      }
      break;
      case 6:
      {
         cout << "Thank you for using this program!" << endl;
         break;
      }
      }
   } while (choice != 6);
}
