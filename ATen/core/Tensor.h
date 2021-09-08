#pragma once

#include <c10/core/ScalarType.h>

namespace at {

class Tensor {
public:
    c10::ScalarType scalar_type() const {
        return {};
    }
};

}