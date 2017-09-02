#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// all line endings should use \r\n so it can work even with the terminal in raw mode
// this is subject to change, so use this macro whenever you output a newline
#define println(msg, ...) printf(msg "\r\n", ##__VA_ARGS__)

// debug output utilities

#ifndef DEBUG_all
#define DEBUG_all 0
#endif
#ifndef DEBUG_default
#define DEBUG_default DEBUG_all
#endif
#ifndef DEBUG_instr
#define DEBUG_instr DEBUG_all
#endif
#ifndef DEBUG_debug
#define DEBUG_debug DEBUG_all
#endif

#if DEBUG_default
#define TRACE_default TRACE__
#else
#define TRACE_default TRACE__NOP
#endif
#if DEBUG_instr
#define TRACE_instr TRACE__
#else
#define TRACE_instr TRACE__NOP
#endif
#if DEBUG_debug
#define TRACE_debug TRACE__
#else
#define TRACE_debug TRACE__NOP
#endif

#define TRACE__NOP(msg, ...) do {} while(0)
#define TRACE__(msg, ...) printf(msg, ##__VA_ARGS__)
#define TRACE_(chan, msg, ...) CONCAT(TRACE_, chan)(msg, ##__VA_ARGS__)
#define TRACE(msg, ...) TRACE_(DEFAULT_CHANNEL, msg, ##__VA_ARGS__)
#define TRACELN_(chan, msg, ...) TRACE_(chan, msg "\r\n", ##__VA_ARGS__)
#define TRACELN(msg, ...) TRACE(msg "\r\n", ##__VA_ARGS__)
#ifndef DEFAULT_CHANNEL
#define DEFAULT_CHANNEL default
#endif

#define TODO(msg, ...) { println("TODO: " msg, ##__VA_ARGS__); abort(); }
#define FIXME(msg, ...) println("FIXME " msg, ##__VA_ARGS__)
#define DIE(msg) { perror(msg); abort(); }
