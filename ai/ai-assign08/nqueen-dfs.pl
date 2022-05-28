addEle(A,List,NewList):-
    append(List,[A],NewList).

solve(Board,N,_,Board,N).

solve(Board,R,C,Ans,N):-
    ok(R,C,Board,0),
    addEle(C,Board,NewBoard),
    R1 is R+1,
    solve(NewBoard,R1,0,Ans,N).

solve(Board,R,C,Ans,N):-
    C < N-1,
    C1 is C+1,
    solve(Board,R,C1,Ans,N).
    ok(_,_,[],_).

ok(R,C,[H|T],N):-
    H =\= C,
    N =\= R,
    Sum1 is R + C,
    Sum2 is H + N,
    Sum1 =\= Sum2,
    Diff1 is R - C,
    Diff2 is N-H,
    Diff1 =\= Diff2,
    N1 is N+1,
    ok(R,C,T,N1).

:-
    write("Enter N: "),
    read(N),
    solve([],0,0,Ans,N),
    write(Ans).