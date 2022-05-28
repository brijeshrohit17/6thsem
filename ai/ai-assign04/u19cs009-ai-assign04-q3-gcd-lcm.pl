%U19CS009
%BRIJESH ROHIT

lcm(A,B,R):-
    gcd(A,B,Res),
    R is A*B/Res.

gcd(0,A,A):-!.
gcd(A,0,A):-!.
gcd(A,B,R):-
    B1 is mod(A,B),
    gcd(B,B1,R).

calculate(A,B,GCD,LCM):-
    gcd(A,B,GCD),
    lcm(A,B,LCM).