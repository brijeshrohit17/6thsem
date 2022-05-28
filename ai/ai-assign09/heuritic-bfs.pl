%PREDICATE TO PERFORM HORIZONAL SWAP
hswap([A1,A2,A3],1,[A2,A1,A3]).
hswap([A1,A2,A3],2,[A1,A3,A2]).

%PREDICATE TO PERFORM VERTICAL SWAP
vswap([A1,A2,A3],[B1,B2,B3],1,[B1,A2,A3],[A1,B2,B3]).
vswap([A1,A2,A3],[B1,B2,B3],2,[A1,B2,A3],[B1,A2,B3]).
vswap([A1,A2,A3],[B1,B2,B3],3,[A1,A2,B3],[B1,B2,A3]).

%FINAL GOAL STATE
goal([[1,2,3],[4,5,6],[7,8,w],[3,3,0]]).

%PREDICATE TO EXTRACT ROWS
getcells([H1,H2,H3],[H1,H2,H3]).
match([X,Y,Z],[X,Y,Z],0).
match([X,Y,Z],[A,Y,Z],1).
match([X,Y,Z],[X,B,Z],1).
match([X,Y,Z],[X,Y,C],1).
match([X,Y,Z],[A,B,Z],2).
match([X,Y,Z],[A,Y,C],2).
match([X,Y,Z],[X,B,C],2).
match(_,_,3).

%number of mismatched tiles
huefunc([A,B,C,[I,J,H]]):-
    match(A,[1,2,3],N1),
    match(B,[4,5,6],N2),
    match(C,[7,8,w],N3),
    H is N1+N2+N3.

sets(X,X).

%PREDICATE TO GET RIGHT POSSIBILITY
getright([A,B,C,[I,J,H]],Right):-
    I>0,I=<3,J>0,J<3,
    (
        (I==1)->
        (
            hswap(A,J,X),J1 is
            J+1,huefunc([X,B,C,[I,J1,H1]]),sets([X,B,C,[I,J1,H1]],Right)
        );
        (I==2)->
        (
            hswap(B,J,X),J1 is
            J+1,huefunc([A,X,C,[I,J1,H1]]),sets([A,X,C,[I,J1,H1]],Right)
        );
        (I==3)->
        (
            hswap(C,J,X),J1 is
            J+1,huefunc([A,B,X,[I,J1,H1]]),sets([A,B,X,[I,J1,H1]],Right)
        )
    ),!.
getright(_,[]).

%PREDICATE TO GET LEFT POSSIBILITY
getleft([A,B,C,[I,J,H]],Left):-
    I>0,I=<3,J>1,J=<3,
    J1 is J-1,
    (
        (I==1)->
        (
            hswap(A,J1,X),huefunc([X,B,C,[I,J1,H1]]),sets([X,B,C,[I,J1,H1]],Left)
        );
        (I==2)->
        (
            hswap(B,J1,X),huefunc([A,X,C,[I,J1,H1]]),sets([A,X,C,[I,J1,H1]],Left)
        );
        (I==3)->
        (
            hswap(C,J1,X),huefunc([A,B,X,[I,J1,H1]]),sets([A,B,X,[I,J1,H1]],Left)
        )
    ),!.
getleft(_,[]).

%PREDICATE TO GET UP POSSIBILITY
getup([A,B,C,[I,J,H]],Up):-
    I>1,I=<3,J>0,J=<3,
    (
        (I==2)->
        (
            vswap(A,B,J,X,Y),I1 is
            I-1,huefunc([X,Y,C,[I1,J,H1]]),sets(Up,[X,Y,C,[I1,J,H1]])
        );
        (I==3)->
        (
            vswap(B,C,J,X,Y),I1 is
            I-1,huefunc([A,X,Y,[I1,J,H1]]),sets(Up,[A,X,Y,[I1,J,H1]])
        )
    ),!.
getup(_,[]).

%PREDICATE TO GET DOWN POSSIBILITY
getdown([A,B,C,[I,J,H]],Down):-
    (
        (I==2)->
        (
            vswap(B,C,J,X,Y),I1 is
            I+1,huefunc([A,X,Y,[I1,J,H1]]),sets([A,X,Y,[I1,J,H1]],Down)
        );
        (I==1)->
        (
            vswap(A,B,J,X,Y),I1 is
            I+1,huefunc([X,Y,C,[I1,J,H1]]),sets([X,Y,C,[I1,J,H1]],Down)
        )
    ),!.
getdown(_,[]).

%PREDICATE TO APPEND
append([],X,X).
append([H|T],N,[H|T1]):-
    append(T,N,T1).

%PREICATE TO PRINT THE SOLUTION
print([A,B,C,_]):-
    write(A),nl,write(B),nl,write(C),nl,nl.

display([]).
display([H|T]):-
    display(T),
    print(H).

%TO GET LIST OF ADJACENT NODES OF THE CURRENT NODE
extend([Node|Path],NewPaths):-
    bagof
    (
        [NewNode,Node|Path],
        (   (
                (getup(Node,X),sets(X,NewNode),not(sets(NewNode,[])),sets(Node,[_,_,_,[_,_,H]]),sets(NewNode,[_,_,_,[_,_,H1]]),H1<H);
                (getdown(Node,X),sets(X,NewNode),not(sets(NewNode,[])),sets(Node,[_,_,_,[_,_,H]]),sets(NewNode,[_,_,_,[_,_,H1]]),H1<H);
                (getleft(Node,X),sets(X,NewNode),not(sets(NewNode,[])),sets(Node,[_,_,_,[_,_,H]]),sets(NewNode,[_,_,_,[_,_,H1]]),H1<H);
                (getright(Node,X),sets(X,NewNode),not(sets(NewNode,[])),sets(Node,[_,_,_,[_,_,H]]),sets(NewNode,[_,_,_,[_,_,H1]]),H1<H)
            ),
        not(member(NewNode,[Node|Path]))),
        NewPaths
    ).
extend(_,[]).

%PERFORMING Hueristic search.
hs([[Node|Path]|_],[Node|Path],_):-goal(Node),write("\ndone\n").
hs([Path|Paths],Sol,K):-
    K<15,%max recursion counter.
    K1 is K+1,
    extend(Path,NewPath),
    append(Paths,NewPath,Path1),
    hs(Path1,Sol,K1).

%SOLVING FUNCTION
solve(Node):-
    hs([[Node]],X,0)
    ,display(X).