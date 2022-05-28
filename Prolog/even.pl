check_even(N):-
    Y is N//2,Y*2=:=N
    ->format('~w is even.~n',[N]); 
    format('~w is odd.~n',[N]).

:-
    write('Please enter a number : '),
    read(A),
    A=\=0,
    check_even(A).