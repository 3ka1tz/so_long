# Ft_printf

*This project has been created as part of the 42 curriculum by [elopez-u](https://profile.intra.42.fr/users/elopez-u).*

## Description

This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.

## Instructions

1. Clone the repository:
```bash
git clone https://github.com/3ka1tz/ft_printf.git
```

2. Move into it:
```bash
cd ~/ft_printf/
```

3. Build the project:
```bash
make
```

4. Use the function as you want:
```c
#include "~/ft_printf.h"

ft_printf("Hi there!");
```

test.c: used to detect if there is any difference between the og printf's and my custom ft_printf's outputs.
```bash
cc -Wall -Wextra -Werror test.c libftprintf.a && ./a.out
```

## Resources

https://en.wikipedia.org/wiki/Printf  
https://www.ibm.com/docs/en/i/7.6.0?topic=functions-printf-print-formatted-characters  
https://github.com/Tripouille/printfTester
