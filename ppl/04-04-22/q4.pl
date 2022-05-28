%wap to print all the fibonacci numbers upto a given entered number n

fib(N1,N2,N):-
    N3 is N1+N2,
    N3 =< N -> write(N3), write(" "),fib(N2,N3,N).

:-
    write("Please enter a number : "),
    read(A),
   ( A<0 -> write('Invalid input!!\n'),!;
    A=:=0 -> write('0\n'),!;
    A=:=1 -> write('0 1\n'),!;
    A=:=2 -> write('0 1 1\n'),!;
    A>2-> write("0 1 "),fib(0,1,A)).