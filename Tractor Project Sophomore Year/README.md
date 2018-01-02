Here are the instructions given to the class for the Tractor Project:


In this assignment you will implement a simple framework for a “Little Farm” RTS game. You might need it later for further assignments so make sure it is written and documented well.

 

There should be a header file with declarations Game.h (declare all classes in it) and a file with implementations Game.cpp (implement all classes in it). The header file should have a protection against multiple declarations. All methods should make a good use of const keyword and references.  To avoid unnecessary hints, I do not include const and references in the description of the methods, but they should be there!

This is important: please make sure that all files, the classes themselves and all methods are named exactly as specified in this assignment! If, for example, parameters in a method do not match my specification, my driver-program will report me that the method doesn’t work, and you will lose points or even get fail the homework!

 

The assignment should be submitted ONLY through the Blackboard. No late submissions! Your program should compile and run on our Linux Lab computers. The assignment should be completed individually. You are responsible for every statement in your project (check our syllabus for more details).

When grading, I will first check if the classes work as specified. This check will be automatic, so if you do not follow the specification, it will show as wrong. Not implementing a method costs a lot of points. So make sure everything works! Then I will evaluate your programming style. Missing a const keyword or adding it where it shouldn’t be, forgetting to use #ifndef , using meaningless or misleading variable names– all of it will cost a significant number of points. Think about the following breakdown:

Program that doesn’t compile or doesn’t do what it needs to do is always 0 points. If your program works then:
Program working correctly: 80%
Program using a safe programming style: 15%
Readability: 5%
 

I advise you to not wait until the very last moment. You are welcome to ask questions during and after the class. Feel free to show me your programs after the class for a quick initial check.

Feel free to add more methods and variables as long as the specified interface stays the same.

 

 

 

ASSIGMNENT

 

The following type should be defined:

enum Activity {SEEDING, HARVESTING, MOVING, IDLE}

 

Class Tractor

 

Class Tractor stores the following data:

 

int x – x coordinate of the tractor.
int y – y coordinate of the tractor.
unsigned short size – size of the tractor. Each tractor is a square with the edge of size size with the center at (x,y) .
Activity activity – current activity.
 

 

Class Tractor should have accessor and modifier methods for every field mentioned above. Also, it should have two constructors:

 

Tractor() – the default constructor that sets all fields to some default values (choose them yourself).

Tractor(int x_val, int y_val, unsigned short size_val, Activity activity_val) – the constructor that sets all fields to the given values.
 

 

Class Game

 

Class Game stores the following data:

unsigned int  map_size – size of the game map. The bottom-left corner of the map has the coordinates (0,0). The map is always square.

vector<Tractor> all – list of all tractors on the map
  
vector<int> selected – indexes of all units currently selected in all-vector.
 

 

Class Game has the following methods:

Game(unsigned int new_size) – the default constructor that initializes an empty Game object for the map of new_size.
int GetTractor( int x, int y ) – returns the index in all-vector of the tractor that occupies location (x,y). Pay attention: location (x,y) belongs to the square where the unit is positioned. If there is no unit on (x,y), the function should return a negative value -1.

void SelectTractor( int x, int y ) – selects the tractor located on (x,y). Selecting tractor means you should empty the selected-vector and put the index of the selected tractor in it. Just as in case of GetTractor () method, point (x,y) should belong to unit’s square. If there is no unit at (x,y) the method should simply empty the selected-vector.

void SelectTractors( int x1, int y1, int x2, int y2 ) – selects all tractors located in the rectangular defined by (x1,y1) and (x2,y2). Functions exactly like SelectTractor method, but this time we add to the selected-vector the indexes of the all tractors whose squares at least partially intersect with the rectangle given by points (x1,y1) and (x2,y2).

void AddTractor( Tractor new_unit) – adds the new tractor to all-vector.

bool MoveTractor( int i, int new_x, int new_y ) – moves the tractor number i to the new coordinates if it is possible and returns true value to signal the success. If moving is not possible, leave the tractor at initial position and return false value. Tractor can be moved to the new position (new_x, new_y) if in this position his square does not overlap with a square of another tractor and if in this position tractor does not go off the map even partially. 

void AssignTractorsActivity(Activity new_activity) – sets the new_activity for all selected tractors.

void PrintTractor( int i ) – prints the tractor number i from the all-vector. In other words, print all fields of that unit.

void PrintSelectedTractors() – prints selected units. Make sure the output is readable.

void PrintAllTractors() – prints all units.
 

 

Good luck!
