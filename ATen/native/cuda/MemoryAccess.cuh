#pragma once

// #include <cstdint>
// #include <type_traits>
// #include <c10/util/Exception.h>
// #include <c10/util/TypeCast.h>
// #include <c10/macros/Macros.h>
// #include <ATen/core/Array.h>
// #include <ATen/detail/FunctionTraits.h>
// #include <ATen/cuda/detail/OffsetCalculator.cuh>

// #include <thrust/tuple.h>

namespace at { namespace native { namespace memory {

// aligned vector generates vectorized load/store on CUDA
template<typename scalar_t, int vec_size>
struct alignas(sizeof(scalar_t) * vec_size) aligned_vector {
  scalar_t val[vec_size];
};

}}} // namespace at::native::memory
