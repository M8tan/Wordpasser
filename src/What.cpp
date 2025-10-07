    #include <string>
    #include <iostream>

    std::string xor_encrypt(std::string data, char key) {
        std::string encrypted_data = data;
        for (char& c : encrypted_data) {
            c ^= key;
        }
        return encrypted_data;
    }

    std::string xor_decrypt(std::string data, char key) {
        return xor_encrypt(data, key);
    }

    int main(){
        std::string Password_1 = "!@#$%^&*()[]{}\\':;~`";
        std::string Password_2 = xor_encrypt(Password_1, 3);
        std::cout << Password_2 << '\n';
        Password_2 = xor_decrypt(Password_2, 3);
        std::cout << Password_2;

        return 0;
    }