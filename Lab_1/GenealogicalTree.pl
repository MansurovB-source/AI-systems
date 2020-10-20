
parent('Mullomansur', 'Rahimjon').
parent('Ff', 'Rahimjon').
parent('Mmm', 'Marhabokhon').
parent('Fff', 'Marhabokhon').
parent('Rahimjon', 'Bakhtiyor').
parent('Marhabokhon', 'Bakhtiyor').
parent('Rahimjon', 'Malohatkhon').
parent('Marhabokhon', 'Malohatkhon').
parent('Rahimjon', 'Madinakhon').
parent('Marhabokhon', 'Madinakhon').
parent('Rahimjon', 'Bahodur').
parent('Marhabokhon', 'Bahodur').
parent('Bakhtiyor', 'Behruz').
parent('Munzifakhon', 'Behruz').
parent('Bakhtiyor', 'Firdavs').
parent('Munzifakhon', 'Firdavs').
parent('Bakhtiyor', 'Mansur').
parent('Munzifakhon', 'Mansur').
parent('Malohatkhon', 'Mahfuza').
parent('Malohatkhon', 'Maftuna').
parent('Malohatkhon', 'Azim').
parent('Malohatkhon', 'Azam').
parent('Madinakhon', 'Parvina').
parent('Madinakhon', 'Parviz').
parent('Madina', 'Aziz').
parent('Bahodur', 'Husrav').
parent('Bahodur', 'Amir').

female('Ff').
female('Fff').
female('Marhabokhon').
female('Munzifakhon').
female('Malohatkhon').
female('Madinakhon').
female('Mahruza').
female('Maftuna').
female('Parvina').

male('Mmm').
male('Mullomansur').
male('Bakhtiyor').
male('Bahodur').
male('Behruz').
male('Parviz').
male('Firdavs').
male('Husrav').
male('Mansur').
male('Azim').
male('Azam').
male('Aziz').
male('Amir').

predecessor(X, Y) :- parent(X, Y).
predecessor(X, Y) :- parent(X, Z), predecessor(Z, Y).
grandparent(X, Y) :- parent(X, Z), parent(Z, Y). 
grandgrandparent(X, Y) :- parent(X, Z), grandparent(Z, Y).
grandfather(X, Y) :- male(X), parent(X, Z), parent(Z, Y).
grandgrandfather(X,Y) :- male(X), parent(X, Z), grandparent(Z, Y).
grandmother(X, Y) :- female(X), parent(X, Z), parent(Z, Y).
grandgrandmother(X,Y) :- female(X), parent(X, Z), grandparent(Z, Y).
father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), sibling(X, Y).
sister(X, Y) :- female(X), sibling(X, Y).
son(X, Y) :- male(X), parent(Y, X).
daughter(X, Y) :- female(X), parent(Y, X).
uncle_or_aunt(X, Y) :- sibling(X, Z), parent(Z, Y).
uncle(X, Y) :- male(X), uncle_or_aunt(X, Y).
aunt(X, Y) :- female(X), uncle_or_aunt(X, Y).
grandson(X, Y) :- male(Y), grandparent(X, Y).
granddaughter(X, Y) :- female(Y), grandparent(X, Y).
cousin(X, Y) :- parent(Z, X), parent(K, Y), sibling(Z, K).

/** <examples>
?- uncle('Bahodur', 'Amir')
*/
