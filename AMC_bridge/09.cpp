/*

9. What is the construction order of global variables?
Ans - Global variables are safe only within the same file; across files, order is not guaranteed.

Within one translation unit (.cpp file):
Constructed top to bottom (order of definition).

*/

