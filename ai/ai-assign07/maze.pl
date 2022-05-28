%U19CS009
%BRIJESH ROHIT

%CONNECTED NODES
path('A','B').
path('A','C').
path('I','K').
path('I','M').
path('I','J').
path('I','L').
path('I','K').
path('I','M').
path('I','J').
path('I','L').
path('B','D').
path('B','E').
path('E','H').
path('E','I').
path('C','F').
path('Q','S').
path('Q','T').
path('D','G').
path('M','N').
path('M','O').
path('M','Q').
path('E','H').
path('E','I').
path('L','R').
path('F','P').


%APPEND LISTS
append([],X,X).
append([H|T],N,[H|T1]):-    
    append(T,N,T1).

%GET ALL NON VISITED NODES
extend([Node|Path],NewPaths):-
    bagof(
        [NewNode,Node|Path], 
        ((path(Node,NewNode);path(NewNode,Node)),
        not(member(NewNode,[Node|Path]))),
         NewPaths
        ),!.
extend(_,[]).

%WHEN NODE END IS REACHED
bfs([[Node|Path]|_],[Node|Path],Goal):-
    Node=Goal.

%BFS RECURSION.
bfs([Path|Paths],Sol,Goal):-
    extend(Path,NewPaths),
    append(Paths,NewPaths,Paths1),
    bfs(Paths1,Sol,Goal).

%PRINT GRAPH
display([]):-
    write("END"),nl.
display([H|T]):-
    write(H),
    write(" -> "),
    display(T).

%BFS.
findpath(Start,Goal):-
    bfs([[Start]],Sol,Goal),
    reverse(Sol,Path),
    display(Path).

main:-
    findpath('A','B'),nl,
    findpath('A','C'),nl,
    findpath('A','D'),nl,
    findpath('A','E'),nl,
    findpath('A','F'),nl,
    findpath('A','G'),nl,
    findpath('A','H'),nl,
    findpath('A','I'),nl,
    findpath('B','A'),nl,
    findpath('B','C'),nl,
    findpath('B','D'),nl,
    findpath('B','E'),nl,
    findpath('B','F'),nl,
    findpath('B','G'),nl,
    findpath('K','R'),nl,
    findpath('P','T'),nl,
    halt.
:- main.