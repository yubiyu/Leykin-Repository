#pragma once

#include "being.h"

class PC : public Being
{
public:
    static PC*pc;

    PC();
    ~PC();
};
