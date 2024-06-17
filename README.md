# clogger
### A simple logger in C

clogger is a simple logging utility in C. It was made with the intention to be used in my EPITECH projects so it is compliant with the EPITECH coding style rules.

## Dependencies

- [GNU Compiler Collection](https://gcc.gnu.org/) (11.4.0)
- [GNU Make](https://www.gnu.org/software/make/) (4.3)

## Building

to build the library you can use the included Makefile:

```sh
make
```

It will then build the `libclogger.a` binary

## Installing

You can install the library into your system using the following command:

```sh
make install
```

You can then uninstall it using:

```sh
make uninstall
```

## Usage

See the following example code:

```c
#include <clogger.h>

int main(void)
{
    logger_t logger;

    if (!logger_init(&logger, NULL, true, stdout))
        return 84;
    LOG(&logger, WARN, "Hello, world!");
    logger_deinit(&logger);
    return 0;
}

```

Logging uses the `vsnprintf` function so it is compatible with the [printf format identifiers](https://cplusplus.com/reference/cstdio/printf/). The maximum length of a log line is set by `LOG_SIZE` (see [clogger.h](include/clogger.h))

You also need to add the library to the linker when compiling:

```sh
gcc myfile.c -lclogger
```

Running the code will print a similar line on the standard output:

```log
INFO - May 14 2024 13:48:21 - tests/main.c:16 - Hello, world!
```

When logging into a file, if the file has more than `LOG_MAX_LINES` lines, is is cleared first.
