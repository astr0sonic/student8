#include "volume.h"
#include<iostream>

int getMaxVolume(int a, int b, int c, int n, int* arr) {
    int maxVolume = 0;

    for (int startColumn = 0; startColumn < n; ++startColumn) {
        for (int endColumn = startColumn + 1; endColumn < n; ++endColumn) {
            if (endColumn - startColumn <= a && std::min(arr[startColumn], arr[endColumn]) <= c)
            {
                int length = endColumn - startColumn;
                int height = std::min(arr[startColumn], arr[endColumn]);
                int volume = b * length * height;
                if (volume > maxVolume) {
                    maxVolume = volume;
                }
            }
        }
    }
    
    return maxVolume;
}
