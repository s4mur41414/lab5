#pragma once
#include <cstdint>
#include <iostream>

class Array {
public:
    class Array1D {
        friend Array;
    public:
        class Array2D {
			friend Array;
        public:
            class Array3D {
                friend Array;
            public:
                Array3D(uint32_t x, uint32_t y, uint32_t z, uint16_t *lower_bit,
                        uint8_t *first_bit, int32_t index_1, int32_t index_2, int32_t index_3) {
                    size_x = x;
                    size_y = y;
                    size_z = z;
                    data = lower_bit;
                    one_bit = first_bit;
					temp_x = index_1;
					temp_y = index_2;
					temp_z = index_3;
                }


                Array3D(uint32_t x, uint32_t y, uint32_t z){
                    size_x = x;
					size_y = y;
					size_z = z;
					data = new uint16_t[x * y * z]{ 0 };
					one_bit = new uint8_t[(x * y * z + 7) / 8]{ 0 };
                }

                uint32_t Get();

                uint32_t Get() const;

				bool operator==(const uint32_t value);

                Array3D &operator=(const uint32_t value);

                void CheckNumber(int num, uint32_t index);

                bool CheckRange(int64_t x, int64_t y, int64_t z);

                bool CheckRange(int64_t x, int64_t y, int64_t z) const;

            private:
                uint32_t size_x;
                uint32_t size_y;
                uint32_t size_z;
				int32_t temp_x;
				int32_t temp_y;
				int32_t temp_z;
                uint16_t *data;
                uint8_t *one_bit;
            }; // Class Array3D
            Array2D(uint32_t x, uint32_t y, uint32_t z, uint16_t *lower_bit,
                    uint8_t *first_bit, int32_t index, int32_t index1) {
                size_x = x;
                size_y = y;
                size_z = z;
                data = lower_bit;
                one_bit = first_bit;
                temp_x = index;
                temp_y = index1;
            }

            Array3D operator[](int32_t index) {
                return Array3D{size_x, size_y, size_z, data, one_bit, temp_x, temp_y, index};
            }

            const Array3D operator[](int32_t index) const{
                return Array3D{ size_x, size_y, size_z, data, one_bit, temp_x, temp_y, index };
            }

        private:
            int32_t temp_x;
            int32_t temp_y;
            uint32_t size_x;
            uint32_t size_y;
            uint32_t size_z;
            uint16_t *data;
            uint8_t *one_bit;
        }; // class Array2D

        Array1D(uint32_t x, uint32_t y, uint32_t z, uint16_t *lower_bit,
                uint8_t *first_bit, int64_t index) {
            size_x = x;
            size_y = y;
            size_z = z;
            data = lower_bit;
            one_bit = first_bit;
            temp_x = index;
        }

        Array2D operator[](int32_t index) {
            return Array2D(size_x, size_y, size_z, data, one_bit, temp_x, index);
        }

        const Array2D operator[](int32_t index) const {
            return Array2D(size_x, size_y, size_z, data, one_bit, temp_x, index);
        }

    private:

        int32_t temp_x;
        uint32_t size_x;
        uint32_t size_y;
        uint32_t size_z;
        uint16_t *data;
        uint8_t *one_bit;
    };  // Class Array3D
    static const int k16bit = 65536;
    static const int k17bit = 131072;


    Array(uint32_t x, uint32_t y, uint32_t z) : size_x{ x }, size_y{ y }, size_z{ z } {
        data = new uint16_t[x * y * z]{0};
        one_bit = new uint8_t[(x * y * z + 7) / 8]{0};
    }

    static Array MakeArray(uint32_t x, uint32_t y, uint32_t z) {
        return Array(x, y, z);
    }

    ~Array() {}

    static uint8_t MyPow(uint32_t x, uint32_t y);

    bool CheckRange(int64_t x, int64_t y, int64_t z);

    Array1D operator[](int32_t index) {
        return Array1D(size_x, size_y, size_z, data,
            one_bit, index);
    }

    const Array1D operator[](int32_t index) const {
        return Array1D(size_x, size_y, size_z, data,
            one_bit, index);
    }

    void CheckNumber(int num, uint32_t index);

    uint32_t Getsize_x() const { return size_x; }
    uint32_t Getsize_y() const { return size_y; }
    uint32_t Getsize_z() const { return size_z; }

    Array operator+(const Array &rhs);

    Array operator-(const Array &rhs);

    Array operator*(const int number);


private:
    uint16_t *data;
    uint8_t *one_bit;
    uint32_t size_x;
    uint32_t size_y;
    uint32_t size_z;
};

std::ostream& operator<<(std::ostream& os, Array& arr);
std::istream& operator>>(std::istream& is, Array& arr);

bool operator==(const Array& lhs, const Array& rhs);