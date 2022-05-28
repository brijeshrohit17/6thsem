%U19CS009
%BRIJESH_ROHIT

%MALES
male('I').
male('F').
male('S1').
male('S2').

%FEMALES
female('W').
female('D').

%PARENT(WHO, TO_WHOM)
parent('I','D').
parent('W','D').
parent('F','I').
parent('D','I').
parent('I','S1').
parent('W','S1').
parent('F','S2').
parent('D','S2').

%MARRIED(WHO, TO_WHOM)
married('I','W').
married('F','D').
married('W','I').
married('D','F').

%WIDOW
widow('W').

%RULES
step_children(X,Y):-Y\==parent(Z,X),parent(Z,X),married(Z,Y).
stepdaughter(X,Y):-female(X),step_children(X,Y).
son(X,Y):-male(X),parent(Y,X).
daughter(X,Y):-female(X),parent(Y,X).
husband(X,Y):-male(X),married(X,Y),female(Y).
wife(X,Y):-husband(Y,X).
sibling(X,Y):-parent(Z,X),parent(Z,Y).
soninlaw(X,Y):-male(X),parent(Y,Z),married(X,Z).
brotherinlaw(X,Y):-male(X),married(Y,Z),female(Z),sibling(X,Z).
fatherinlaw(X,Y):-male(X),parent(X,Z),married(Y,Z).
uncle(X,Y):-male(X),sibling(X,Z),parent(Z,Y).
grandfather(X,Y):-male(X),parent(X,Z),parent(Z,Y).