:- op(500,xfx,'is_parent').

a is_parent b.    c is_parent g.     f is_parent l.     j is_parent q.
a is_parent c.    c is_parent h.     f is_parent m.     j is_parent r.
a is_parent d.    c is_parent i.     h is_parent n.     j is_parent s.
b is_parent e.    d is_parent j.     i is_parent o.     m is_parent t.
b is_parent f.    e is_parent k.     i is_parent p.

getchildren(Parent, Children) :-
    setof(Child, Parent^is_parent(Parent, Child), Children), !.
getchildren(_, []).

depthfirst([]) :- !.
depthfirst([Node|Frontier]) :-
    format('~p ', [Node]),
    getchildren(Node, Children),
    append(Children, Frontier, NewFrontier),
    depthfirst(NewFrontier).

breadthfirst([]) :- !.
breadthfirst([Node|Frontier]) :-
    format('~p ', [Node]),
    getchildren(Node, Children),
    append(Frontier, Children, NewFrontier),
    breadthfirst(NewFrontier).