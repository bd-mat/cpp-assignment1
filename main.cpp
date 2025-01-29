// PHYS30762 Assignment 1
// Want to calculate energy for a given bohr transition
// User specifies Z, n_init, n_fin
// User specifies result in eV or J

#include<iostream>
#include<cmath>

int verify_int(){
    int input;
    // get initial input
    std::cin >> input;
    // now verify for pos.int
    while(std::cin.fail() || input<=0){
        std::cerr << "Error. Please enter a positive integer: ";
        // clear error flag
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> input;
    }
    return input;
}

float findval(int Z, int n_i, int n_f){
    // returns value in eV
    float temp;
    temp = 13.6 * std::pow(Z,2);
    temp = temp * (1/pow(n_f,2) - 1/pow(n_i,2));
    return temp;
}

bool checkeV(){
    char temp;
    // send prompts
    std::cout << "Enter 'e' for results in eV, and 'J' for results in Joules: ";
    std::cin >> temp;
    // verify
     while(true){
        while(std::cin.fail()){
            std::cerr << "Error. Please try again: ";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> temp;
        }
        // check for ev
        if(temp == 'J'){
            return true;
        }
        // check for joules
        else if (temp == 'e'){
            return false;
        }
        // obviously neither, so please requery
        std::cerr << "Error. Please try again: ";
        std::cin.ignore(256,'\n');
        std::cin >> temp;
    }
}

bool query(){
    std::cout << "Would you like to repeat the program?\n";
    // send prompts
    std::cout << "Enter 'y' for yes, and 'n' for no: ";
    // declare input
    char temp;
    // receive input
    std::cin >> temp;
    // check for invalid input, and re-query if so
    while(true){
        while(std::cin.fail()){
            std::cerr << "Error. Please try again: ";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> temp;
        }
        // check for yes
        if(temp == 'y'){
            return true;
        }
        // check for no
        else if (temp == 'n'){
            return false;
        }
        // obviously neither, so please requery
        std::cerr << "Error. Please try again: ";
        std::cin.ignore(256,'\n');
        std::cin >> temp;
    }
}

int main(){
    // Declare variables
    int n_init;
    int n_fin;
    int Z;
    float result;
    bool unit;
    bool repeat{true};
    while(repeat){
        // Print welcome message
        std::cout << "Welcome to Bohr Calculator v1.0 \n";
        // Find Z
        std::cout << "Please specify an atomic number: ";
        Z = verify_int();
        // find n_init
        std::cout << "Please specify an initial n: ";
        n_init = verify_int();
        // find n_fin
        std::cout << "Please specify a final n: ";
        n_fin = verify_int();
        // find bare result
        result = findval(Z,n_init,n_fin);
        // convert as necessary
        unit = checkeV();
        if(unit){
            result = result*(1.6e-19);
        }
        // print result in desired unit
        std::cout << result << std::endl;
        // check for repeat
        repeat = query();
    }
    // end program
    return 0;
}
