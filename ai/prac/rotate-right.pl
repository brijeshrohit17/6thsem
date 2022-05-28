length([H|T],Len):-
    Len1
    Len is Len1+1.

rotate([H|T],L):-
    append(T,[H],L).