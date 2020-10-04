//
// Created by boris on 15.09.2020.
//

#include "uiExceptions.h"

const char* FontLoadFromFileError::what() const noexcept {
    return errorStr;
}
