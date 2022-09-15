# Section 1.1-1.3
## Intro to Logic #1
- `Statement`/`Proposition` is a sentence that is true or false. NOT BOTH
### Logical Connective Symbols
- `Negation`: if p is a proposition, `~`, not, ¬, ! are used to negate p
- when negating sentences don't write dumb shit. Write a sensible negation of the sentence
- `Conjunction`: and, but, `^` 
- `Disjunction`: (inclusive or) or, `v`, ||
- `Conditional Statement`/`Material Implication`: `->`
#### Truth Tables
- the 1st column(s) provide values for propositions which will be used to fill the rest of the columns. Ex:

|p|q|~p|p^q|pvq|
|---|---|---|---|---|
|T|T| | | |
|T|F| | | |
|F|T| | | |
|F|F| | | |

### DeMorgan's Laws
**Negation of conjunctions and disjunctions**
- the negation of conjunction is equivalent to the disjunction of negations
- Ex: ~(p^q) ≡ ~p v ~q
- similarly the negation of disjunction is equivalent to the conjunction of negations (you can prove this via a truth table)
- Ex: ~(pvq) ≡ ~p ^ ~q

### Conditional Statement/Material Implication
- "if p then q" ≡ "p implies q"
- the premise/hypothesis/antecedent is what's before the arrow and conclusion/consequence is what comes after
- Ex: p -> q. p is the premise q is the conclusion
- "If you get 100%, then you'll get an A"

|p|q|p -> q|
|-|-|-|
|T|T|T|
|T|F|F|
|F|T|T|
|F|F|T|

- the third statement is confusing but notice how the premise is false. if the premise is false the conclusion does not matter. If you don't get 100% and still get an A the above example has not been broken
- **An implication will always evaluate to true if the premise is false**

### Converse/Contrapositive/Inverse
- `Converse`: Changes the order
- `Contrapositive`: Negates the conclusion, and therefore also the premise. The conditional and contrapositive are equivalent
- `Inverse`: Negates the premise, and therefore also the conclusion. The converse and the inverse are equivalent
Given the conditional p -> q
- the converse is q -> p
- the contrapositive is ~q -> ~p
- the inverse is ~p -> ~q

## Intro to Logic #2
- `Biconditional`(material equivalence): The implication works both way. p<->q or [(p->q) ^ (q->p)]

### Order of Precedence (Pemdas)
1. ~
2. ^
3. v
4. ->/<-> (associate with symbols on the right first)
**Note** you don't have to read left to right. Symbol with precedence matters not left to right

Ex: p v q ^ r ≡ (p v (q ^ r))
Ex: p -> q -> r ≡ (p -> (q -> r))

### Exclusive Disjunction
- `Exclusive or`: xor, `⊕`. Means one or the other but not both
- p ⊕ q ≡ (p v q) ^ ~(p ^ q)

### Negating the Conditional
- `~(p -> q)` ≡ p ^ ~q. **No longer a conditional**. usually use but here instead of and


### Tautology vs. Contradiction
- `Tautology`: a statement/proposition that is **ALWAYS** true regardless of the truth values of the parts

Ex: p v ~p (something happens or it doesn't happen. this is always true. `p v ~p ≡ **T**`)

|p|~p|p v ~p|
|---|---|---|
|T|T|T|
|F|F|T|

- `Contradiction`: a statement/proposition that's **ALWAYS** false regardless of the truth values of the parts

Ex: p ^ ~p (something can't happen and not happen. This is always false. `p ^ ~p ≡ **F**`)

|p|~p|p ^ ~p|
|---|---|---|
|T|T|F|
|F|F|F|

- `Contingency`: neither of the above. ae. it varies

### Basic Logic Identities
- `Commutative`: order doesn't matter for disjunction and conjunction. 

Ex: p v q ≡ q v p  &  p ^ q ≡ q ^ p
- `Associative`: when solving more complicated disjunctions or conjunctions the order of solving doesn't matter

Ex: (p ^ q) ^ r ≡ p ^ (q ^ r)  &  (p v q) v r ≡ p v (q v r)
- `Distributive`: you must distribute the proposition and the logical operator together

Ex: p v (q ^ r) ≡ (p v q) ^ (p v r)  &  p ^ (q v r) ≡ (p ^ q) v (p ^ r)
- `Double Negation`: cancels out

Ex: ~(~p) ≡ p
- `DeMorgan`: if you negate a conjunction that's equivalent to a conjunction of negations

Ex: ~(p ^ q) ≡ ~p v ~q  &  ~(p v q) ≡ ~p ^ ~q
- `Identity`: conjoining a proposition and tautology results in prop. disjoining prop and contradiction results in prop.

Ex: p ^ T ≡ p  &  p v F ≡ p
- `Domination`: conjoining prop and contradiction results in false. disjoining prop and tautology results in true.

Ex: p ^ F ≡ F  &  p v T ≡ T
- `Idempotent`: conjunction/disjunction with oneself results in prop

Ex: p ^ p ≡ p  &  p v p ≡ p
- `Negation`: conjunction with negation is a contradiction. disjunction with negation is a tautology

Ex: p ^ ~p ≡ F  &  p v ~p ≡ T
- `Absorbtion`: p v (p ^ q) ≡ p  &  p ^ (p v q) ≡ p
**CAN USE TRUTH TABLE TO PROVE THESE**

# Section 1.4-1.5
## Logic Predicates 1

- `Predicate`: a logical statement with variables

Ex: P(x) = "x is tall"

- `Domain`: set of all possible substitutions
- `Truth set`: subset of values from the domain that make the predicate true

### Quantifiers
- `Universal`: `∀` for all
- `Existential`: `∃` there exists

Ex: P(x): x^2 > x      D: {R^2}

∃xP(x) => True    ∀xP(x) => False. (1/2)^2 < 1/2

- quantifiers don't distribute. ∃x[P(x) ^ (Q(x))] != ∃xP(x) ^ ∃xQ(x)l

### DeMorgan's Laws for Quantifiers (Negating quantifiers)
- `Negation of the universal quantifer`: ~∀xP(x) ≡ ∃x~P(x)
- `Negation of exisistential quantifier`: ~∃xP(x) ≡ ∀x~P(x)
- `Negating chained quantifiers`: flip them and negate the predicate (ae. ~(∃x∀y)P(x,y) ≡ ∀x∃y~P(x,y))