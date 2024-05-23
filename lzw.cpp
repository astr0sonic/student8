#include "lzw.h"
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, int> dictionary;

void buildDictionary(){
    for (int i = 0; i < 256; i++){
        std::string ch = "";
        ch += char(i);
        dictionary[ch] = i;
    }
}

std::vector<int> compress(const std::string& text) {
    std::vector<int> compressed;
    buildDictionary();
    std::string w = "";
    char k;
    int dictSize = 256;

    for (char c : text){
        k = c;
        std::string wc = w + k;
        if (dictionary.find(wc) != dictionary.end()){
            w = wc;
        }
        else{
            compressed.push_back(dictionary[w]);
            dictionary[wc] = dictSize++;
            w = k;
        }
    }

    if (!w.empty()){
        compressed.push_back(dictionary[w]);
    }

    return compressed;
}

std::string decompress(const std::vector<int>& compressed) {
    std::unordered_map<int, std::string> dictionaryy;
    for (int i = 0; i < 256; i++) {
        std::string ch = "";
        ch += char(i);
        dictionaryy[i] = ch;
    }

    int dictSize = 256;
    int prevCode = compressed[0];
    std::string entry=dictionaryy[prevCode];
    std::string decompressed = entry;
    std::string w=entry;

    for (int i = 1; i < compressed.size(); i++) {
        int currCode = compressed[i];
        if (dictionaryy.find(currCode) == dictionaryy.end()) {
            entry = dictionaryy[prevCode];
            if (!entry.empty()) { // Проверяем, не пустая ли строка
                entry += entry[0]; 
            }
        } else {
            entry = dictionaryy[currCode];
        }
        decompressed += entry;
        dictionaryy[dictSize++] = w + entry[0];
        w = entry;
        prevCode = currCode;
    }

    return decompressed;
}