%U19CS009
%Brijesh Rohit

sumList([],0).
sumList([H|T],Sum) :-
    sumList(T,Sum1),
    Sum is H + Sum1.