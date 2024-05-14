/*
** EPITECH PROJECT, 2023
** clogger
** File description:
** initializing functions
*/

#include "clogger.h"

bool init_enabled_logger(logger_t *logger, const char *path)
{
    if (!logger || !path)
        return false;
    trim_log_file(path);
    logger->fs = fopen(path, "a");
    if (!logger->fs)
        return false;
    logger->level = INFO;
    return true;
}

bool init_disabled_logger(logger_t *logger)
{
    if (!logger)
        return false;
    logger->fs = NULL;
    logger->level = INFO;
    return true;
}

void deinit_logger(logger_t *logger)
{
    if (logger && logger->fs) {
        fclose(logger->fs);
        logger->fs = NULL;
    }
}
