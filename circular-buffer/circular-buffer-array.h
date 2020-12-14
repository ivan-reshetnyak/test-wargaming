#pragma once

#include "circular-buffer.h"

template<class data_type>
class circular_buffer_array : public circular_buffer<data_type> {
public:
  circular_buffer_array( int size ) : circular_buffer<data_type>(size) {
    resize(size);
  }

  ~circular_buffer_array() {
    if (data != nullptr)
      delete[] data;
  }

  void write( const data_type &what ) override {
    data[writePosition++] = what;
    writePosition %= circular_buffer<data_type>::size;
  }

  data_type read() override {
    data_type read = data[readPosition++];
    readPosition %= circular_buffer<data_type>::size;
    return read;
  }

  void resize( int newSize ) override {
    circular_buffer<data_type>::size = newSize;
    if (data != nullptr)
      delete[] data;
    data = new data_type[circular_buffer<data_type>::size];
    readPosition = writePosition = 0;
  }

private:
  int writePosition, readPosition;
  data_type *data = nullptr;
};
