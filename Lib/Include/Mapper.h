//
// Created by dmirty on 7/22/23.
//

#ifndef MAPPER_H
#define MAPPER_H

#include "dsp_module.h"
enum modulation_type
{
    BPSK,
    QPSK
};

class Mapper
{
    modulation_type modulationtype;
public:
    Mapper(modulation_type type);
    dsp_result exec(uint8_t* input, size_t size);
};


#endif //MAPPER_H
