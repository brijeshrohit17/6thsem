%U19CS009
%BRIJESH RHOIT

leap(Y):-
    Y mod 400 =:= 0 , write("It is a Leap Year!!\n");
    Y mod 100 =:= 0 , write("It is not a Leap Year!!\n");
    Y mod 4   =:= 0 , write("It is a Leap Year!!\n");
    write("It is not a Leap Year!!\n").

:-
    write("Please enter a year : "),
    read(Y),
    leap(Y).