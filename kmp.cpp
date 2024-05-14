#include "kmp.h"

std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
     std::vector<int> result;

    std::vector<int> pf(my_template.length());

    pf[0] = 0;
    for (int k = 0, i = 1; i < my_template.length(); ++i) {
        while ((k > 0) && (my_template[i] != my_template[k]))
            k = pf[k - 1];

        if (my_template[i] == my_template[k])
            k++;

        pf[i] = k;
    }

    for (int k = 0, i = 0; i < text.length(); ++i) {
        while ((k > 0) && (my_template[k] != text[i]))
            k = pf[k - 1];

        if (my_template[k] == text[i])
            k++;

        if (k == my_template.length()) {
            result.push_back(i - my_template.length() + 1);
            k = pf[k - 1];
        }
    }

    return result;
}
