*******************************************************
*  Name      :  Nate Dore    
*  Student ID:  105956145               
*  Class     :  CSC 2421          
*  HW#       :  1                
*  Due Date  :  05 FEB 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This collection is an implementation of the given class: ArrayBag. 
ArrayBag is an ADT, that in this case contains a list of ints.
I have implemented overloaded operators '+' & '-' (aka the union and difference operators)
for added functionality. Also, I have created a dynamic data parser, that given the correct format,
will correctly parse any given amount of lines of integers. Each line will become it's own 'bag'
 


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that constructs an instances of the 
   class ArrayBag. A data file is then parsed and assigned to the first two instances of 
   ArrayBag. The third event is the union of bag1 and bag2, being assinged to bag3. 
   This demonstrates the functionality of the overloaded operators. 
   
   Also in main.cpp the function vector<ArrayBag> parseInputIntoBags() is defined.
   This function takes a formatted input file and creates the appropriate amount of 
   ArrayBags. The complicated method to doing so lies in creating multiple vectors of 
   the input file, and then parsing those respectively into seperate vectors. The data
   is initially taken in as a single string, and then broken down into sub-strings, based on 
   delimiters (in this case first '\n' and then ' '). Once the data is in a matrix of strings,
   it is then converted into a matrix of integers, and added to each bag seperately.

Name: ArrayBag.h
   Contains the definition for the class ArrayBag.  

Name: ArrayBag.cpp
   Defines and implements the ArrayBag class for starting an ADT collection.
   Note three added functions: The overloaded operators (union and difference),
   as well as a new function 'addList' which takes in a vector and adds it to 
   the specific ArrayBag as long as there is room. 
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully on ouray.cudenver.edu as long as compiling under c++11 with g++.  
