%U19CS009
%BRIJESH ROHIT

mem(X,[]):-
    write(X),
    write("'IS NOT' member of givem List"),
    nl.

mem(X,[X|_]):-
    write(X),
    write(" 'IS' member of givem List"),
    nl.

mem(X,[_|T]) :- 
    mem(X,T).