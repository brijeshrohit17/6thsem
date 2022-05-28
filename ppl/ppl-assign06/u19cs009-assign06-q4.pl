%U19CS009
%BRIJESH ROHIT

%female
female(sandra). 
female(juliet). 
female(lisa).

%male
male(peter). 
male(paul). 
male(dick). 
male(bob). 
male(harry).

%parent
parent(bob, lisa). 
parent(bob, paul). 
parent(bob, mary). 
parent(juliet, lisa). 
parent(juliet, paul). 
parent(juliet, mary).
parent(peter, harry). 
parent(lisa, harry). 
parent(mary, dick). 
parent(mary, sandra). 

%New Predicates

%father predicate (X is father of Y)
father(X,Y):-
    male(X),
    parent(X,Y),
    write(X), write(" is Father of "),write(Y),nl.

%sister predicate (X is sister of Y)
sister(X,Y):-
    female(X),
    parent(Z,X),
    parent(Z,Y),
    X\==Y,
    write(X),write(" is Sister of "),write(Y),nl.

%grandmother predicate (X is grandmother of Y)
grandmother(X,Y):-
    female(X),
    parent(X,Z),
    parent(Z,Y),
    write(X), write(" is Grandmother of "),write(Y),nl.

%brother predicate (X is brother of Y)
brother(X,Y):-
    male(X),
    parent(Z,X),
    parent(Z,Y),
    X\==Y,
    write(X), write(" is Brother of "),write(Y),nl.

%sibling predicate (X is sibling of Y)
sibling(X,Y):-
    sister(X,Y);
    brother(X,Y),
    write(X), write(" is Sibling of "),write(Y),nl.

%cousin predicate (X is cousin of Y)
cousin(X,Y):-
    parent(Z,X),
    parent(W,Y),
    sibling(Z,W),
    write(X), write(" is Cousin of "),write(Y),nl.