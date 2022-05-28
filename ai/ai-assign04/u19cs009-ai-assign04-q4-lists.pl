%U19CS009
%BRIJESH ROHIT

%count number of elements in list
countEle([],0).
countEle([_|T],N):-
    countEle(T,N1),
    N is N1 + 1.

%first element of list
firstEle([]).
firstEle(X,[H|_]):-
    X is H.

%last element
lastEle(X,[X]).
lastEle(X,[_|L]):-
    lastEle(X,L).

firstAndLast([H|T]):-
    write("First element : "),
    firstEle(X,[H|T]),
    write(X),nl,
    write("Last element : "),
    lastEle(Y,[H|T]),
    write(Y).

%nth element in list
nthEle([],0):-
    write("Invalid Argument!!"),nl.
nthEle([H|_],1):-
    write("Nth element is : "),
    write(H).
nthEle([_|T],N):-
    N1 is N-1,
    nthEle(T,N1).

%increment each number in list
increment([],[]).
increment([H|T],[H1|T1]):-
    increment(T,T1),
    H1 is H+1.

%add elemenet at end
addAtEnd(H,[],[H]).
addAtEnd(X,[H|T1],[H|T2]):-
addAtEnd(X,T1,T2).

%reverse a list
reverse([],[]).
reverse([H|T],Y):-
    reverse(T,T1),
    addAtEnd(H,T1,Y).

checknum:-
    write('Please enter a number : '),
    read(A),
    A=\=0,
    check_even(A).

%check even or odd integer
check_even(N):-
    Y is N//2,Y*2=:=N
    ->format('Given List has \"EVEN\" number of elements.~n'); 
    format('Given List has \"ODD\" number of elements.~n').

%check if number of elements are even or odd
evenList([H|T]):-
    countEle([H|T],N), %from first ques
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

execute([H|T],Len,First,Last,N,Nth,IncList,Value,RevList,EvenEle,[H2|T2],CountVowels,RemoveDuplicates):-
    countEle([H|T],Len);nl,
    firstEle([H|T],First);nl,
    lastEle([H|T],Last);nl,
    nthEle([H|T],N,Nth);nl,
    increment([H|T],IncList,Value);nl,
    reverse([H|T],[],RevList);nl,
    evenList([H|T],EvenEle);nl,
    countVowels([H2|T2],CountVowels);nl,
    remove_duplicates([H2|T2],RemoveDuplicates);nl.

%execute statement for ai-assign04
%execute([1,2,3,4,5,6,7,8,9],LenOfList,FirstEle,LastEle,3,NthEle,IncrementedList,1,ReverseList,EvenNoOfEleOrNot,[b,r,i,j,e,s,h,r,a,m,e,s,h,b,h,a,i,r,o,h,i,t],NumOfVowels,DuplicateFreeList).