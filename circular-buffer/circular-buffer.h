#pragma once

template<class data_type>
class circular_buffer {
public:
  circular_buffer( int size ): size(size) {
  }

  virtual ~circular_buffer() {
  }

  virtual void write( const data_type &what ) = 0;

  virtual data_type read() = 0;

  virtual void resize( int newSize ) = 0;

protected:
  int size;
};
