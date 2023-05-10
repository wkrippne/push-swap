# push-swap
42 project about sorting 2 stacks as fast as possible.

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.

## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Algorithm

For the stacks with size less than 3 there is a simple sort algo which can be found in the src folder.

In this project I used `QuickSort` as the main algorithm. This is an efficient algorithm to sort integers
with average time complexity O(n*logn). 

### Performance of the Algorithm

My push_swap sorts

    3 numbers with maximum 3 instructions,
    100 numbers with average 700 instructions => 5 points,
    500 numbers with avaerage 5200 instructions => 5 points.

### Bonus

The bonus part is to write a program named checker, which will get as an argument the stack A formatted as a list of integers. Checker will then wait and read instructions on the standard input. Once all the instructions have been read, checker will execute them on the stack received as an argument (After giving the instructions press ctrl + d).

If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" else "KO". If checker arguments are invalid it displays Error.

The checker code can be found in the checker.c file in src.