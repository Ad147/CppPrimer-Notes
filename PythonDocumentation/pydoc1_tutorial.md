pydoc1_tutorial.md

Python Tutorial (3.8.3)
================================================================================

A~0f27

The tutorial informally introduces basic concepts and features of Python;  
For standard objects and modules, see *library-index*;  
For a more formal definition of the language, see *reference-index*;  
To write extensions in C/C++, read *extending-index* and *c-api-index*

Chapter 1 Whetting Your Appetite
--------------------------------------------------------------------------------

Python is just the language for you:

Shell scripts are best at moving around files and changing text data, but not GUI apps;  
C/C++ takes a lot of development time.

Python offers more structre and support for large programs than shell;  
On the other hand, more error cheching than C.

The interpreter can be used to experiment with features, to write throw-away programs, to test functions during bottom-up program development, or as a desk calculator.

Programs written in Pyton are typically much shorter than C/C++:
1. high-level data types make complex operations in a single statement
2. statement grouping by indentation instead of brackets
3. no variable declarations

Extensibility: easy to add new built-in functions or module in C to the interpreter, either to perform critical operations at max speed, or to link Python programs to libs that may only be avaiable in binary form.

By the way, the language is named after the BBC show "Monty Python’s Flying Circus" and has nothing to do with
reptiles.

Chapter 2 Using the Python Interpreter
--------------------------------------------------------------------------------

### 2.2 The Interpreter and Its Environment

#### 2.2.1 Source Code Encoding

Python source files are treated as encoded in UTF-8 by default;  
To declare another encoding, add a special comment at first line of file, like:  
`# -*- coding: cp1252 -*-`.

One exception to the first line rule is a UNIX "shebang" line, like:  
`#!/usr/bin/env python3`  
`# -*- coding: cp1252 -*-`

Chapter 3 An Informal Introduction to Python
--------------------------------------------------------------------------------

Comments start with the hash character `#`, and extend to the end of the physical line.

### 3.1 Using Python as a Calculator

#### 3.1.1 Numbers

Operators: `+` `-` `*` `/` `//` `%` `**`

Division `/` always returns a float, `//` returns int.

In interactive mode, the last printed expression is assigned to variable `_`.

In addition to int and float, there are other types of numbers: `Decimal` and `Fraction`.

Built-in support for complex numbers, use `j` or `J` suffix to indicate imaginary part (3+5j).

#### 3.1.2 Strings

- strings enclosed in `'...'` or `"..."`
- concatenate by `+`
- repeat by `*`
- strings can be indexed
- strings are immutable (cannot assign)

#### 3.1.3 Lists

- `lst = [1, 2, 3]`
- negative index (start with -1)
- slice (end index exclusive)
- concatenation: `[1, 2] + [3, 4]`
- `list.append()`
- assignment to slices: `lst[2:4] = [4, 5]`
- `len(lst)`

### 3.2 First Steps Towards Programming

- multiple assignment: `a, b = 0, 1`
- in conditions, zero and empty sequences are false
- in `print()`
  - items are split by a space
  - the keyword argument `end` can be used to avoid newline or end output with custom string: `print(a, end=',')`

Chapter 4 More Control Flow Tools
--------------------------------------------------------------------------------

### 4.1 `if` Statements

- `if` `elif` `else`
- `if...elif...elif...` sequence is a subtitute for switch or case statements in other languages

### 4.2 `for` Statements

- python's `for` iterates over items of any sequence

### 4.3 The `range()` Function

- `range(end)`
- `range(beg, end, step)`
- to iterate over indices of a sequence:
  - `range(len(lst))`
  - `enumerate(lst)`
- to get a list from a range: `list(rang(7))`

### 4.4 `break` and `continue` Statements, and `else` Clauses on Loops

- loops can have an `else` clause, executed when the loop terminated *not* by a `break`
- `try` (exception handling) can also have a `else`, runs when no exception occurs

### 4.5 `pass` Statements

`pass` does nothing, like `;` in C

### 4.6 Defining Functions

- `def functionName(formalParameters):`
- first line of function body can optionally be a string literal, as documentation string, or docstring
- `global` `nonlocal`
- even functions without a return do return a value: `None`

### 4.7 More on Defining Functions

Arguments of functions have 3 forms:

#### 4.7.1 Default Argument Values

- `def func(arg1, arg2=2, arg3="hi"):`
- `in` tests whether sequence contains
- **important warning**: the default value evaluated only once, if the default is a mutable (list, dict, instance of classes), the result will accumulate:
```py
def f(a, L=[]):
    L.append(a)
    return L

f(1)
f(2)
# will get
[1]
[1, 2]

# to avoid:
def f(a, L=None):
    if L is None:
        L = []
    L.append(a)
    return L
```

#### 4.7.2 Keyword Arguments

- use keyword arg can ignore order of args:
  - `func(1, arg4=[1], arg3="hello")`
  - but keyword args must follow positional args
- a final formal parameter of the form `**name` receives a dictionary containing all keyword arguments except for those corresponding to a formal parameter
- this may be combined with a formal parameter of the form `*name` which receives a tuple containing the positional arguments beyond the formal parameter list
- `*name` must occur before `**name`

#### 4.7.3 Special Parameters

```py
def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
      -----------    ----------     ----------
          |              |              |
          |     Positional or keyword   |
          |                             - Keyword only
          -- Positional only
```

Use case of the 3 parameters:
- Use positional-only if you want the name of the parameters to not be available to the user. This is useful when parameter names have no real meaning, if you want to enforce the order of the arguments when the function is called or if you need to take some positional parameters and arbitrary keywords.
- Use keyword-only when names have meaning and the function definition is more understandable by being explicit with names or you want to prevent users relying on the position of the argument being passed.
- For an API, use positional-only to prevent breaking API changes if the parameter’s name is modified in the future.

#### 4.7.4 Arbitary Argument Lists

- `def f(*args)`
- the args will be wrapped up in a tuple

#### 4.7.5 Unpacking Argument Lists

- when args are already in a list or tuple but need to be unpacked for a function call requiring separate positional args:
  - use `*` to unpack list or tuple
  - `range(*lst)`
- use `**` to unpack dict

#### 4.7.6 Lambda Expressions

- small anonymous functions can be created with the `lambda` keyword
- `lambda a, b: a+b` returns the sum of its two args
- lambda functions can be used wherever function objects are required
- lambdas are syntactically restricted to a single expression
- semantically, they are just syntactic sugar for a normal function definition
- like nested function definitions, lambda functions can reference variables from the containing scope

#### 4.7.7 Documentation Strings

- first line should always be a short, concise summary of purpose, begin with a capital letter and end with a period
- if there are more lines, the second line should be blank
- example:
```py
def my_function():
    """Do nothing, but document it.

    No, really, it doesn't do anything.
    """
    pass

>>> print(my_function.__doc__)
Do nothing, but document it.

    No, really, it doesn't do anything.
```

#### 4.7.8 Function Annotations

- function annotations are completely optional metadata information about the types used by user-defined functions
- annotations are stored in the `__annotations__` attribute of the function as a dictionary and have no effect on any other part of the function
- parameter annotations: `(param: str = "default")`
- return annotations: `f() -> int`

The following example has a positional argument, a keyword argument, and the return value annotated:
```py
>>> def f(ham: str, eggs: str = 'eggs') -> str:
...     print("Annotations:", f.__annotations__)
...     print("Arguments:", ham, eggs)
...     return ham + ' and ' + eggs
...
>>> f('spam')
Annotations: {'ham': <class 'str'>, 'return': <class 'str'>, 'eggs': <class 'str'>}
Arguments: spam eggs
'spam and eggs'
```

### 4.8 Intermezzo: Coding Style

Every Python developer should read PEP8 at some point;  
here are the most important points extracted from PEP8:

- 4-space indentation, no tabs
- wrap lines, do not exceed 79 chars
- use blank lines to separate funcs, classes and blocks inside funcs
- when possible, put comments on a line of their own
- use docstrings
- use spaces around ops and commas, but not brackets
- `UpperCamelCase` for classes, `lowercase_with_underscores` for funcs, always use `self` as first method arg

Chapter 5 Data Structures
--------------------------------------------------------------------------------

### 5.1 More on Lists

All list methods:
- `append(x)` == `a[len(a):] = [x]`
- `extend(iterable)`: append all items from iterable, == `a[len(a):] = iterable`
- `insert(i, x)`
- `remove(x)`: remove the first item with value x
- `pop([i])`: remove item at i, and return it; if no i, remove tail
- >p37

--------------------------------------------------------------------------------

#### 7.1.1 Formatted String Literals

- also called f-strings for short
- can include expression values inside a string
- prefix with `f` or `F`, write expressions as `{expr}`
- optional format specifier control the format:
  - `f"{math.pi:.3f}"`
  - integer after `:` for padding
  - convert the value before formatted:
    - `!a` applies ascii()
    - `!s` applies str()
    - `!r` applies repr()

for ref on format specifications, see ref guide for formatspec