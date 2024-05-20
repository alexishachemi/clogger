/*
** EPITECH PROJECT, 2023
** clogger
** File description:
** initializing functions
*/

#include "clogger.h"

bool logger_init(logger_t *l, const char *path, bool clear_file)
{
    if (!l)
        return false;
    l->level = INFO;
    l->fs = NULL;
    if (!path)
        return true;
    if (clear_file) {
        l->fs = fopen(path, "w");
        if (l->fs)
            fclose(l->fs);
    }
    trim_log_file(path);
    l->fs = fopen(path, "a");
    return l->fs != NULL;
}

void logger_deinit(logger_t *logger)
{
    if (logger && logger->fs) {
        fclose(logger->fs);
        logger->fs = NULL;
    }
}
