/*
** EPITECH PROJECT, 2023
** clogger
** File description:
** logging functions
*/

#pragma once

#include <stdio.h>
#include <stdbool.h>

#define LOG_SIZE 2048
#define EXPAND(m) #m
#define STRINGIFY(m) EXPAND(m)
#define LOG_MAX_LINES 100
#define LOG_LEVEL_SIZE 9
#define SEP " - "
#define LOG_META __DATE__ " "  __TIME__ SEP __FILE__":"STRINGIFY(__LINE__)

/// @brief Convenience macro for writing log messages using printf-style
/// formatting. Includes metadata.
/// @param lptr logger pointer
/// @param lvl log level
/// @param f format string
/// @param ... arguments to the format string
/// @note Does nothing if lptr is NULL.
/// @note Does nothing if the log level of lptr is higher than lvl.
#define LOG(lptr, lvl, f...) write_log(lptr, lvl, LOG_META SEP f)

typedef enum {
    DEBUG = 0,
    INFO = 1,
    WARN = 2,
    ERROR = 3,
    CRITICAL = 4,
} log_level_t;

typedef struct {
    log_level_t level;
    const char *str;
} log_level_str_t;

typedef struct {
    FILE *fs;
    log_level_t level;
} logger_t;


/// @brief Initializes the logger. This function must be called even if
/// the logger is disabled.
/// @param logger logger to initialize
/// @param path path to the log file, if NULL the logger will be disabled
/// @return true if the logger was successfully initialized, false otherwise
bool logger_init(logger_t *logger, const char *path);

/// @brief Deinitializes the logger.
/// @param logger logger to deinitialize
void deinit_logger(logger_t *logger);

/// @brief Get the string representation of a log level.
/// @param level log level
/// @param buf buffer to store the string representation. Must be at least
/// LOG_LEVEL_SIZE bytes long.
/// @return true if the operation was succesful, false otherwise
bool get_log_level_str(log_level_t level, char *buf);

/// @brief Set the log level of a logger.
/// @param logger logger to set the log level of
/// @param level log level
/// @return true if the operation was succesful, false otherwise
bool set_log_level(logger_t *logger, log_level_t level);

/// @brief Clears the file at `path` if it is longer than LOG_MAX_LINES.
/// @param path path to the log file, if invalid, the function is a no-op
void trim_log_file(const char *path);

/// @brief Writes a log message to the logger using printf-style formatting.
/// Use this function directtly if you want to write log messages without
/// metadata or have your own metadata format. Otherwise, prefer the LOG macro.
/// @param logger the logger to write to
/// @param level log level
/// @param f format string
/// @param ... arguments to the format string
/// @note Does nothing if lptr is NULL.
/// @note Does nothing if the log level of lptr is higher than lvl.
void write_log(logger_t *logger, log_level_t level, const char *f, ...);
