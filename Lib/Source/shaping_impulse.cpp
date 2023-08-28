//
// Created by dmirty on 8/9/23.
//

#include "../Include/shaping_impulse.h"
//#include <iostream>

shaping_impulse::shaping_impulse(shaping_impulse_type impulse_form, uint8_t span, uint8_t sps, float param) {
    uint16_t length = span*sps;
    impulse.head = new std::complex<float>[length];
    impulse.size = length;
    float t[length];
    //float bt=0.3;
    float alpha;
    switch (impulse_form) {
        case SQUARE:
            for (int i = 0; i < length; ++i) impulse.head[i] = 1;
            break;
        case RC:
            for (int i = 0; i < length; ++i) impulse.head[i] = (sin(i / (length - 1.0)*M_PI*2 - M_PI/2) +1)/2;
            break;
        case GAUSSIAN:
            if (param < 0 || param > 1) throw std::runtime_error("A shaping impulse parameter is incorrect or not initialized");
            alpha = sqrt(log2(2)/2)/(param);
            for (int i = 0; i < length; ++i) t[i]=-span/2.0 + span/(length - 1.0) * i;
            for (int i = 0; i < length; ++i) impulse.head[i] = (sqrt(M_PI)/alpha)*exp(-(pow(t[i]*M_PI/alpha,2)));
            break;  
    }

}