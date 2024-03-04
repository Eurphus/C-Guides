# C-Guides
A small collection of guides for learning C

##  Important Information

### C Information

#### Procedural
Imperative: Uses statements to change a programs state

Code becomes a series of logical instructions to execute.



#### Statically Typed

| Type | What is it? | Languages |
|--|--|--|
| Static Typing  | All variable types are defined, types are known at compile time. Advantages include better bug catching, as compiler can detect type issues during compiling. | Java, C# |
| Dynamic Typing | Type is associated with run-time values, does not need to be explicitly defined in the code Advantages include it being easier to write code | Racket, Javascript, Python |\

Statically typed means variable types are defined and known before the compiler does it's thin



### Memory

1 byte = 8 bits

* int : 4 bytes
* bool : 1 byte
* char : 1 or 4 byte
* struct
    * At least the sum of all types within the structure
    * Typically compiler will pad/offset in a way that is most efficient
