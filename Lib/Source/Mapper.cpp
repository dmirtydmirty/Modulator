//
// Created by dmirty on 7/22/23.
//

#include "../Include/Mapper.h"
#include <cmath>

Mapper::Mapper(modulation_type type) : modulationtype(type) {;}

dsp_result Mapper::exec(uint8_t *input, size_t size) {
    dsp_result result;
    uint8_t mask;
    switch (modulationtype) {
        case BPSK:
            result = {new std::complex<float>[size*8], size*8};
            for (int i = 0; i < size; ++i) {
                mask = 1;
                for (int j = 0; j < 8; ++j) {
                    if (mask & input[i]) result.head[8*i+j] = 1;
                    else result.head[8*i+j] = -1;
                    mask = mask << 1;
                }
            }
            break;
        case QPSK:
            result = {new std::complex<float>[size*4], size*4};
            for (int i = 0; i < size; ++i) {
                mask = 3;
                for (int j = 0; j < 4; ++j) {
                    if ((input[i] & mask) == 0) result.head[4*i+j] = std::complex<float>(sqrt(2), sqrt(2));
                    else if ((input[i] & mask) == pow(2, 2*j)) result.head[4*i+j] = std::complex<float>(sqrt(2), -sqrt(2));
                    else if ((input[i] & mask) == pow(2, 2*j+1)) result.head[4*i+j] = std::complex<float>(-sqrt(2), sqrt(2));
                    else result.head[4*i+j] = std::complex<float>(-sqrt(2), -sqrt(2));
                    mask = mask << 2;
                }
            }
            break;
    }
    return result;
}