
#pragma once

#include <vector>
#include <string.h>
#include <mutex>
#include "utils.h"


class Step {
public:
    u16 end;
    u16 std;
    u16 k[96];
};


class Server;


class Mapper {
public:
    Mapper(Server *server);
    void add(ISlice name, u16 value);
    u16 find(ISlice name);
private:
    Server *server;
    std::mutex mutex;
    char *buf, *buf_t;
    int _size;
    int _cap;
    inline Step* get_step(int n) {return (Step*)(buf + (n - 1) * sizeof(Step)); };
    inline Step* get_step_t(int n) {
        if(buf_t == NULL) return get_step(n);
        return (Step*)(buf_t + (n - 1) * sizeof(Step));
    };
    u16 _next();
};
