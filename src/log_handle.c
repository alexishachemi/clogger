/*
** EPITECH PROJECT, 2023
** clogger
** File description:
** logging functions & utils
*/

#include <stdarg.h>
#include <string.h>
#include "clogger.h"

static const log_level_str_t log_level_str[] = {
    {DEBUG, "DEBUG"},
    {INFO, "INFO"},
    {WARN, "WARN"},
    {ERROR, "ERROR"},
    {CRITICAL, "CRITICAL"},
    {0, NULL}
};

static int count_file_lines(const char *path)
{
    int c = 0;
    size_t lines = 1;
    FILE *fs = NULL;

    fs = fopen(path, "r");
    if (!fs)
        return -1;
    c = getc(fs);
    while (c != EOF) {
        if (c == '\n')
            lines++;
        c = getc(fs);
    }
    fclose(fs);
    return lines;
}

void trim_log_file(const char *path)
{
    int lines = 0;
    FILE *fs = NULL;

    if (!path)
        return;
    lines = count_file_lines(path);
    if (lines < LOG_MAX_LINES)
        return;
    fs = fopen(path, "w");
    if (fs)
        fclose(fs);
}

bool get_log_level_str(log_level_t level, char *buf)
{
    if (!buf)
        return false;
    for (int i = 0; log_level_str[i].str; i++) {
        if (log_level_str[i].level == level) {
            strcpy(buf, log_level_str[i].str);
            return true;
        }
    }
    return false;
}

bool set_log_level(logger_t *logger, log_level_t level)
{
    char level_str[LOG_LEVEL_SIZE];

    if (!logger)
        return false;
    if (!get_log_level_str(level, level_str))
        return false;
    LOG(logger, INFO, "Log level set to %s", level_str);
    logger->level = level;
    return true;
}

void write_log(logger_t *logger, log_level_t level, const char *f, ...)
{
    char line[LOG_SIZE];
    char level_str[LOG_LEVEL_SIZE];
    size_t written = 0;
    va_list args;

    if (!logger || !logger->fs || level < logger->level || !f)
        return;
    if (!get_log_level_str(level, level_str))
        return;
    va_start(args, f);
    written = sprintf(line, "%s%s", level_str, SEP);
    vsprintf(line + written, f, args);
    va_end(args);
    fwrite(line, strlen(line), 1, logger->fs);
    fwrite("\n", 1, 1, logger->fs);
    fflush(logger->fs);
}
