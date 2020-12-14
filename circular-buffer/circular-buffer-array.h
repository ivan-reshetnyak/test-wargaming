#pragma once

template<class data_type>
class circular_buffer_array {
public:
  circular_buffer_array( int size ) {
    resize(size);
  }

  ~circular_buffer_array() {
    if (data != nullptr)
      delete[] data;
  }

  void write( const data_type &what ) {
    data[writePosition++] = what;
    writePosition %= size;
  }

  data_type read() {
    data_type read = data[readPosition++];
    readPosition %= size;
    return read;
  }

  void resize( int newSize ) {
    size = newSize;
    if (data != nullptr)
      delete[] data;
    data = new data_type[size];
    readPosition = writePosition = 0;
  }

private:
  int size, writePosition, readPosition;
  data_type *data = nullptr;
};
