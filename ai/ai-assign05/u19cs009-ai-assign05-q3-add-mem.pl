%U19CS009
%BRIJESH ROHIT

concatMem([],X, [X]).
concatMem([Y|T1], X,[Y|T2]) :- 
    concatMem(T1, X,T2).