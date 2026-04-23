#pragma once
#include "secure_buffer.hpp"
#include <vector>
#include <cstdint>

struct EncryptedPayload {
    std::vector<uint8_t> ciphertext;
    std::vector<uint8_t> iv;          
    std::vector<uint8_t> auth_tag;    
};

class CryptoEngine {
public: 
        EncryptedPayload encrypt(
        SecureBuffer&              dek,
        const std::vector<uint8_t>& plaintext,
        const std::vector<uint8_t>& aad
    );

    std::vector<uint8_t> decrypt(
        SecureBuffer&              dek,
        const EncryptedPayload&    payload,
        const std::vector<uint8_t>& aad
    );

};