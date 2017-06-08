
// Catalan's Number -
answer to 3 eqv problems :
>No of ways of correctly parenthesising
>Dycks words of length 2n (each prefix of the string has no of X >= no of Y)
Reduced to >Number of paths without crossing the diagonal
-> Solved by : 
	>Create a line CD parallel to the diagonal AB in the upper(crossing) side.
	> Reflection of A in line CD will be at F(-1,1). 
	>All "incorrect" paths must have a point on CD, call the first such point E.
	>

 void some_function(const vector<int>& v) { // OK 
      // ... 
 } 
If you are going to change the contents of vector in the function, just omit the ‘const’ modifier.
 void some_function(vector<int>& v) { // OK but less usual