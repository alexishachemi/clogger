/*
** EPITECH PROJECT, 2023
** clogger
** File description:
** initializing functions
*/

#include "clogger.h"

bool logger_init(logger_t *logger, const char *path)
{
    if (!logger)
        return false;
    logger->level = INFO;
    logger->fs = NULL;
    if (!path)
        return true;
    trim_log_file(path);
    logger->fs = fopen(path, "a");
    return logger->fs != NULL;
}

void logger_deinit(logger_t *logger)
{
    if (logger && logger->fs) {
        fclose(logger->fs);
        logger->fs = NULL;
    }
}
