#include <string>

#include "gtest/gtest.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::string filter = "";
    if (argc != 1) {
        for (int i = 1; i < argc; i++) {
            if (std::string(argv[i]) == "lexer") {
                filter += "LexerTest.*";
            }
        }
        ::testing::GTEST_FLAG(filter) = filter;
    }
    
    return RUN_ALL_TESTS();
}
