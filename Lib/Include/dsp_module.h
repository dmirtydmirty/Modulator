//
// Created by dmirty on 7/22/23.
//

#ifndef DSP
#define DSP

#include <memory>
#include <utility>
#include <complex>
#include <cstring>
#include <fftw3.h>

struct dsp_result{
    std::complex<float>* head;
    size_t size;
};

class dsp
{

public:
    static dsp_result fft(std::complex<float>* input, size_t size);
    static dsp_result ifft(std::complex<float>* input, size_t size);
    static dsp_result upsammple(std::complex<float> *input, size_t size, uint8_t sps, uint8_t span);
    static dsp_result shaping_filter(std::complex<float>* input, size_t size, std::complex<float>* impulse_response,
                                     size_t impulse_response_size);
};

#endif //DSP