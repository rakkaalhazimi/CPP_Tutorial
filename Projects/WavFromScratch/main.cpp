#include<iostream>
#include<cmath>
#include<fstream>


const int sampleRate = 44100;
const int bitDepth = 16;
const int numChannel = 1;


class SineOscillator {
    float frequency, amplitude, angle = 0.0f, offset = 0.0;

    public:
        SineOscillator(float freq, float amp) : frequency(freq), amplitude(amp) {
            offset = 2 * M_PI * frequency / sampleRate;
        };

        float process() {
            auto sample = amplitude * std::sin(angle);
            angle += offset;
            return sample;
        }
};

void writeToFile(std::ofstream &file, int value, int size) {
    file.write(reinterpret_cast<const char*>(&value), size);
}


int main() {

    int duration = 2;
    std::ofstream audioFile;
    audioFile.open("waveform.wav", std::ios::binary);
    SineOscillator sineOscillator(440, 0.5);

    // Header chunk
    audioFile << "RIFF";
    audioFile << "----";
    audioFile << "WAVE";

    // Format chunk
    audioFile << "fmt ";
    writeToFile(audioFile, 16, 4); // Size
    writeToFile(audioFile, 1, 2); // Compression code, 1 = PCM
    writeToFile(audioFile, numChannel, 2); // Number of Channel
    writeToFile(audioFile, sampleRate, 4); // Sample Rate
    writeToFile(audioFile, sampleRate * bitDepth / 8, 4); // Byte Rate
    writeToFile(audioFile, numChannel * bitDepth / 8, 2); // Block Align
    writeToFile(audioFile, bitDepth, 2); // Bit Depth

    // Data chunk
    audioFile << "data";
    audioFile << "----";

    int preAudioPosition = audioFile.tellp();

    auto maxAmplitude = std::pow(2, bitDepth - 1) - 1;
    for (int i = 0; i < sampleRate * duration; i++) {
        auto sample = sineOscillator.process();
        int intSample = static_cast<int>(sample * maxAmplitude);
        writeToFile(audioFile, intSample, 2);
    }

    int postAudioPosition = audioFile.tellp();

    // Write the file size except the first 8 bytes (RIFF ----)
    audioFile.seekp(4, std::ios::beg);
    writeToFile(audioFile, postAudioPosition - 8, 4);

    std::cout << preAudioPosition << std::endl;
    std::cout << postAudioPosition << std::endl;
    std::cout << postAudioPosition - 8 << std::endl;

    audioFile.close();

    return 0;
}