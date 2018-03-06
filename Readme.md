*******************************************************
*  Name      :  Nathaniel Dore        
*  Student ID:  105956145               
*  Class     :  CSC 2421           
*  HW#       :  1                
*  Due Date  :  05MAR2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************


this program reads in a list of words from a file called dictionary.txt
and stores them in a stl list of type DictEntry. The stored list is then
sorted and searched for certain words. Specific search words are contained
within findwords.txt. A output file called revsorted.txt contains a reversed
sorted list of the original contents contained in dictionary.txt (the contents
of the featured list). 


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from two input files, one containing the contents to 
   be created into a dictionary and one to be used to parse in search
   words. The dictionary is then sorted and displayed, as well as searched
   with results displayed. Finally the dictionary list is stored in an output
   file.

Name:  DictEntry.h
   Contains the definition for the class DictEntry, as well as the member 
   function declarations and definitions. Contains a wordType word and 
   an unused definition variable. 

Name: dictionary.h
   Contains the definition for the dictionary class.

Name: dictionary.cpp
   includes functions to create a dictionary list of type DictEntry. This 
   List can be sorted, and searched in multiple ways. The list may also be 
   stored in an output file of specified name.

   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed in VS 2015 community and tested on gnu g++ 4.4.2.  
   It was compiled, run, and tested on gcc ouray.cudenver.edu.