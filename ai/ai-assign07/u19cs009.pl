%U19CS009
%BRIJESH ROHIT

% 1. Find the total number of diseases for each patient.
% 2. Find the name and zip code of each patient.
% 3. Write P_Id and name of all patients staying in Delhi.
% 4. List name of all patients treated by doctor D1.
% 5. List roll no. of all patients suffering from Common cold
% 6. List building_name and city_code for all patients in the given format (format: [(building_name, citycode)]).
% 7. List all doctors for each given patient.

patient(p101, brijesh, address(shlimar_park, surat, 395001), [sub(d1,common_cold),sub(d2,flu)]).
patient(p102, aman, address(honey_park, delhi, 110002), [sub(d3,chicken_pox), sub(d2,flu)]).
patient(p103, dhruv, address(shally_tower, mumbai,400004 ),[sub(d4,measles), sub(d2, flu), sub(d3,chicken_pox)]).
patient(p104, neel, address(neelu_parlor,surat,395007), [sub(d3,flu), sub(d1,common_cold), sub(d3,chicken_pox)]).
patient(p105, krina, address(abcd,delhi,200011),[sub(d3,chicken_pox), sub(d1,common_cold), sub(d2,flu)]).

go :-
    write('What is the patient''s name? '),
    read(Patient),
    hypothesis(Patient,Disease),
    write_list([Patient,'probably has ',Disease,'.']),nl.

go :-
    write('Sorry, I don''t seem to be able to'),nl,
    write('diagnose the disease.'),nl.

symptom(Patient,fever) :-
    write_list(['Does ',Patient,' have a fever (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,rash) :-
    write_list(['Does ',Patient,' have a rash (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,headache) :-
    write_list(['Does ',Patient,' have a headache (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,runny_nose) :-
    write_list(['Does ',Patient,' have a runny_nose (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,conjunctivitis) :-
    write_list(['Does ',Patient,' have a conjunctivitis (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,cough) :-
    write_list(['Does ',Patient,' have a cough (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,body_ache) :-
    write_list(['Does ',Patient,' have a body_ache (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,chills) :-
    write_list(['Does ',Patient,' have a chills (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,sore_throat) :-
    write_list(['Does ',Patient,' have a sore_throat (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,sneezing) :-
    write_list(['Does ',Patient,' have a sneezing (y/n) ?']),
    response(Reply),
    Reply='y'.

symptom(Patient,swollen_glands) :-
    write_list(['Does ',Patient,' have a swollen_glands (y/n) ?']),
    response(Reply),
    Reply='y'.

hypothesis(Patient,measles) :-
    symptom(Patient,fever),
    symptom(Patient,cough),
    symptom(Patient,conjunctivitis),
    symptom(Patient,runny_nose),
    symptom(Patient,rash).

hypothesis(Patient,flu) :-
    symptom(Patient,fever),
    symptom(Patient,headache),
    symptom(Patient,body_ache),
    symptom(Patient,conjunctivitis),
    symptom(Patient,chills),
    symptom(Patient,sore_throat),
    symptom(Patient,runny_nose),
    symptom(Patient,cough).

hypothesis(Patient,common_cold) :-
    symptom(Patient,headache),
    symptom(Patient,sneezing),
    symptom(Patient,sore_throat),
    symptom(Patient,runny_nose),
    symptom(Patient,chills).

hypothesis(Patient,chicken_pox) :-
    symptom(Patient,fever),
    symptom(Patient,chills),
    symptom(Patient,body_ache),
    symptom(Patient,rash).

hypothesis(Patient,measles) :-
    symptom(Patient,cough),
    symptom(Patient,sneezing),
    symptom(Patient,runny_nose).

write_list([]).
write_list([Term| Terms]) :-
    write(Term),
    write_list(Terms).

response(Reply) :-
    get_single_char(Code),
    put_code(Code), nl,
    char_code(Reply, Code).

list_length([], 0 ).
list_length([_|Xs], L) :- list_length(Xs, N) , L is N + 1.

q1:-
    patient(_, N, _, S),
    write('All diesases of patient '), write(N), write(': '),
    list_length(S, L), write(L), nl, fail.

q2:-
    patient(_, X, address(_, _, Z), _), nl,
    write('Name: '), write(X), nl,
    write('Zipcode: '), write(Z), nl, fail.

q3:-
    Goal = (patient(Roll, Name, address(_, C, _), _), C = delhi),
    findall(Roll/Name, Goal, L),
    maplist(write, L).

get_subjects(Z):-
    patient(_,Name,_, Subjects),
    member(Subject, Subjects),
    Subject = sub(d1, Z), 
    write(Name), nl.

q4:-
    findall(Z, get_subjects(Z), L),
    sort(L, Y).

q5:-
    patient(_, R, _, Subjects),
    member(Subject, Subjects),
    Subject = sub(_, common_cold),
    write(R),
    nl,
    fail.

q6:-
    patient(_,_,address(B, C, _), _),
    write(B),write(', '), write(C),nl,fail.

% q7:- q7(p102).

q7:-
    patient(R, _, _, Disease),
    write('Doctors for: '), write(R), nl,
    member(Subject, Disease),
    Subject = sub(T, _),
    write(T),nl,fail.

get_all_subjects(Z):-
    student(_,_,_, Subjects),
    member(Subject, Subjects),
    Subject = sub(_, Z),!.