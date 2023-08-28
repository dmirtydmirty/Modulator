# Библиотека реализует цифровую линейную модуляцию
На данный момент реализованы следуюие типы модуляции:
1) BPSK
2) QPSK

Поддреживается только полтный отклик
## Зависимости
#### FFTW:
Скачать можно [здесь](https://fftw.org/download.html)
## Примеры испольования 
#### Модуляция последовательности
```c++
        size_t length = 4;
        uint8_t bits[length] = {1,2,3,4};
        uint8_t sps = 3;
        uint8_t span = 2;

        modulator QPSKmod(QPSK);
        modulator BPSKmod(BPSK);

        dsp_result resQPSK = QPSKmod.exec(bits, length, sps, span, GAUSSIAN, 0.3);
        dsp_result resBPSK = BPSKmod.exec(bits, length, sps, span, GAUSSIAN, 0.3);

        for (int i = 0; i < res.size; ++i) {
            std::cout << res.head[i] <<std::endl;
        }
```
