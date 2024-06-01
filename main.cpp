#include "CLI.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    // Instantiate CLI class
    CLI& cli = CLI::getInstance();

    // Display welcome message, introduction, and menu
    cli.welcome();
    cli.intro();
    cli.menu();

    // Main loop to handle user input
    bool running = true;

    while (running){
        // Get user input
        cout << "Enter a command ('quit' to exit // 'help' for menu): ";
        string input;
        getline(cin, input);

        // Check input and perform corresponding actions
        if (input == "quit"){
            running = false;
        }
        else if (input == "help"){
            cli.menu();
        }
        else{
            // If the user enters command other than 'help' or 'quit', parse and execute it
            vector<string> inputParsed = cli.parse(input);
            cli.execute(inputParsed);
        }
    }

}