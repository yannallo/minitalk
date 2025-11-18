# Ft_printf

![Status](https://img.shields.io/badge/Status-Finished-success)
![Language](https://img.shields.io/badge/Language-C-blue)
![Norminette](https://img.shields.io/badge/Norminette-%E2%9C%93-success)

## My own printf function

This is a reimplementation of the `printf` function from the C standard library.
It introduces to structured programming, variadic programming and number base conversions.


## Supported format specifier

| Specifier | Description |
|----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address |
| `%d`, `%i`| Integer |
| `%u` | Unsigned integer |
| `%x`, `%X` | Hexadecimal (lower/uppercase) |
| `%%` | Percent sign|

## Installation

```Bash
# Clone repository
git clone https://github.com/yannallo/ft_printf.git

# Build
make -C ft_printf
```

## Usage

Include the header in your file and link during compilation.

```Bash
gcc -Ift_printf main.c -Lft_printf -lftprintf -o test
```

### Example `main.c`
```C 
#include "ft_printf.h"

int main(void)
{
  char s[15] = "Hello world !!";

  ft_printf("Message:\n%s\n", s);
  return 0;
}
