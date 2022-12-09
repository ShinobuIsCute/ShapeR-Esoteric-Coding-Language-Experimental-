# ShapeR Esoteric Coding Language Experimental

Experimental esoteric coding language that will compile differently based on what your code looks like to a human.

## Support for the following things will be added in version 1.0
- Commenting/Special characters
- Variables (integers (4 bytes) and ASCII characters (1 byte))
- Arrays/Strings
- Basic I/O (can take input from user and output to the user)
- Basic mathematical operations with variables (of same type) -> addition (+), subtraction (-), multiplication (\*), division (/) and modulus (%) 
- Relational operators ('==', '!=', '<=', '>=', '<' and '>')
- Conditional Statements such as an if..else statement
- Loops such as the 'for' loop and the 'while' loop
- User defined functions

## Support for the following things may be added in later versions
- Logical Operators -> and (&&) , or (||) , not (!)
- Bitwise Operations


## Special Characters
- '~' -> Filler character. It should be used to complete a shape without affecting the code.
- '\' -> Escape character. Use this character before a special character if you need to use the special character in a string.
- '//' -> Comment. Should be used to create commments where necessary.

## Variables & Arrays
- Variables can be defined by integrating their definition into a rectangle shape. 
- Start the line with 'd' to represent an integer or integer array, or 's' to represent a character/string.

Example:
```
  d int_array [1, 2, 3, 4]
  d  sum 7 ~~~~~~~~~~~~~~~
  s  test_string abc~~~~~~
  s  test_char \~~~~~~~~~~
```
-> In the example above, int_array is an array of integers equal to [1, 2, 3, 4], integer sum is equal to 7, character test_char is '~' and character array (string) test_string is equal to 'abc'.

## Input/Output
- User input is described by a right facing triangle with the variable/s that will store the input in the centre.
- Prgoram Output is described by a left facing triangle with the variable/s that will be output in the centre.

Example:
```
       ~  
      ~~  
     ~~~    
    ~~~~  
d  input 
    ~~~~
     ~~~
      ~~
       ~
```
-> In the example above, input is an integer variable that will contain the integer value that the user enters.

## Mathematical Operations
- Upwards facing triangle indicates next 'x' lines of code for mathematical operations where x is the number of lines of the triangle.

## Relational Operations
- Downwards facing triangle indicates next 'x' lines of code for relational operations where x is the number of lines of the triangle.

## If..else Statements
- We will use a semicircle facing left to indicate that there is an if statement for the next 'x' lines of code where x is the radius of the semicircle squared.

## Loops
- We will use a semicircle facing right to indicate that there is a for loop or while loop for the next 'x' lines of code where x is the radius of the semicircle squared.

## Functions
- A rhombus will be used to indicate that there is a function definition in the next 'x' lines of code where x is the area of the rhombus.
- A 2x2 rhombus will indicate a function call (therefore the minimum rhombus size will be 3x3).

Example:
```
 ~
~~~
 ~
function_name
```
Test Changer