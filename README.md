# Aura
A Simple Programming Language

As of now, only the Aura Lexer is functional. More features are coming soon!

Build Instructions: 
1. fork and clone repo 
3. `cd` into repo 
2. `mkdir build`
3. `cd build`
4. `cmake ..`
5. `make`

Run options: 
* `./aura`: opens up the Aura Interactive Lexer 
* `./aura <.aura file>`: runs Aura Lexer on Aura code

Testing:
* `ctest` or `make test`: run all tests with simplified output
* `./test/tests`: run all tests with verbose output
* `./test/tests <options>`: run specific tests with verbose output

Options avaiable: `lexer`

Note: run and test operations should be done from the `Aura/build` directory
