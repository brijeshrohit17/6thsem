%U19CS009
%BRIJESH ROHIT

add(A,B,Sum):-
    Sum is A+B.
sub(A,B,Diffs):-
    Diffs is A-B.
mul(A,B,Prod):-
    Prod is A*B.
div(A,B,Quo):-
    Quo is A/B.

start:-
    write("Please enter first number : "),
    read(A),
    write("Please enter second number : "),
    read(B),
    write("Please enter\n"),
    write("1 : Add two numbers\n"),
    write("2 : Subtract two numbers\n"),
    write("3 : Multiply two numbers\n"),
    write("4 : Divide two numbers\n"),
    write("Enter your choice: "),
    read(C),
    (C=:=1 ->
        (add(A,B,Sum),
        write("Addition : "),
        write(Sum),nl)
;   C=:=2 ->
        (sub(A,B,Diff),
        write("Difference : "),
        write(Diff),nl)
;   C=:=3 ->
        (mul(A,B,Prod),
        write("Product : "),
        write(Prod),nl)
;   C=:=4 ->
        (B=:=0 ->
            write("Division not possible!!\n")
        ;   div(A,B,Quo),
            write("Quotient : "),
            write(Quo),nl))
;   C=:=5 ->
        (
            halt
        )
;   start.

:-
    start.