//
// Created by dmirty on 7/22/23.
//

#ifndef MODULATOR_H
#define MODULATOR_H
#include "../Lib/Include/dsp_module.h"
#include "../Lib/Include/Mapper.h"
#include "../Lib/Include/shaping_impulse.h"
#include <iostream>

class modulator
{
    modulation_type modulationtype;
public:
    modulator(modulation_type modulation);
    dsp_result exec(uint8_t* input, size_t size,  uint8_t sps, uint8_t span, shaping_impulse_type impulse_form = SQUARE, float param = -1);
};

#endif //MODULATOR_H
