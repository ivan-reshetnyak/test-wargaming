#pragma once

#include "circular-buffer.h"

template<class data_type>
class circular_buffer_list : public circular_buffer<data_type> {
public:
  circular_buffer_list( int size ) : circular_buffer<data_type>(size) {
    resize(size);
  }

  ~circular_buffer_list() {
    if (writePosition != nullptr) {
      entry
        *toDelete = writePosition,
        *current = writePosition->next;
      do {
        delete toDelete;
        toDelete = current;
        current = current->next;
      } while (current != writePosition);
    }
  }

  void write( const data_type &what ) override {
    writePosition->data = what;
    writePosition = writePosition->next;
  }

  data_type read() override {
    data_type read = readPosition->data;
    readPosition = readPosition->next;
    return read;
  }

  void resize( int newSize ) override {
    circular_buffer<data_type>::size = newSize;
    if (writePosition == nullptr)
      writePosition = new entry;
    for (int i = 1; i < newSize; ++i)
      writePosition->extend(new entry());
    readPosition = writePosition;
  }

private:
  class entry {
  public:
    data_type data;
    entry *next;

    entry( const data_type &data = data_type(), entry *next = nullptr ) : data(data), next(next) {
      if (this->next == nullptr)
        this->next = this;
    }

    void extend( entry *newNext ) {
      newNext->next = next;
      next = newNext;
    }
  };

  entry
    *readPosition = nullptr,
    *writePosition = nullptr;
};
