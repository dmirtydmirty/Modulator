#include "../Include/dsp_module.h"
#include <iostream>

dsp_result dsp::fft(std::complex<float> *input, size_t size) {

    dsp_result result = {new std::complex<float>[size], size};

    fftw_complex* fftw_input = new fftw_complex[size];
    fftw_complex* fftw_output = new fftw_complex[size];

    for (int i = 0; i < size; ++i)
    {
        fftw_input[i][0] = (input+i)->real();
        fftw_input[i][1] = (input+i)->imag();
    }

    fftw_plan fft_plat = fftw_plan_dft_1d(size, fftw_input, fftw_output, FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(fft_plat);

    for (int i = 0; i < size; ++i)
    {
        *(result.head+i) = std::complex<double>(fftw_output[i][0], fftw_output[i][1]);
    }

    fftw_free(fftw_input);
    fftw_free(fftw_output);

    return result;
}

dsp_result dsp::ifft(std::complex<float> *input, size_t size) {

    dsp_result result = {new std::complex<float>[size], size};

    fftw_complex* fftw_input = new fftw_complex[size];
    fftw_complex* fftw_output = new fftw_complex[size];

    for (int i = 0; i < size; ++i)
    {
        fftw_input[i][0] = (input+i)->real();
        fftw_input[i][1] = (input+i)->imag();
    }

    fftw_plan fft_plat = fftw_plan_dft_1d(size, fftw_input, fftw_output, FFTW_BACKWARD, FFTW_ESTIMATE);

    fftw_execute(fft_plat);

    for (int i = 0; i < size; ++i)
    {
        *(result.head+i) = std::complex<double>(fftw_output[i][0]/size, fftw_output[i][1]/size);
    }
    return result;
}

dsp_result dsp::upsammple(std::complex<float> *input, size_t size, uint8_t sps, uint8_t span) {
    dsp_result result = {new std::complex<float>[size*sps + (span-1)*sps], size*sps+(span-1)*sps};

    for (int i = 0; i < size; ++i) result.head[sps * i] = input[i];
    return result;
}

dsp_result dsp::shaping_filter(std::complex<float> *input, size_t size, std::complex<float> *impulse, size_t impulse_size) {
    // ожижается, что входные данные после апсемплинга под нужную длинну ИХ

    std::complex<float>* full_impulse = new std::complex<float>[size];

    for (int i = 0; i < size; ++i) {
        full_impulse[i] = (i < impulse_size) ? impulse[i] : std::complex<float>();
    }

    dsp_result input_spectrum = dsp::fft(input, size);
    dsp_result impulse_spectrum = dsp::fft(full_impulse, size);

    std::complex<float>* S1xS2 = new std::complex<float>[input_spectrum.size];

    for (int i = 0; i < input_spectrum.size; ++i) {
        S1xS2[i] = input_spectrum.head[i] * impulse_spectrum.head[i];
    }

    return dsp::ifft(S1xS2, input_spectrum.size);
}