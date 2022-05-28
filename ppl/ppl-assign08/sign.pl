%U19CS009
%BRIJESH ROHIT
 
check(N):-
   N=:=0 -> write("You entered 0.\n");
   N>0 -> write("You entered Positive number.\n");
   N<0 -> write("You entered Negative number.\n").   
 
:-
   write("Please enter a number : "),
   read(N),
   check(N).