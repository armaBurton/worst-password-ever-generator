#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int WORD_LENGTH = 50;
const int YEAR_LENGTH = 5;
const int SPECIAL_CHARACTER = 2;

void getWord(char word[]);
void getYear(char year[]);
void getSpecial(char special[]);

int main(){
    char word[WORD_LENGTH];
    char year[YEAR_LENGTH];
    char special[SPECIAL_CHARACTER];

    getWord(word);
    getYear(year);
    getSpecial(special);
    
    system("pause");
    return 0;
}

void getWord(char word[]){
    cout << "Enter a word: ";
    cin.get(word, WORD_LENGTH, '\n');
    cin.ignore();
}

void getYear(char year[]){
    bool loopState;
    do{
        loopState = false;
        cout << "Enter a year: ";
        cin.get(year, YEAR_LENGTH, '\n');
        cin.ignore();
        if (strlen(year) != 4){
            cout << "No time-travellers allowed.\n";
            memset(year, '\0', YEAR_LENGTH);
            loopState = true;
        } else {
            for (int i = 0; i < 4; i++){
                if (isdigit(year[i]) == 0){
                    cout << "Invalid numerical value" << endl;
                    memset(year, '\0', YEAR_LENGTH);
                    loopState = true;
                    break;
                } 
            }
        }
    } while (loopState);
}

void getSpecial(char special[]){
    cout << "Enter a special character, characters after the first will be ignored: ";
    cin.getline(special, SPECIAL_CHARACTER, '\n');
    // cin.ignore();
    cout << strlen(special) << endl;
    cout << special << endl;
}