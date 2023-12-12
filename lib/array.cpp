#include "array.h"

Array::Array1D::Array2D::Array3D& Array::Array1D::Array2D::Array3D::operator=(const uint32_t value) {
  if (!CheckRange(temp_x,temp_y,temp_z)) {
    exit(EXIT_FAILURE);
  }
  uint32_t index = temp_z * size_y * size_x + temp_y * size_x + temp_x;
  CheckNumber(value, index);
  return *this;
}

bool Array::Array1D::Array2D::Array3D::CheckRange(int64_t x, int64_t y, int64_t z) {
  return x >= 0 && y >= 0 && z >= 0;
}

bool Array::Array1D::Array2D::Array3D::CheckRange(int64_t x, int64_t y, int64_t z) const{
  return x >= 0 && y >= 0 && z >= 0;
}

bool Array::Array1D::Array2D::Array3D::operator==(const uint32_t value) {
	return Get() == value;
}

bool Array::CheckRange(int64_t x, int64_t y, int64_t z) {
    return x >= 0 && y >= 0 && z >= 0;
}

uint8_t Array::MyPow(uint32_t x, uint32_t y) {
  if (y>=8) {
    exit(EXIT_FAILURE);
  }
  uint8_t result = 1;
  for (int i = 0; i < y; ++i) {
    result *= x;
  }
  return result;
}

void Array::CheckNumber(int num, uint32_t index) {
    if (num >= k17bit) {
        exit(EXIT_FAILURE);
    }
    if (num >= k16bit) {
        data[index] = num % k16bit;
        uint8_t bit = MyPow(static_cast<uint32_t>(2), index % 8);
        one_bit[index / 8] += bit;
    } else {
        data[index] = num;
    }
}

void Array::Array1D::Array2D::Array3D::CheckNumber(int num, uint32_t index) {
  if (num >= k17bit) {
    exit(EXIT_FAILURE);
  }
  if (num >= k16bit) {
    data[index] = num % k16bit;
    uint8_t bit = MyPow(static_cast<uint32_t>(2), index % 8);
    one_bit[index / 8] += bit;
  } else {
    data[index] = num;
  }
}

uint32_t Array::Array1D::Array2D::Array3D::Get() {
    if (!CheckRange(temp_x,temp_y,temp_z)) {
    exit(EXIT_FAILURE);
  }
  uint32_t index = temp_z * size_y * size_x + temp_y * size_x + temp_x;
  temp_x = temp_y = temp_z = -1;
  return data[index] + one_bit[index] * k16bit;
}

uint32_t Array::Array1D::Array2D::Array3D::Get() const {
    if (!CheckRange(temp_x, temp_y, temp_z)) {
        exit(EXIT_FAILURE);
    }
    uint32_t index = temp_z * size_y * size_x + temp_y * size_x + temp_x;
    return data[index] + one_bit[index] * k16bit;
}

Array Array::operator+(const Array& rhs) {
  if (size_x * size_y * size_z !=
      rhs.size_x * rhs.size_y * rhs.size_z) {
    exit(EXIT_FAILURE);
  }
  Array result(size_x, size_y, size_z);
  int num = 0;
  for (uint32_t i = 0; i < size_x * size_y * size_z; ++i) {
    result.CheckNumber(data[i] + rhs.data[i], i);
  }
  return result;
}

Array Array::operator-(const Array& rhs) {
  if (size_x * size_y * size_z !=
      rhs.size_x * rhs.size_y * rhs.size_z) {
    exit(EXIT_FAILURE);
  }
  Array result(size_x, size_y, size_z);
  int num = 0;
  for (uint32_t i = 0; i < size_x * size_y * size_z; ++i) {
    result.CheckNumber(data[i] - rhs.data[i], i);
  }
  return result;
}

Array Array::operator*(const int number) {
  Array result(size_x, size_y, size_z);
  int num = 0;
  for (uint32_t i = 0; i < size_x * size_y * size_z; ++i) {
    result.CheckNumber(data[i] * number, i);
  }
  return result;
}

std::ostream& operator<<(std::ostream& os, Array::Array1D::Array2D::Array3D& arr) {
  os << arr.Get();
  return os;
}

std::istream& operator>>(std::istream& is, Array::Array1D::Array2D::Array3D& arr) {
  int temp;
  is >> temp;
  arr = temp;
  return is;
}

bool operator==(const Array& lhs, const Array& rhs) {
    if (lhs.Getsize_x() != rhs.Getsize_x() || lhs.Getsize_y() != rhs.Getsize_y() || lhs.Getsize_z() != rhs.Getsize_z())
    {
        exit(EXIT_FAILURE);
    }
    for (uint32_t i = 0; i < lhs.Getsize_x(); ++i)
    {
        for (uint32_t j = 0; j < lhs.Getsize_y(); ++j)
        {
            for (uint32_t k = 0; k < lhs.Getsize_z(); ++k)
            {
                if (lhs[i][j][k].Get() != rhs[i][j][k].Get())
                {
                    return false;
                }
            }
        }
    }
    return true;
}