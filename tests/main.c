/*
** EPITECH PROJECT, 2023
** clogger
** File description:
** test
*/

#include "clogger.h"

int main(void)
{
    logger_t logger;

    if (!logger_init(&logger, "test.log"))
        return 84;
    LOG(&logger, WARN, "Hello, world!");
    deinit_logger(&logger);
    return 0;
}
