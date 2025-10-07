#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <vector>

char Convert_Char_To_Uppercase(char Input_Character);
char Get_Random_Letter();
bool Random_Bool();
bool Biased_Random_Bool();
bool Contains_Uppercase(std::string Input_String);
bool Contains_Lowercase(std::string Input_String);
bool Contains_Number(std::string Input_String);
std::string Generate_Password();
bool Analyze_Password(std::string Input_Password);
std::string Encrypt_Password(std::string Input_Password);
int main(){
    srand(time(0));
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
    return 0;
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
bool Analyze_Password(std::string Input_Password){
    int Input_Password_Length = Input_Password.length();
    bool Input_Password_Contains_Uppercase = Contains_Uppercase(Input_Password);
    bool Input_Password_Contains_Lowercase = Contains_Lowercase(Input_Password);
    bool Input_Password_Contains_Number = Contains_Number(Input_Password);

    if(Input_Password_Contains_Uppercase && Input_Password_Contains_Lowercase && Input_Password_Contains_Number && Input_Password_Length == 20){
        return true;
    } else {
        return false;
    }

}
std::string Encrypt_Password(std::string Input_Password){
    return "Yay";
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
