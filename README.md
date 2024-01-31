# 42-get_next_line
This project is about creating your own function that returns a line read from one file descriptor or more, if you consider the bonus project requirement. The function `get_next_line()` returns `NULL`, if there is nothing else to read or if an error occurred. It should work as expected both when reading a file and when reading from the standard output.

</br>

# Content

1. [Usage](#usage)
2. [Description](#description)
3. [Algorithm](#algorithm)

</br>

## Usage

Follow the steps below to test the project: 

1. Clone the repository:
```bash
$> git clone https://github.com/Sepahsalar/42-get_next_line.git
```
2. Write your own test file and compile it with this command:
```bash
$> cc -Wall -Wextra -Werror -D BUFFER_SIZE='any_number' <files>.c
```
- It should work with and without the  `-D BUFFER_SIZE` flag.

</br>

## Description

This projects is about creating a function that, allows to read a line ending with a newline character `\n` from a file descriptor, without knowing its size beforehand. One of the goal of this project is to learn a highly interesting new concept in `C` programming: **static variables**, and to gain a deeper understanding of allocations, whether they happen on the stack memory or in the heap memory, the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables.

</br>

## Algorithm

There are different ways to solve the problem. You can use either an array or a singly linked list. I chose to use an array because it's simpler to implement.

The project contains six files. The ones that ends with `_bonus` are the bonus project that reads a line from two or more file descriptors at the same time. To sum up,

- [`get_next_line.h`](get_next_line.h): Contains the prototypes of all necessary functions to the project.
- [`get_next_line.c`](get_next_line.c): It has five functions. They are:
  - `get_next_line()`: It is the project main function. It reads lines from the file descriptor, utilizing the other functions to handle buffering and extraction. Static variable `str` retains information between function calls;
  - `ft_read()`: Reads lines from a file descriptor up to a specified buffer size.
  - `ft_con()`: Determines the length of the line, including newline characters.
  - `ft_line()`: Extracts a line from the input string.
  - `ft_new_str()`: Generates a new string without the extracted line.
- [`get_next_line_utils.c`](get_next_line_utils.c): Implements helper functions to manipulate heap(or dynamic) memory and arrays.
