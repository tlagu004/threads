Name: Thierry Laguerre
Surname: Laguerre 
Panther ID: 6359559
Course code: COP 4610 RVG 1261
Course name:  Operating Systems Principles
Semester: Spring 2026
Professor information: Kiavash Bahreini
Grader/SICA name: Elnaz Toreihi
Grader/SICA email: etoreihi@fiu.edu


Demo Video:https://youtu.be/s3rxuBkJ2Cc

Programming Assignment 2 —Multithreaded Sorting Application
Write a multithreaded sorting program in C that works as follows: A list of integers is divided into two smaller lists of equal size. Two separate threads (which we will term sorting threads) sort each sublist using a sorting algorithm of your choice. The two sublists are then merged by a third thread—a merging thread—which merges the two sublists into a single sorted list.

Because global data are shared across all threads, perhaps the easiest way to set up the data is to create a global array. Each sorting thread will work on one-half of this array. A second global array of the same size as the unsorted integer array will also be established. The merging thread will then merge the two sublists into this second array. Graphically, this program is structured as in the figure below.