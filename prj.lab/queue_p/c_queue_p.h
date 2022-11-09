#ifdef __cplusplus
#include <cstdint>
using std::int32_t;
using std::uint64_t;
extern "C" {
#else
#include <stdint.h>
#endif

typedef enum {
    kGood = 0,
    kHandlerError,
    kOutOfRange
} ErrorCode;

typedef uint64_t QueueHandler;

ErrorCode CreateQueue(QueueHandler* queue);

ErrorCode CloneQueue(QueueHandler source, QueueHandler* queue);

ErrorCode DestroyQueue(QueueHandler* queue);

ErrorCode Pop(QueueHandler queue);

ErrorCode Push(QueueHandler queue, int32_t value);

ErrorCode IsEmpty(QueueHandler queue, int32_t* result);

ErrorCode Top(QueueHandler queue, int32_t* result);

const char* WhatIs(ErrorCode err);

#ifdef __cplusplus
};
#endif
