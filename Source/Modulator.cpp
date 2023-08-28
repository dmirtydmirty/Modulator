//
// Created by dmirty on 7/22/23.
//

#include "../Include/Modulator.h"

modulator::modulator(modulation_type modulation) : modulationtype(modulation) {;}

dsp_result modulator::exec(uint8_t *input, size_t size,  uint8_t sps, uint8_t span, shaping_impulse_type impulse_form, float param) {

    Mapper mapper(modulationtype);

    auto h = shaping_impulse(impulse_form, span, sps, param).impulse;

    dsp_result symbols = mapper.exec(input, size);

    dsp_result upsampled_symbols = dsp::upsammple(symbols.head, symbols.size, sps, span);

    return dsp::shaping_filter(upsampled_symbols.head, upsampled_symbols.size, h.head, h.size);
}