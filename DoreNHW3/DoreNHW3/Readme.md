*******************************************************
*  Name      :  Nathaniel Dore
*  Student ID:  105956145
*  Class     :  CSC 2421           
*  HW#       :  3                
*  Due Date  :  12FEB2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program is meant to format a input file called data.txt. The file is 
formatted so that there is a max number of characters per line. This max 
number is provided by the user. If the limit is exceeded, a newline 
character is inserted. If this occurs during the middle of a word, a
 hyphen distinguishes the continuation of the word on the next line.
 The new created data file is then stored in "data.out"


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from an input file, and reformat the file using the specified
   circumstances.

Name:  mystring.h
   Contains the definition for the class my_string.  

Name: mystring.cpp
  This is a simple version of the Standard Library string. 
  It is part of the namespace main_savitch_4, from the textbook
  "Data Structures and Other Objects Using C++"
  by Michal Main and Walter Savitch
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed in Visual Studios 2015 and tested on gnu g++ 4.4.2.  It was 
   compiled, run, and tested on gcc ouray.cudenver.edu.
