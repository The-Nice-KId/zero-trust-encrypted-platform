#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>
#include <sys/mman.h>

class SecureBuffer {
public:
    explicit SecureBuffer(size_t size);
    ~SecureBuffer();

    SecureBuffer(const SecureBuffer&)          =delete;
    SecureBuffer operator=(const SecureBuffer&)=delete;
    SecureBuffer(SecureBuffer&&)               =default;

    uint8_t*         data()       noexcept  {return data_.data();}
    const uint8_t*   data() const noexcept  {return data_.data();}
    size_t           size() const noexcept  {return data_.size();}

private:
    std::vector<uint8_t> data_;
    void zeroize() noexcept;
};