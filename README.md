# Minimalistic ANSI Color Formatting Library for C

This is a lightweight ANSI color formatting library for C programming language. It provides functions to format text with various colours, bold, and highlighted styles, making it easy to add colourised output to your console applications.

## Features

- **Support for ANSI Color Codes**: Format text with a wide range of ANSI color codes.
- **Simple API**: Easy-to-use functions for applying colours, bold, and highlight styles to text.
- **Lightweight**: Minimalistic implementation with no external dependencies.
- **Portable**: Compatible with most terminals supporting ANSI escape codes.

## Usage

### Installation

Simply clone the repository or download the source files and include them in your project.

### Example

```c
#include "min/hint/hint.h"
#include <stdio.h>

int main()
{
    char * text = "Hello, World!";
    char * coloured_text = hintColour(text, HINT_COLOUR_RED);
    printf("%s\n", coloured_text);
    free(coloured_text);
    return 0;
}
```
