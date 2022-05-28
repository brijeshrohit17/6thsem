%wap to determine whether an arugument list is sorted or not.
isSorted([],B):-
    write("List is Sorted!!\n").

isSorted([H|T],B):-
    H >= B -> isSorted(T,H);
    write("List is not sorted!!\n"),fail.