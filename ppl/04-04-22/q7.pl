%wap to count number of occurences of an element in the list.

cnt([],A,C):-
    write("There are "),write(C), write(" occurences of "), write(A),nl.

cnt([H|T],A,C):-
    H=:=A -> C1 is C+1,cnt(T,A,C1)
    ; cnt(T,A,C).

counto(L,A):-
    C is 0,
    cnt(L,A,C).