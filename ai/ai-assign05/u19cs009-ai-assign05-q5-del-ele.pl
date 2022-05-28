%U19CS009
%Brijesh Rohit

delEleAtIndex(1,[_|T],T).
delEleAtIndex(P,[X|Y],[X|R]):-
    P1 is P-1,
    delEleAtIndex(P1,Y,R).

delEle(A, [A|B], B).
delEle(A, [B, C|D], [B|E]) :-
    delEle(A, [C|D], E).