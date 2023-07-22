//
// Created by dmirty on 7/22/23.
//

#include "../Include/Modulator.h"

modulator::modulator(modulation_type modulation) : modulationtype(modulation) {;}

dsp_result modulator::exec(uint8_t *input, size_t size, uint8_t sps) {

    Mapper mapper(modulationtype);

    std::complex<float>* h = new std::complex<float>[sps];

    for (int i = 0; i < sps; ++i) h[i] = 1;

    dsp_result symbols = mapper.exec(input, size);

    dsp_result upsampled_symbols = dsp::upsammple(symbols.head, symbols.size, sps);

    return dsp::shaping_filter(upsampled_symbols.head, upsampled_symbols.size, h, sps);
}