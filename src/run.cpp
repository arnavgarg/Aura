#include <iostream>
#include <fstream>
#include <sstream>

#include <lexer/lexer.hpp>

int main(int argc, char* argv[]) {
    Lexer lexer;
    if (argc == 1) {
        std::system("clear");
        std::cout << "Aura Interactive Lexer 0.0.1 DEV BUILD" << std::endl;
        while (true) {
            std::string input;
            std::cout << "> ";
            getline(std::cin, input);

            std::vector<Token> tokens = lexer.tokenize(input);
            for (Token token : tokens) {
                std::cout << token.toString() << std::endl;
            }
            std::cout << std::endl;
        }
    } else if (argc == 2) {
        std::string filename(argv[1]);
        if (filename.length() <= 5 || filename.substr(filename.length()-5, 5) != ".aura") {
            std::cout << "Error: Invalid File\nAll files must have .aura extension" << std::endl;
            return 1;
        }
        std::string outfile = filename.substr(0, filename.length()-5) + ".aout";

        std::ifstream fin(filename);
        std::ofstream fout(outfile);
        std::stringstream buffer;
        buffer << fin.rdbuf();

        std::vector<Token> tokens = lexer.tokenize(buffer.str());
        for (Token token : tokens) {
            fout << token.toString() << std::endl;
        }
        std::cout << "tokenized output can be found in " <<  outfile << std::endl;
    } else {
        std::cout << "ERROR: Usage\n";
        std::cout << "./aura\n";
        std::cout << "./aura file.aura\n";
    }
}
