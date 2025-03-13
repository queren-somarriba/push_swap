# Push_swap

Push_swap est un projet en C visant à trier une pile d'entiers en utilisant un ensemble limité d'opérations sur deux piles (`a` et `b`). L'objectif est d'optimiser le nombre de coups nécessaires pour trier les nombres.

## Installation

Pour compiler `push_swap`, utilisez la commande suivante :

```sh
gcc -Wall -Wextra -Werror push_swap.c utils/*.c -o push_swap
```

## Utilisation

La syntaxe de `push_swap` est la suivante :

```sh
./push_swap [list of integers]
```

Exemple :

```sh
./push_swap 4 67 3 87 23
```

Le programme retournera une suite d'opérations pour trier la liste donnée.

## Opérations disponibles

- `sa` : Échange les deux premiers éléments de la pile `a`
- `sb` : Échange les deux premiers éléments de la pile `b`
- `ss` : Effectue `sa` et `sb` simultanément
- `pa` : Pousse le premier élément de `b` vers `a`
- `pb` : Pousse le premier élément de `a` vers `b`
- `ra` : Fait pivoter `a` vers le haut
- `rb` : Fait pivoter `b` vers le haut
- `rr` : Fait pivoter `a` et `b` vers le haut simultanément
- `rra` : Fait pivoter `a` vers le bas
- `rrb` : Fait pivoter `b` vers le bas
- `rrr` : Fait pivoter `a` et `b` vers le bas simultanément

## Bonus : Vérificateur

### Checker

Un programme `checker` est fourni pour vérifier si la suite d'opérations donnée trie correctement la pile.

Utilisation :

```sh
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

Le `checker` affichera `OK` si la pile est bien triée, sinon `KO`.
