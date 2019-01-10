cartesian( [], _, [] ).
cartesian( [F|R], X, C3 ) :- cartesian( R, X, C1), product(F, X, C2), append( C1, C2, C3).

product( _, [], []).
product( X, [F|R], [pair(X,F)|L]) :- product( X, R, L).

deepmember(X, [X|_]).
deepmember(X, [F|_]) :- deepmember(X, F).
deepmember(X, [_|R]) :- deepmember(X, R).

notcontains(_, []).
notcontains(X, [F|T]) :- X\=F, notcontains(X, T).

addunique(X, L1, [X|L1]) :- notcontains(X, L1).

setinsertion(X, S1, [X|S1]) :- notcontains(X, S1), !.
setinsertion(_, S1, S2) :- S2 = S1.

graph1( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 4 ], [ 4, 1 ] ] ).
graph2( [ [ 1, 2 ], [ 2, 3 ], [ 2, 4 ], [ 3, 4 ],
          [ 4, 3 ], [ 3, 1 ], [ 4, 1 ] ] ).
graph3( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 2 ],
          [ 3, 4 ], [ 2, 4 ], [ 4, 6 ], [ 4, 5 ],
          [ 5, 6 ], [ 6, 5 ], [ 6, 7 ], [ 5, 7 ],
          [ 7, 1 ] ] ).

allvertices([], []).
allvertices([[X, Y]|R], L3) :- allvertices(R, L),
				setinsertion(X, L, L2),
				setinsertion(Y, L2, L3).

connected(V0, V1, G) :- member([X, Y], G), V0 = X, V1 = Y.

path(_,Vbegin,1,_,[Vbegin],Vbegin).
path(G,Vbegin,N,Forbidden,[Vbegin|Path2],Vend) :- connected(Vbegin, Next, G),
				notcontains(Next, Forbidden),
				Next \= Vbegin,
				path(G,Next,N1,[Next|Forbidden],Path2,Vend),
				N is N1+1.

hamiltoniancircuit(G, C) :- allvertices(G, Vert),
				Vert = [V0|_],
				length(Vert, N),
				path(G, V0, N, [V0], C, LastV),
				connected(LastV, V0, G).
