
%wap to calculate odd and even number of elements.

checkoddeven([],O,E):-
    write("Number of even elements : "),write(E),
    nl,write("Number of odd elements : "),write(O),nl.

checkoddeven([H|T],O,E):-
    (H mod 2)=:=0 -> C1 is E+1, checkoddeven(T,O,C1);
    (H mod 2)=\= 0 -> C1 is O+1, checkoddeven(T,C1,E).
    