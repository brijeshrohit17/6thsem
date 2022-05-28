%wap to insert elements into list only if that element is not present in the list

isele([],A,B):-
    B is 0,!.

isele([H|T],A,B):-
    H=:=A -> B is 1,!
    ;isele(T,A,B).

insertlist(L1,A,L):-
    B is 0,
    isele(L1,A,B),
    (B =:= 1) -> L is L1;
    append(L1,[A],L).