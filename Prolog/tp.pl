%reverse count down
count_down(0).
count_down(N):-
    N > 0,
    write(N),tab(1),
    N1 is N-1,
    count_down(N1).

%count up
count_up_rev(0).
count_up_rev(N):-
    N > 0,
    N1 is N-1,
    count_up_rev(N1),
    write(N),tab(1).

%count_up original
countup(A,B):-
    A=<B,
    write(A),tab(1),
    A1 is A+1,
    countup(A1,B).
count_up(N):-
    N>0,
    countup(1,N).

%check even or odd integer
check_even(N):-
    Y is N//2,Y*2=:=N
    ->format('~w is even.~n',[N]); 
    write(N),tab(1),write('is odd.~n').

checknum():-
    write('Please enter a number : '),
    read(A),
    A=\=0,
    check_even(A).

%Traverse through list
write_list([]).
write_list([H|T]):-
    write(H),tab(1),
    write_list(T).

%first element of list
firstEle([]).
firstEle(A,[H|_]):-
    A is H.

%last element
lastEle(X,[X]).
lastEle(X,[_|L]):-
    lastEle(X,L).

%nth element in list
nthEle([H|_],0,H):-
    !.
nthEle([_|T],N,X):-
    N>0,
    N1 is N-1,
    nthEle(T,N1,X).

%increment each number in list
increment([],[],_).
increment([H|T],[H1|T1],Value):-
    increment(T,T1,Value),
    H1 is H+Value.

%reverse a list
reverse([],Y,R):-
    R=Y.
reverse([H|T],Y,R):-
    reverse(T,[H|Y],R).

%count number of elements in list
countEle([],0).
countEle([H|T],N):-
    countEle(T,N1),
    (
        number(H)
        ->N is N1+1
        ; N=N1
    ).

%check if number of elements are even or odd
evenList([H|T],N):-
    countEle([H|T],N),
    check_even(N).

%check vowels in list
vowels(X):-member(X,[a,e,i,o,u]).
countVowels([],0).
countVowels([H|T],N):-
    vowels(H),
    countVowels(T,N1),
    N is N1+1,
    !.
countVowels([_|T],N):-
    countVowels(T,N).

%remove duplicates
remove_duplicates([],[]).

remove_duplicates([H | T], List) :-    
     member(H, T),
     remove_duplicates( T, List).

remove_duplicates([H | T], [H|T1]) :- 
      \+member(H, T),
      remove_duplicates( T, T1).

initialize(A,B):-
    A is 10,
    B is A+100.


execute([H|T],Len,First,Last,N,Nth,IncList,Value,[H2|T2],RevList,EvenEle,CountVowels,RemoveDuplicates):-
    countEle([H|T],Len),
    firstEle([H|T],First),
    lastEle([H|T],Last),
    nthEle([H|T],N,Nth),
    increment([H|T],IncList,Value),
    reverse([H2|T2],[],RevList),
    evenList([H2|T2],EvenEle),
    countVowels([H2|T2],CountVowels),
    remove_duplicates([H2|T2],RemoveDuplicates).

%execute statement for ai-assign04
%execute([1,2,3,4,5,6,7,8,9],LenOfList,FirstEle,LastEle,3,NthEle,IncrementedList,1,ReverseList,EvenNoOfEleOrNot,[b,r,i,j,e,s,h,r,a,m,e,s,h,b,h,a,i,r,o,h,i,t],NumOfVowels,DuplicateFreeList).