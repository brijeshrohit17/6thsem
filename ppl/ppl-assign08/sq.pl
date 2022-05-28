%U19CS009
%BRIJESH ROHIT

check(L,B):-
    L=:=B 
    ->  write("It is a square!!\n")
    ;   write("It is not a square!!\n").

:-
    write("Enter Length : "),
    read(L),
    write("Enter Breadth : "),
    read(B),
    check(L,B).