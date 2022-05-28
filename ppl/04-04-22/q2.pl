%write a program to find and print every kind of roots of quadratic equation

calc(A,B,C):-
    Z is B*B-4*A*C,
    A1 is 2*A,
    Z =:= 0 ->
        write("Roots are equal!!"),nl,
        write("Roots : "),
        R1 is (-B+sqrt(Z))/(A1),
        R2 is (-B-sqrt(Z))/(A1),
        write(R1), write(" and "),write(R2),nl;
    Z > 0 ->
        write("Roots are real and unique!!\n"),
        write("Roots : "),
        R1 is (-B+sqrt(Z))/(A1),
        R2 is (-B-sqrt(Z))/(A1),
        write(R1), write(" and "),write(R2),nl;
    Z < 0 ->
        write("Roots are imaginary!!\n"),
        write("Roots : "),
        R1 is -B/(A1) + sqrt((Z)/(A1)),
        R2 is -B/(A1) - sqrt((Z)/(A1)),
        I1 is -Z,
        write(R),write(" + i"), write(I1), write(" and "), write(R),write(" - i"),write(I1),nl.

check(A):-
    A=:=0->
    write("A cannot be 0!!\n"),halt;
    !.

:-
    write("Enter a : "),
    read(A),
    check(A),
    write("Enter b : "),
    read(B),
    write("Enter c : "),
    read(C),
    calc(A,B,C).