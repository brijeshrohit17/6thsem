%write a program to input a character repeatedly than decicde whether it is uppercase lowercase or a number, program should exit when entered space

checktype(A):-
    (A>="a", A=<"z") -> write('Is is a lowercase cahracter!!\n'),!;
    (A>="A" , A=<"Z") -> write('It is a uppercase character!!\n'),!;
    (A=:=0 ; A >= 1 , A =< 9) -> write('It is a number\n'),!;
    write("It is a special character").

:-
    write("Please input a character : "),
    read(A),
    checktype(A).