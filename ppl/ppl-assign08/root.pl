%U19CS009
%BRIJESH ROHIT
 
roots(A,B,C):-
	(B*B-4*A*C) > 0 ->
		write("Roots are REAL and UNIQUE!!\n"),
		A1 is 2*A,
		R1 is ((-B+sqrt(B*B-4*A*C))/(A1)),
		R2 is ((-B-sqrt(B*B-4*A*C))/(A1)),
		write("Roots : "), write(R1),write(", "),write(R2),nl
;   (B*B-4*A*C) =:= 0 ->
		write("Roots are REAL and Equal!!"),nl,
		R1 is -B/(2*A),
		write("Roots : "), write(R1),write(", "),write(R1),nl
;   (B*B-4*A*C) < 0 ->
		write("Roots are Imaginary!!"),nl,
		A1 is 2*A,
		D1 is (-1)*(B*B-4*A*C),
		R1 is ((-B)/A1),
		I1 is ((sqrt(D1)/A1)),
		write("Roots : "), write(R1), write(" + "), write(I1),write("i and "),
		write(R1), write(" - "), write(I1), write("i"),nl.
 
check(A):-
    A=:=0 -> write("A can't be 0\n"),halt;
    !.
 
:-
    write("Please enter coefficients of equation 'ax^2 + bx + c':\n"),
    write("Please enter value of a : "),
    read(A),
    check(A),
    write("Please enter value of b : "),
    read(B),
    write("Please enter value of c : "),
    read(C),
    roots(A,B,C).