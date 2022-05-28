hswap([A1,A2,A3],1,[A2,A1,A3]).
hswap([A1,A2,A3],2,[A1,A3,A2]).

vswap([A1,A2,A3],[B1,B2,B3],1,[B1,A2,A3],[A1,B2,B3]).
vswap([A1,A2,A3],[B1,B2,B3],2,[A1,B2,A3],[B1,A2,B3]).
vswap([A1,A2,A3],[B1,B2,B3],3,[A1,A2,B3],[B1,B2,A3]).

goal([[1,2,3],[4,5,6],[7,8,w]]).

getcells([H1,H2,H3],[H1,H2,H3]).

dfs(Path,Node,Path,_,_,_):-
    goal(Node).


%RIGHT
dfs(Path,Node,Sol,I,J,K):-
    I>0,I=<3,J>0,J<3,
    % K<5,K1 is K+1,
    % write(Node),nl,
    getcells(Node,[A,B,C]),
    (
        (I==1)->(
            hswap(A,J,X),not(member([X,B,C],Path)),J1 is J+1,dfs([[X,B,C]|Path],[X,B,C],Sol,I,J1,K)
            );
        (I==2)->(
            hswap(B,J,X),not(member([A,X,C],Path)),J1 is J+1,dfs([[A,X,C]|Path],[A,X,C],Sol,I,J1,K)
            );
        (I==3)->(
            hswap(C,J,X),not(member([A,B,X],Path)),J1 is J+1,dfs([[A,B,X]|Path],[A,B,X],Sol,I,J1,K)
            )
        
        ),!.
%DOWN
dfs(Path,Node,Sol,I,J,K):-
    I>0,I<3,J>0,J=<3,
    % K<5,K1 is K+1,
    % write(Node),nl,
    getcells(Node,[A,B,C]),
    (
        (I==2)->(
        vswap(B,C,J,X,Y),not(member([A,X,Y], Path)),I1 is I+1,dfs([[A,X,Y]|Path],[A,X,Y],Sol,I1,J,K)
            );
        (I==1)->(
            vswap(A,B,J,X,Y),not(member([X,Y,C], Path)),I1 is I+1,dfs([[X,Y,C]|Path],[X,Y,C],Sol,I1,J,K)
            )
    ),!.
%UP
dfs(Path,Node,Sol,I,J,K):-
    I>1,I=<3,J>0,J=<3,
    % K<5,K1 is K+1,
    % write(Node),nl,
    getcells(Node,[A,B,C]),
    (
        (I==2)->(
        vswap(A,B,J,X,Y),not(member([X,Y,C], Path)),I1 is I-1,dfs([[X,Y,C]|Path],[X,Y,C],Sol,I1,J,K)
            );
        (I==3)->(
            vswap(B,C,J,X,Y),not(member([A,X,Y], Path)),I1 is I-1,dfs([[A,X,Y]|Path],[A,X,Y],Sol,I1,J,K)
            )
    ),!.


%LEFT
dfs(Path,Node,Sol,I,J,K):-
    I>0,I=<3,J>1,J=<3,
    % K<5,K1 is K+1,
    % write(Node),nl,
    getcells(Node,[A,B,C]),
    (
        J1 is J-1,
        (I==1)->(
            hswap(A,J1,X),not(member([X,B,C],Path)),dfs([[X,B,C]|Path],[X,B,C],Sol,I,J1,K)
            );
        (I==2)->(
            hswap(B,J1,X),not(member([A,X,C],Path)),dfs([[A,X,C]|Path],[A,X,C],Sol,I,J1,K)
            );
        (I==3)->(
            hswap(C,J1,X),not(member([A,B,X],Path)),dfs([[A,B,X]|Path],[A,B,X],Sol,I,J1,K)
            )
        
        ),!.

print([A,B,C]):-
    write(A),nl,write(B),nl,write(C),nl,nl.

display([]).
display([H|T]):-
    display(T),
    print(H).
solve(Node,I,J):-
    dfs([],Node,Sol,I,J,0),print(Node),display(Sol).

