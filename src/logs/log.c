/**
 * @description  系统日志函数 System log function
 * @copyright    2019 moss@nodie.ink
 * @version      1.0.0
 * @author       莫斯莫斯 mossnodie
 * @file         log.c
 * @date         2019-01-06
 */

#include "log.h"

_log *_log_instance = NULL;

_log _get_log_instance() {
    if (!_log_instance)
        _new_log(_log_instance);
    return *_log_instance;
}

void _new_log(_log *_self) {
    _log *self = (_p_log) malloc(sizeof(_log));
    int buffer_size = _LOG_BUFFER_SIZE;
    self->log_information = (char *) malloc(sizeof(char) * buffer_size);
    self->log_type = _LOG_OFF;
    *_self = *self;
    _log_instance = self;
}

void _log_update(int level, char *s) {
    switch (level) {
        case 0:
            break;
        case 1:
            printf("信息:%s\n", s);
            break;
        case 2:
            printf("警告:%s\n", s);
            break;
        case 3:
            printf("错误:%s\n", s);
            break;
    }
}