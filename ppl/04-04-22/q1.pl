%write a program in prolog to print all the integers between wo nintegers n1 and n2 input from keyboard\

print(N,N1):-
    write(N),write(" "),
    N=:=N1 -> !
    ; N2 is N+1, print(N2,N1).
printint(N1,N2):-
    print(N1,N2).