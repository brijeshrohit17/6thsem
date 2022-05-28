%U19CS009
%BRIJESH ROHIT

%facts taken from previous assignment
female(mary).
female(sandra).
female(juliet).
female(lisa).

male(peter).
male(paul).
male(dick).
male(bob).
male(harry).

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

husband(peter,lisa).
husband(bob,juliet).

%child(X child of Y).
child(X,Y):-
    parent(Y,X).

% mother(X mother of Y).
mother(X,Y):-
    female(X),
    parent(X,Y).

% father (X father of Y).
father(X,Y):-
    parent(X,Y),
    male(X).

% wife (X wife of Y).
wife(X,Y):-
    female(X),
    husband(Y,X).

% son (X son of Y).
son(X,Y):-
    male(X),
    child(X,Y).

% daughter (X daughter of Y).
daughter(X,Y):-
    female(X),
    child(X,Y).

% brother (X brother of Y).
brother(X,Y):-
    son(X,Z),
    parent(Z,Y),
    X\==Y.

% sister (X sister of Y).
sister(X,Y):-
    daughter(X,Z),
    parent(Z,Y),
    X\==Y.

% uncle (X uncle of Y).
uncle(X,Y):-
    brother(X,Z),
    child(Y,Z).

% aunt (X aunt of Y).
aunt(X,Y):-
    sister(X,Z),
    child(Y,Z).

% nephew (X nephew of Y).
nephew(X,Y):-
    male(X),
    uncle(Y,X);
    male(X),
    aunt(Y,X).

% niece (X niece of Y).
niece(X,Y):-
    female(X),
    uncle(Y,X);
    female(X),
    aunt(Y,X).

%sibling (X sibling of Y).
sibling(X,Y):-
    parent(X,Z),
    parent(Y,Z),
    X\==Y.