//
// Created by dmirty on 7/22/23.
//

#ifndef MODULATOR_H
#define MODULATOR_H
#include "../Lib/Include/dsp_module.h"
#include "../Lib/Include/Mapper.h"
#include <iostream>

class modulator
{
    modulation_type modulationtype;
public:
    modulator(modulation_type modulation);
    dsp_result exec(uint8_t* input, size_t size, uint8_t sps);
};

#endif //MODULATOR_H
