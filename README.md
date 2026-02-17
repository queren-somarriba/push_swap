# Push_swap - @42Paris

## Project Overview
**Push_swap** is a highly efficient algorithm project that challenges you to sort a stack of integers using a limited set of instructions and two stacks (**a** and **b**). The goal is to find the shortest possible sequence of operations to sort the data.

This project is a deep dive into data structures (Linked Lists), complexity (Big O notation), and algorithm optimization.

---

## Algorithm: "The Turkish Algorithm"
For this implementation, I chose a cost-based insertion sort. Instead of using simple chunks, this approach calculates the most efficient move at every single step.

### Key Concepts:
* **Target Positioning:** For every element in Stack A, the algorithm identifies its "target" position in Stack B (the largest element that is still smaller than the current one).
* **Cost Calculation:** The program evaluates the number of operations required to bring an element from A and its target in B to the top of their respective stacks.
* **Rotation Optimization:** If both the element and its target are in the same half of their stacks (both in the top or both in the bottom), the algorithm utilizes double rotations (`rr` or `rrr`) to minimize moves.
* **The "Cheapest" Move:** Only the element with the lowest combined cost is pushed to Stack B in each iteration.

---

## Instruction Set
| Command | Action |
| :--- | :--- |
| `sa`, `sb`, `ss` | Swap the first 2 elements at the top of a stack. |
| `pa`, `pb` | Take the first element at the top of one stack and put it on the other. |
| `ra`, `rb`, `rr` | Shift up all elements of a stack by 1 (The first becomes the last). |
| `rra`, `rrb`, `rrr` | Shift down all elements of a stack by 1 (The last becomes the first). |

---

## Getting Started

### Compilation
The project includes a `Makefile` with the standard 42 rules:

```bash
# Compiles the push_swap mandatory executable
make

# Compiles the checker bonus program
make bonus

# Clean object files and the executable
make fclean
```

## Execution

To see the instructions generated to sort a stack:
```Bash

./push_swap 4 67 3 87 23
```
To verify the result using the Bonus Checker:
```Bash

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
## Bonus: Checker Program

I implemented a custom Checker that replicates the behavior of the stack and validates the sorting logic.

* **    It reads instructions from stdin.

* **    Executes them on the initial stack.

* **    Displays OK if the stack is sorted and Stack B is empty.

* **    Displays KO if the stack remains unsorted.

* **    Displays Error for invalid arguments or unknown instructions.

## Performance Benchmarks

My implementation consistently achieves the following results (meeting the highest 42 evaluation brackets):

  * **  3 numbers: Max 3 operations.

  * **  5 numbers: Max 12 operations.

  * **  100 numbers: ~600 operations (Top score).

  * **  500 numbers: ~5500 operations (Top score).

## Contact

    Login: qsomarri

    School: 42 Paris
