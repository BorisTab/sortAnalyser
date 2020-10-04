//
// Created by boris on 15.09.2020.
//

#include <exception>

class FontLoadFromFileError: std::exception {
    const char* errorStr = "Can't load font from source file. Set default font";
public:
    const char* what() const noexcept override;
};
