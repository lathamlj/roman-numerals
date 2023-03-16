#include <iostream>
#include <unordered_map>

using namespace std;

int rom_to_dec(string rn) { //this function converts roman numerals to decimals numbers

    unordered_map<char, int> rnMap = // creating map of the roman numeral symbols and their values
            {{'I', 1},
             {'V', 5},
             {'X', 10},
             {'L', 50},
             {'C', 100},
             {'D', 500},
             {'M', 1000}};

    int decValue = 0;

    for(int i=0;i<rn.size();i++){
        if(rn.size()==1){ //if an input is just a single character long, add the value to decValue and return
            decValue += rnMap[rn[i]];
            break;
        }
        if(rnMap[rn[i]] > rnMap[rn[i-1]]){
            decValue += rnMap[rn[i]] - (2*rnMap[rn[i-1]]); //figuring out the logic here was probably the most
            // difficult and time-consuming part of this challenge for me.
        }else {
            decValue += rnMap[rn[i]]; //first attempt with this line resulted in infinite loop. I fixed the infinite
            // loop when I realized I was decrementing i on accident. This was happening at the ends of lines 25 and 26
            // I had rnMap[rn[i--]] instead of rnMap[rn[i-1]]
        }
    }
    return decValue;
}

string dec_to_rom(int decimal){ //this function converts decimals to roman numerals. Please see commented out
    // note below in this function

    string romNum = "";

    while(decimal-1000 >= 0){
        decimal = decimal - 1000;
        romNum += "M";
    }
    while(decimal-500 >= 0){
        decimal = decimal - 500;
        romNum += "D";
    }
    while(decimal-100 >= 0){
        decimal = decimal - 100;
        romNum += "C";
    }
    while(decimal-50 >= 0){
        decimal = decimal - 50;
        romNum += "L";
    }
    while(decimal-10 >= 0){
        decimal = decimal - 10;
        romNum += "X";
    }
    while(decimal-5 >= 0){
        decimal = decimal - 5;
        romNum += "V";
    }
    while(decimal-1 >= 0){
        decimal = decimal - 1;
        romNum += "I";
    }
    /*
    if(romNum)
     I have run out of time here; however, if I had more time I would figure out how to read the string that is romNum
     and substitute certain combinations of characters with other characters. An example of this would be if
     romNum has "IIII" it would swap that for "IV". If you were to cin the decimal number of 99, my code produces
     "LXXXXVIIII", which is obviously incorrect. While I believe the direction I was going would work eventually,
     I recognize that this is probably not the most effecient way to convert number values to roman numerals.
     If I had all day, I think I would be able to think of another way to do it.
     */
    return romNum;
}

int main() {
    string rn;
    cout << "Enter a valid roman numeral: "; //if I had more time I would create conditions to avoid invalid inputs
    cin >> rn;
    cout << rom_to_dec(rn) << endl;
    int decimal;
    cout << "Enter a valid whole number: ";
    cin >> decimal;
    cout << dec_to_rom(decimal);
    return 0;
}
