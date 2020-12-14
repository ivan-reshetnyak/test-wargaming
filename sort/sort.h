#pragma once

#include <algorithm>

template<class data_type>
void quickSort( data_type *left, data_type *right ) {
  if (right - left < 1)
    // 0-sized chunk
    return;

  if (right - left < 2) {
    // Recursion exit
    if (*right < *left)
      std::swap(*left, *right);
    return;
  }

  data_type
    *l0 = left, *r0 = right,
    pivot = *(left + (right - left) / 2);

  while (left < right) {
    if (*left == pivot && *right == pivot)
      left++;
    while (*left < pivot && left < right)
      left++;
    while (*right > pivot && left < right)
      right--;
    if (*left > *right && left < right)
      std::swap(*left, *right);
  }
  quickSort(l0, right - 1);
  quickSort(right + 1, r0);
}
