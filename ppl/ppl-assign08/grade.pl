%U19CS009
%BRIJESH ROHIT

check(P):-
    P=<100,P>=80, write("A"),nl;
    P<80,P>=60, write("B"),nl;
    P<60,P>=35, write("C"),nl;
    write("D"),nl.
:-
    write("Please enter percentage : "),
    read(P),
    write("Your Grade : "),
    check(P).
    