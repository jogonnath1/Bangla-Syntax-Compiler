#pragma once
#include <string>

// বাংলা সংখ্যায় রূপান্তর করুন (0-9 → ০-৯)
inline std::string বাংলাসংখ্যা(long long n) {
    if (n < 0) return "-" + বাংলাসংখ্যা(-n);
    std::string eng = std::to_string(n);
    std::string result;
    const char* বাংলাঅঙ্ক[] = {"০","১","২","৩","৪","৫","৬","৭","৮","৯"};
    for (char ch : eng) {
        result += বাংলাঅঙ্ক[ch - '0'];
    }
    return result;
}
