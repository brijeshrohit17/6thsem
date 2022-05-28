%U19CS009
%BRIJESH ROHIT

max(A,B,C):-
	A>B,
	A>C,
	write(A).
max(A,B,C):-
	A>B,
	write(C).
max(_,B,C):-
	B>C,
	write(B).
max(_,_,C):-
	write(C).

min(A,B,C):-
	A<B,
	A<C,
	write(A).
min(A,B,C):-
	A<B,
	write(C).
min(_,B,C):-
	B<C,
	write(B).
min(_,_,C):-
	write(C).

maxmin(A,B,C):-
    write("Max salary : "),
	max(A,B,C),nl,
    write("Min salary : "),
	min(A,B,C).

:-
	write("Please enter first employee's salary : "),
	read(A),
	write("Please enter second employee's salary : "),
	read(B),
	write("Please enter third employee's salary : "),
	read(C),
	maxmin(A,B,C).