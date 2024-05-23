#include "lzw.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> dictionary;

void buildDictionary(){
    for (int i = 0; i < 256; i++){
        string ch = "";
        ch += char(i);
        dictionary[ch] = i;
    }
}

vector<int> compress(string s){
    vector<int>m;
    buildDictionary();
    string w = "";
    char k;
    int dictSize = 256;

    for (char &c : s){
        k = c;
        string wc = w + k;
        if (dictionary.find(wc) != dictionary.end()){
            w = wc;
        }
        else{
            m.push_back(dictionary[w]);
            dictionary[wc] = dictSize++;
            w = k;
        }
    }

    if (!w.empty()){
        m.push_back(dictionary[w]);
    }
    return m;
}

string decompress(vector<int> compressedData) {
    unordered_map<int, string> dictionaryy;
    for (int i = 0; i < 256; i++) {
        string ch = "";
        ch += char(i);
        dictionaryy[i] = ch;
    }

    int dictSize = 256;
    int prevCode = compressedData[0];
    string entry=dictionaryy[prevCode];
    string output = entry;
    string w=entry;

    for (int i = 1; i < compressedData.size(); i++) {
        int currCode = compressedData[i];
        if (dictionaryy.find(currCode) == dictionaryy.end()) {
            entry = dictionaryy[prevCode];
            entry += entry[0];
        } else {
            entry = dictionaryy[currCode];
        }
        output += entry;
        dictionaryy[dictSize++] = w + entry[0];
        w = entry;
        prevCode = currCode;
    }

    return output;
}
