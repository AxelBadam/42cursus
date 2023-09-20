# push_swap

This project introduced me to sorting algorithms and the concept of complexity.

## The Rules

You start with two empty stacks: a and b. You can give a random list of integers via command line arguments.

Only these moves are allowed:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.

At the end, stack b is empty and all integers are be in stack a, sorted in ascending order.

The program will return the moves that were used be the sorting algorithm.

## Method

I decided to use a sorting method that made the most sense to me. The basic idea was to push the integers in groups into stack b, starting from the smallest numbers. (for example: group 1 = numbers 0-20 and so on...) When everything was in stack b, they were already semi-sorted and all I had to do was to push them back into stack a, this time starting from the largest number.

## Helpful

A cool project to go along side this one is the push_swap visualizer ```https://github.com/o-reo/push_swap_visualizer```.

Using the debug feature of this tester was also very handy to get an idea of how the integers are actually moving between the stacks. https://github.com/LeoFu9487/push_swap_tester.git

