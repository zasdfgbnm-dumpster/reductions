#pragma once

namespace at {

class TensorIterator;

struct SplitUntil32Bit {
  struct iterator {
    TensorIterator& operator*() const;
    iterator& operator++() { return *this; }
    bool operator==(const iterator& other) const { return false; }
    bool operator!=(const iterator& other) const { return false; }
  };

  iterator begin() const { return {}; }
  iterator end() const { return {}; }
};

class TensorIteratorBase {
public:
  int ndim() const { return 0; }
  IntArrayRef shape() const { return {}; }
  int64_t numel() const { return 0; }
  int ntensors() const { return 0; }
  int noutputs() const { return 0; }
  int ninputs() const { return 0; }
  IntArrayRef strides(int arg) const { return {}; }
  int64_t element_size(int arg) const { return 0; }
  int num_reduce_dims() const { return 0; }
  void* data_ptr(int arg) const { return nullptr; }

  bool can_use_32bit_indexing() const { return false; }
  bool should_accumulate() const { return false; }
  bool is_final_output() const { return false; }
  int64_t num_output_elements() const { return 0; }
  IntArrayRef view_offsets() const { return {}; }

  SplitUntil32Bit with_32bit_indexing() const { return {}; }
};

class TensorIterator: public TensorIteratorBase {};

TensorIterator& SplitUntil32Bit::iterator::operator*() const {
    static TensorIterator ti;
    return ti;
}

}