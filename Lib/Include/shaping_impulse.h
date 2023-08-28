//
// Created by dmirty on 8/9/23.
//

#ifndef TESTS_SHAPING_IMPULSE_H
#define TESTS_SHAPING_IMPULSE_H
#include "dsp_module.h"
#include <complex>

enum shaping_impulse_type{
    SQUARE,
    RC,
    GAUSSIAN
};

struct shaping_impulse{
    dsp_result impulse;
    shaping_impulse(shaping_impulse_type impulse_form, uint8_t span, uint8_t sps, float param );
};


#endif //TESTS_SHAPING_IMPULSE_H
