/*
** EPITECH PROJECT, 2023
** clogger
** File description:
** log writing functions
*/

#include <string.h>
#include "clogger.h"

void logger_va_log(logger_t *l, log_level_t lvl, const char *f, va_list args)
{
    char line[LOG_SIZE];
    char level_str[LOG_LEVEL_SIZE];
    size_t written = 0;

    if (!l || !l->fs || lvl < l->level || !f)
        return;
    if (!get_log_level_str(lvl, level_str))
        return;
    written = sprintf(line, "%s%s", level_str, SEP);
    vsnprintf(line + written, LOG_SIZE - written, f, args);
    fwrite(line, strlen(line), 1, l->fs);
    fwrite("\n", 1, 1, l->fs);
    fflush(l->fs);
}

void logger_log(logger_t *l, log_level_t lvl, const char *f, ...)
{
    va_list args;

    if (!l || !l->fs || lvl < l->level || !f)
        return;
    va_start(args, f);
    logger_va_log(l, lvl, f, args);
    va_end(args);
}

bool logger_log_true(logger_t *l, log_level_t lvl, const char *f, ...)
{
    va_list args;

    if (!l || !l->fs || lvl < l->level || !f)
        return true;
    va_start(args, f);
    logger_va_log(l, lvl, f, args);
    va_end(args);
    return true;
}

bool logger_log_false(logger_t *l, log_level_t lvl, const char *f, ...)
{
    va_list args;

    if (!l || !l->fs || lvl < l->level || !f)
        return false;
    va_start(args, f);
    logger_va_log(l, lvl, f, args);
    va_end(args);
    return false;
}

void *logger_log_null(logger_t *l, log_level_t lvl, const char *f, ...)
{
    va_list args;

    if (!l || !l->fs || lvl < l->level || !f)
        return NULL;
    va_start(args, f);
    logger_va_log(l, lvl, f, args);
    va_end(args);
    return NULL;
}
