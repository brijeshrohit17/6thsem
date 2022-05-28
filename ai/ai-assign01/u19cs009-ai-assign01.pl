%U19CS009
%BRIJESH_ROHIT

%invalid states considering capacity of Jug A is 4L anf Jug B is 3L
water_jug(X,Y):-X>4,Y<3,write("\nJug A Overflowed\n").
water_jug(X,Y):-X<4,Y>3,write("\nJug B Overflowed\n").
water_jug(X,Y):-X>4,Y>3,write("\nBoth Jugs Overflowed\n").

%goal state
water_jug(X,Y):- X=:=2,Y=:=0,write('\nGoal Achieved\n\n').

%static path to final state
water_jug(X,Y):-
X=:=0,Y=:=0,write("\n • Fill Jug B                         Then, Jug A : 0 and Jug B : 3"),water_jug(0,3);
X=:=0,Y=:=3,write("\n • Pour water in Jug A from Jug B     Then, Jug A : 3 and Jug B : 0"),water_jug(3,0);
X=:=3,Y=:=0,write("\n • Fill Jug B                         Then, Jug A : 3 and Jug B : 3"),water_jug(3,3);
X=:=3,Y=:=3,write("\n • Pour water in Jug A from Jug B     Then, Jug A : 4 and Jug B : 2"),water_jug(4,2);
X=:=4,Y=:=2,write("\n • Empty Jug A                        Then, Jug A : 0 and Jug B : 2"),water_jug(0,2);
X=:=0,Y=:=2,write("\n • Pour water in Jug A from Jug B     Then, Jug A : 2 and Jug B : 0"),water_jug(2,0);
X=:=4,Y=:=0,write("\n • Pour water in Jug B from Jug A     Then, Jug A : 1 and Jug B : 3"),water_jug(1,3);
X=:=1,Y=:=3,write("\n • Empty Jug B                        Then, Jug A : 1 and Jug B : 0"),water_jug(1,0);
X=:=1,Y=:=0,write("\n • Pour water in Jug B from Jug A     Then, Jug A : 0 and Jug B : 1"),water_jug(0,1);
X=:=0,Y=:=1,write("\n • Fill Jug A                         Then, Jug A : 4 and Jug B : 1"),water_jug(4,1);
X=:=4,Y=:=1,write("\n • Pour water in Jug B from Jug A     Then, Jug A : 2 and Jug B : 3"),water_jug(2,3);
X=:=2,Y=:=3,write("\n • Empty Jug B                        Then, Jug A : 2 and Jug B : 0"),water_jug(2,0).

%other state other than set path.
water_jug(X,Y):-
X=:=2,Y>0,write("\n • Empty Jug B                          Then, Jug A : 2 & Jug B : 0"),water_jug(2,0);
X=:=1,Y=:=1,write("\n • Pour water in Jug A from Jug B     Then, Jug A : 2 & Jug B : 0"),water_jug(2,0);
X=:=2,Y>0,write("\n • Empty Jug B                          Then, Jug A : 2 & Jug B : 0"),water_jug(2,0);
X>0,Y=:=2,write("\n • Empty Jug A                          Then, Jug A : 0 & Jug B : 2"),water_jug(0,2);
X>0,Y=:=3,write("\n • Empty Jug A                          Then, Jug A : 0 & Jug B : 3"),water_jug(0,3);
X>0,Y=:=1,write("\n • Fill Jug A                           Then, Jug A : 4 & Jug B : 1"),water_jug(4,1).

:-
write("Enter the initial states of Jug A : "),read(A),
write("Enter the initial states of Jug B : "),read(B),
write("Initial state of Jugs are :"),
write("\nJug A : "),write(A),
write(" & Jug B : "),write(B),
water_jug(A,B).
