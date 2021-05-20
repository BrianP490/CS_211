/**********************************************************
Homework 1
Brian Perez
9/20/19

This program is a type of gradebook for a specific course. For each student registered in this course, the program keeps track of the student's name, identification number (id), four exam grades, and final grade. The program performs several functionalities such as: enrolling a student in the course, dropping a student from the course, uploading student's exam grades, displaying the grades of a specific student, displaying the grades of all students in the course, and printing grades summary information.  
**********************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

//struct declaration
struct Student
{
  string name;//storing the name
  long id;//storing the id number
  double grades[4];//storing the grades
  double finalGrade;//store the final grade
};
//function prototypes
void Enroll(ifstream& fin, vector <Student>& students);
void Print(const vector <Student>& students);
void UploadGrades(ifstream& fin, vector <Student>& students);
void Drop(ifstream& fin, vector <Student>& students);
void Search(ifstream& fin,const vector <Student>& students);
void Display(const vector <Student>& students);

int main()
{
  ifstream fin;//fin is the file that is being read
  vector <Student> students;//declare the student structure vector
  string command;//recieves the command from fin

  fin.open("StudentsTrans.txt");//open the file
  if(!fin)//if the file cannot be opened
    {
      cout << "Error opening file" << endl;
    }
  else
    {
      fin >> command;//read the command in from file
      
      //this while loop will determine what will occur
      while(fin)//proceed if a command was recieved
	{
	  if(command == "enroll")
	    {
	      cout << "Enroll: ";
	      Enroll(fin, students);//call the enroll function
	    }
	  else if(command == "display")
	    {
	      cout << "\nDisplay:" << endl;
	      Display(students);//call the desplay function
	    }
	  else if(command == "uploadGrades")
	    {
	      cout << "\nUploading Grades: " << endl;
	      UploadGrades(fin, students);//call the upload function
	    }
	  else if(command == "drop")
	    {
	      cout << "\nAttempting to Drop "; 
	      Drop(fin, students);//call the drop function	
	    }
	  else if(command == "searchByName")
	    {
	      cout << "\nSearch by name: ";
	      Search(fin, students);//call the search function
	    }
	  else if(command == "printClassSummary")
	    {
	      cout << "\nPrint Class Summary: " << endl;
	      Print(students);//call the print function
	    }
	  
	  fin >> command;//get the next command 
	}   
    }
  return 0;//end the program
}
/*****************************************************************************
This function called Enroll will read the first and last name, and Id number. It will store the student if they are a new student as well as initialize their scores to zero.
The fin parameter will be used to read the inpur file stream "StudentsTrans.txt".  The student vector will be needed to add students
*****************************************************************************/
void Enroll(ifstream& fin, vector <Student>& students)
{
  bool preReg = false;//a variable to check if the student was preregistered
  long Id;//a variable for their Id numb
  string Fname, Lname;//holds the student's first and last name
  
  Student tempStu;//make a temporary student structure
  
  fin >> Fname >> Lname >> Id;//get info(first name, last name , and id number) from file
  
  if(students.size() != 0)//checks to see if there are students in vector
    {
      for(int i = 0; i < students.size() ; i++)//goes throught the vector to find any preregistered students
	{
	  if(Id == students[i].id)
	    {
	      preReg = true;
	      cout << "Student was already registered into this class, cannot enroll again." << endl;
	    }
	}
    }
  
  if(!preReg || students.size() == 0)//if the student is the first student to be added or a fresh new student, then go into the for loop
    {
      tempStu.name = Fname + " " + Lname;//combine the names and store it in the temporary struct in name 
      tempStu.id = Id;//store the id as a temporary value    
      
      //initialize the array for the grades and final grade
      for(int i = 0; i < 4; i++)
	{
	  tempStu.grades[i]= 0;
	}

      tempStu.finalGrade = 0;
      students.push_back(tempStu);//insert the student into the vector 
      
      cout << tempStu.name << " has been successfully added to students vector." << endl;//print a success message
    }
}
/*****************************************************************************
This function called UploadGrades will update the grades for the students and find the average test grades for each student. 
The fin parameter will be used to read the inpur file stream" studentstrans.txt. 
The student vector parameter will be needed to add students into the class
*****************************************************************************/  
void UploadGrades(ifstream& fin, vector <Student>& students)
{
  double T1, T2, T3, T4;//variables for the test scores
  long Id;//store the Id
  bool found = false;

  fin >> Id;//get the Id from the input file 

  for(int i = 0; i < students.size(); i++) 
    {
      if(Id == students[i].id)
	{
	  fin >> T1 >> T2 >> T3 >> T4; //get scores from input file
	  found = true;
	  students[i].grades[0] = T1;  //store the scores into the vector
	  students[i].grades[1] = T2;
	  students[i].grades[2] = T3;
	  students[i].grades[3] = T4;

	  students[i].finalGrade = (T1 + T2 + T3 + T4)/4;  //save the average test score of the studentinto the vector 
	  cout << students[i].name << "'s grades were successfully uploaded." << endl;
	}
    }

  if(!found)//output error message
    {
      cout << "No such student exists, grades can not be uploaded." << endl;
    }
}
/*****************************************************************************
This function, called Drop, will erase the student with the requested Id only if the student exists
The fin parameter will be used to read the inpur file stream" studentstrans.txt.  
The student vector parameter will be needed to add students into the class
*****************************************************************************/
void Drop(ifstream& fin, vector <Student>& students)
{
  long Id; //store the Id number
  bool found = false;
  fin >> Id;

  for(int i = 0; i < students.size(); i++)//check the students vector
    {
      if(Id == students[i].id)//if the student was found, enter the loop
	{
	  found = true;  //the student has been found in the vector;set found as true
	  cout << students[i].name << "\n" << students[i].name << " was successfully deleted" << endl;	  
	  students.erase(students.begin() + i);   //erase the student in the vector
	  
	} 
    }

  if(!found) //send message saying the student was not found
    {
      cout << Id << "\nStudent does not exist" << endl;//print message
    }
}
/*****************************************************************************
This search function will print out the students whose first names, last names, or full names if they match a keyword.
The fin parameter will be used to read the inpur file stream" studentstrans.txt. The student vector parameter will be needed to add students into the class.
*****************************************************************************/
void Search(ifstream& fin, const vector <Student>& students)
{
  string Key, Ftemp, Ltemp;//store the key words, the first name of the temp(Ftemp) and the last name of the temp(Ltemp)
  string Fname,Lname; //student first name(Fname) and last name(Lname)
  bool found = false;//found variable will be checked to see if the student was found

  fin >> Key;//get the key word(s) from the input file stream
  cout << Key;

  //this stringstream s is going to break up the search key terms into first and last temporary variables
  stringstream s(Key);//s is going to contain a full name: first and last
  s >> Ftemp;
  s >> Ltemp;

  cout << left << setw(19) << "\nStudent" << setw(11) << "ID" << setw(8) << "Exam1" << setw(8) << "Exam2" << setw(8) << "Exam3" << setw(8) << "Exam4" << setw(20) << "Final Grade" << endl << "-----------------------------------------------------------------------------------\
" << endl;//cout the display prompt

  for(int i = 0; i < students.size(); i++)//go inside the vector of students until there are no more students
    {
      stringstream t(students[i].name);//break down the student's name into first and last name storing them in seperate variables using string streams
      t >> Fname;
      t >> Lname;

      if(Key == students[i].name || Ftemp == Fname || Ftemp == Lname)//if we found a match, display their stats
	{
	  found = true;//change the boolean variable

	  cout << left << setw(19) << students[i].name << setw(11) << students[i].id;
	  for(int j = 0; j < 4; j++)  //look through the students' four test scores and print them
	    {
	      cout << left << fixed << setprecision(2) << setw(8) << students[i].grades[j];
	    }
	  cout << setw(20) << students[i].finalGrade << endl;//print the final grade
	}
    }      
      
  if(!found)//error message
    {
	  cout << "No student was found. " << endl;//print message
    }
}
/*****************************************************************************
This function displays all the students in the vector showing the test scores and their Id numbers.
The student vector parameter will be needed to show the students from the class
*****************************************************************************/
void Display(const vector <Student>& students)
{
  cout << left << setw(19) << "Student" << setw(11) << "ID" << setw(8) << "Exam1" << setw(8) << "Exam2" << setw(8) << "Exam3" << setw(8) << "Exam4" << setw(20) << "Final Grade" << endl << "-----------------------------------------------------------------------------------" << endl;//print message prompt
  
  int i = 0;//initialize i outside of the loop to use anywhere in this function
  for(i = 0; i < students.size(); i ++ )  //go through each of the students in the vector
    {
      cout << left << setw(19) << students[i].name << setw(11) << students[i].id;
     
      for(int j = 0; j < 4; j++)  //look through the students' four test scores
        {
	  cout << left << fixed << setprecision(2) << setw(8) << students[i].grades[j];
	}
      cout << setw(20) << students[i].finalGrade << endl;//print final grade
    }  
}
/*****************************************************************************
This function displays the person with the highest final grade, the person with the lowest grade, and calculates the class average.
The students vector will get the vector from main to use it to print the class info
*****************************************************************************/
void Print(const vector <Student>& students)
{
  double highest = students[0].grades[0];//set the highest score defaulted at the first score of the first test score 
  double lowest = students[0].grades[0];//saves the lowest test score
  string Hname, Lname;//store the names of the people with the highest and lowest score
  double sum = 0;
  int i;//counter for vector

  for(i = 0; i < students.size(); i++)//go throught the vector
    {
      sum += students[i].finalGrade;//add up the students' final scores
      
      if(students[i].finalGrade > highest)//if score is greater than highest
	{	
	  highest = students[i].finalGrade;//adjust highest
	  Hname = students[i].name; //store the name of the student
	}

      if(students[i].finalGrade < lowest)//if score is less than lowest score
	{
	  lowest = students[i].finalGrade;//adjust lowest
	  Lname = students[i].name;//store the student's last name
	} 
    }
  //print the highest and lowest grade as well as their owners
      cout << "The student with the highest final grade is: " << Hname << " with " << highest <<  "%" << endl; 
      cout << "The student with the lowest final grade is: " << Lname << " with " << lowest <<  "%" << endl; 
      cout << "The overall class average is " << sum/i << "%" << endl; //calculates the avg as the message is printing on-screen 
}
