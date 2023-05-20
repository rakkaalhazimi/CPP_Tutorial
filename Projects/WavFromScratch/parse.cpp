#include<bitset>
#include<iostream>
#include<fstream>
#include<cstring>


void showBytesRepr(char* blocks) {
    for (int i = 0; i < sizeof(blocks); i++) {
        std::cout << std::bitset<8>(blocks[i]) << " " <<  std::endl;
    }
}

void showIntRepr(char* blocks) {
    int value;
    std::memcpy(&value, blocks, sizeof(blocks));
    std::cout << "Integer repr: " << value << std::endl;
}

void readBytes(std::ifstream &file, int position, int size) {
    char memblock[size];

    file.seekg(position);
    std::cout << "Current position: " << file.tellg() << std::endl;
    file.read(memblock, size);

    std::cout << memblock << std::endl;
    std::cout << "Size of block: " << sizeof(memblock) << " bytes" << std::endl;
    // showBytesRepr(memblock);
    showIntRepr(memblock);
}


int main() {

    std::ifstream audioFile;
    audioFile.open("waveform.wav", std::ios::binary);

    readBytes(audioFile, 4, 4);

    audioFile.close();

    return 0;
}