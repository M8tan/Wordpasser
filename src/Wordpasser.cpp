#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <limits>
#include "Wordpasser.h"
#include "base64_rfc4648.hpp"
using base64 = cppcodec::base64_rfc4648;

char Convert_Char_To_Uppercase(char Input_Character);
char Get_Random_Letter();
char Get_Random_Symbol();
bool Random_Bool();
bool Biased_Random_Bool();
bool Contains_Uppercase(std::string Input_String);
bool Contains_Lowercase(std::string Input_String);
bool Contains_Number(std::string Input_String);
bool Contains_Symbol(std::string Input_String);
std::string Generate_Password();
bool Analyze_Password(std::string Input_Password);
void Display_Menu();
std::string Encrypt_Password(const std::string input, char key);
std::string Decrypt_Password(const std::string encoded, char key);
std::string xorEncrypt(const std::string input, char key);
int ValidateIntType(const std::string prompt);


int main(){
    srand(time(0));
    std::cout << "Hello! welcome to the wordpasser,\nA password generator, encryptor and decryptor :)\n";
    std::cout << "You can generate a password, take an existing password and encrypt it using a certain shift number,\nOr decrypt an existing password with a shift number.\n";
    std::cout << "For example:\nGenerate a password, encrypt it using a 3 shift, and then u can take the output, decrypt it to shift 3 and get the original password.\n";
    Display_Menu();
    bool Running = true;
    int User_Choice;
    while (Running){
        User_Choice = ValidateIntType("Choose an operation: ");
        
        switch(User_Choice){
            case 0:
                Display_Menu();
                break;
            case 1:{
                std::string New_Password = Generate_Password();
                std::cout << "Done! your new password is " << New_Password << "\n";
                break;}
            case 2:{
                std::string Original_Password;
                std::string Encrypted_Password;
                int Password_Shift;
                std::cout << "Enter password: ";
                std::cin >> Original_Password;
                Password_Shift = ValidateIntType("Enter encryption shift {number}: ");
                Encrypted_Password = Encrypt_Password(Original_Password, Password_Shift);
                std::cout << "Done! your encrypted password is " << Encrypted_Password << "\n";
                break;}
            case 3:{
                std::string Original_Password;
                std::string Decrypted_Password;
                int Password_Shift;
                std::cout << "Enter password: ";
                std::cin >> Original_Password;
                Password_Shift = ValidateIntType("Enter encryption shift {number}: ");
                Decrypted_Password = Decrypt_Password(Original_Password, Password_Shift);
                std::cout << "Done! your decrypted password is " << Decrypted_Password << "\n";
                break;}
            case 4:
                Running = false;
                break;
            default:
                break;
        }
    }
    
    return 0;
}

void Display_Menu(){
    std::cout << "Optional operations:\n";
    std::cout << "0. Dispaly this menu\n";
    std::cout << "1. Generate a password\n";
    std::cout << "2. Encrypt a password\n";
    std::cout << "3. Decrypt a password\n";
    std::cout << "4. Exit wordpasser\n";
}
char Convert_Char_To_Uppercase(char Input_Character){
    switch (Input_Character){
        case 'a':
        Input_Character = 'A';
        break;
        case 'b':
        Input_Character = 'B';
        break;
         case 'c':
        Input_Character = 'C';
        break;
        case 'd':
        Input_Character = 'D';
        break;
         case 'e':
        Input_Character = 'E';
        break;
        case 'f':
        Input_Character = 'F';
        break;
         case 'g':
        Input_Character = 'G';
        break;
        case 'h':
        Input_Character = 'H';
        break;
         case 'i':
        Input_Character = 'I';
        break;
        case 'j':
        Input_Character = 'J';
        break;
         case 'k':
        Input_Character = 'K';
        break;
        case 'l':
        Input_Character = 'L';
        break;
         case 'm':
        Input_Character = 'M';
        break;
        case 'n':
        Input_Character = 'N';
        break;
         case 'o':
        Input_Character = 'O';
        break;
        case 'p':
        Input_Character = 'P';
        break;
         case 'q':
        Input_Character = 'Q';
        break;
        case 'r':
        Input_Character = 'R';
        break;
         case 's':
        Input_Character = 'S';
        break;
        case 't':
        Input_Character = 'T';
        break;
         case 'u':
        Input_Character = 'U';
        break;
        case 'v':
        Input_Character = 'V';
        break;
         case 'w':
        Input_Character = 'W';
        break;
        case 'x':
        Input_Character = 'X';
        break;
         case 'y':
        Input_Character = 'Y';
        break;
        case 'z':
        Input_Character = 'Z';
        break;
        default:
        break;
    }
    return Input_Character;
}
char Get_Random_Letter(){
    
    int Random_Number = (rand() % 26) +1;
    char Random_Char;
    switch (Random_Number){
        case 1:
        Random_Char = 'a';
        break;
        case 2:
        Random_Char = 'b';
        break;
         case 3:
        Random_Char = 'c';
        break;
        case 4:
        Random_Char = 'd';
        break;
         case 5:
        Random_Char = 'e';
        break;
        case 6:
        Random_Char = 'f';
        break;
         case 7:
        Random_Char = 'g';
        break;
        case 8:
        Random_Char = 'h';
        break;
         case 9:
        Random_Char = 'i';
        break;
        case 10:
        Random_Char = 'j';
        break;
         case 11:
        Random_Char = 'k';
        break;
        case 12:
        Random_Char = 'l';
        break;
         case 13:
        Random_Char = 'm';
        break;
        case 14:
        Random_Char = 'n';
        break;
         case 15:
        Random_Char = 'o';
        break;
        case 16:
        Random_Char = 'p';
        break;
         case 17:
        Random_Char = 'q';
        break;
        case 18:
        Random_Char = 'r';
        break;
         case 19:
        Random_Char = 'r';
        break;
        case 20:
        Random_Char = 't';
        break;
         case 21:
        Random_Char = 'u';
        break;
        case 22:
        Random_Char = 'v';
        break;
         case 23:
        Random_Char = 'w';
        break;
        case 24:
        Random_Char = 'x';
        break;
         case 25:
        Random_Char = 'y';
        break;
        case 26:
        Random_Char = 'z';
        break;
        default:
        break;
    }
    return Random_Char;
}
char Get_Random_Symbol(){
    
    int Random_Number = (rand() % 8) +1;
    char Random_Symbol;
    switch (Random_Number){
        case 1:
        Random_Symbol = '!';
        break;
        case 2:
        Random_Symbol = '@';
        break;
         case 3:
        Random_Symbol = '#';
        break;
        case 4:
        Random_Symbol = '$';
        break;
         case 5:
        Random_Symbol = '%';
        break;
        case 6:
        Random_Symbol = '^';
        break;
         case 7:
        Random_Symbol = '&';
        break;
        case 8:
        Random_Symbol = '*';
        break;
        default:
        break;
    }
    return Random_Symbol;
}
bool Random_Bool(){
    int Random_Number = (rand() % 2) + 1;
    if (Random_Number == 1){
        return true;
    } else {
        return false;
    }
}
bool Biased_Random_Bool(){
    int Random_Number = (rand() % 100) + 1;
    if (Random_Number >= 30){
        return true;
    } else {
        return false;
    }
}
std::string Generate_Password(){
    while(true){
        std::string Password = "";
        for (int i = 1; i < 26; i++){
            bool Coin_Flip = Biased_Random_Bool(); /*Biased_Random_Bool*/
            std::string Tempo;
            if(Coin_Flip){
                char Character = Get_Random_Letter();
                bool Uppercase_The_Letter_Bool = Random_Bool();
                if (Uppercase_The_Letter_Bool){
                    Character = Convert_Char_To_Uppercase(Character);
                    Tempo = Character;
                } else {
                    Tempo = Character;
                }
            } else {
                bool New_Coin_Flip = Random_Bool();
                if(New_Coin_Flip){
                int Num = (rand() % 9) + 1;
                std::string Character = std::to_string(Num);
                Tempo = Character;
                } else {
                    char Symbol = Get_Random_Symbol();
                    std::string Character = std::string(1, Symbol);
                    Tempo = Character;
                }
            }
            Password += Tempo;
        }
        if(Analyze_Password(Password)){
            return Password;
        }
    }
}

bool Contains_Uppercase(std::string Input_String){
    for (char Character : Input_String){
        if(isupper(static_cast<unsigned>(Character))){
            return true;
        } 
    }
    return false;
}
bool Contains_Lowercase(std::string Input_String){
    for (char Character : Input_String){
        if(islower(static_cast<unsigned>(Character))){
            return true;
        } 
    }
    return false;
}
bool Contains_Number(std::string Input_String){
    return Input_String.find_first_of("0123456789") != std::string::npos;
}
bool Contains_Symbol(std::string Input_String){
    int Count = 0;
    for(int i = 0; i < Input_String.length(); i++){
        char Current_Character = Input_String[i];
        if(Current_Character == '!' || Current_Character == '@' || Current_Character == '#' || Current_Character == '$' || Current_Character == '%' || Current_Character == '^' || Current_Character == '&' || Current_Character == '*'){
            Count++;
        }         
    }
    if(Count == 0){
        return false;
    } else {
        return true;
    }
}
bool Analyze_Password(std::string Input_Password){
    int Input_Password_Length = Input_Password.length();
    bool Input_Password_Contains_Uppercase = Contains_Uppercase(Input_Password);
    bool Input_Password_Contains_Lowercase = Contains_Lowercase(Input_Password);
    bool Input_Password_Contains_Number = Contains_Number(Input_Password);
    bool Input_Password_Contains_Symbol = Contains_Symbol(Input_Password);

    if(Input_Password_Contains_Uppercase && Input_Password_Contains_Lowercase && Input_Password_Contains_Number && Input_Password_Contains_Symbol && Input_Password_Length == 25){
        return true;
    } else {
        return false;
    }

}
std::string xorEncrypt(const std::string input, char key) {
    std::string output = input;
    for (char& c : output) {
        c ^= key;
    }
    return output;
}
std::string Encrypt_Password(const std::string input, char key) {
    std::string encrypted = xorEncrypt(input, key);
    return base64::encode(encrypted);
}
std::string Decrypt_Password(const std::string encoded, char key) {
    std::vector<unsigned char> decoded_bytes = base64::decode(encoded);
    std::string decoded(decoded_bytes.begin(), decoded_bytes.end());
    return xorEncrypt(decoded, key);
}
int ValidateIntType(const std::string prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (!std::cin.fail()) return value;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input {needs to be a number}\n";
    }
}
std::string Generate_Password_BU(){
    std::string Password = "";
    for (int i = 1; i < 21; i++){
        bool Coin_Flip = Biased_Random_Bool(); /*Biased_Random_Bool*/
        std::string Tempo;
        if(Coin_Flip){
            char Character = Get_Random_Letter();
            bool Uppercase_The_Letter_Bool = Random_Bool();
            if (Uppercase_The_Letter_Bool){
            Character = Convert_Char_To_Uppercase(Character);
            Tempo = Character;
            } else {
                Tempo = Character;
            }
        } else {
            int Num = (rand() % 9) + 1;
            std::string Character = std::to_string(Num);
            Tempo = Character;
        } Password += Tempo;
    } return Password;}

    /*Tests and stuff -
    
    bool Found_Problem = false;
    std::vector<std::string> Problems_Array;
    int Problem_Number = 0;
    for (int j = 0; j < 10000; j++){
        std::string Temp_Password = Generate_Password();
        bool Temp_Password_Strong = Analyze_Password(Temp_Password);
        if (!Temp_Password_Strong){
            Found_Problem = true;
            Problems_Array.push_back(Temp_Password);
            Problem_Number++;
        }
    }
    std::string Found_Problem_S = Found_Problem ? "true" : "false";
    std::cout << "Found a problem within 10000 passwords: " << Found_Problem_S << "\n";
    if(Found_Problem){
        std::cout << Problem_Number << " bad passwords:\n";
        for(std::string Problem : Problems_Array){
            std::cout << Problem << "\n";
        }
    }
        */