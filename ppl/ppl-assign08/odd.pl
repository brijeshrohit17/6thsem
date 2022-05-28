%U19CS009
%BRIJESH ROHIT

check_even(N):-
    Y is N//2,Y*2=:=N
    ->format('~w is even.~n',[N]); 
    format('~w is odd.~n',[N]).

:-
    write('Please enter a number : '),
    read(A),
    check_even(A).