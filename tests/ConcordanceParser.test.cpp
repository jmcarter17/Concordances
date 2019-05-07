#include "catch2/catch.hpp"
#include "ConcordanceParser.h"
#include <sstream>
#include <fstream>


TEST_CASE("Simple Sentences") {
  CHECK(ConcordanceParser{std::istringstream{""}}.getConcordance() == "");
  CHECK(ConcordanceParser{"Hello."}.getConcordance() == "hello\t{1:1}\n");
  CHECK(ConcordanceParser{"Hello, hello."}.getConcordance() == "hello\t{2:1,1}\n");
  CHECK(ConcordanceParser{"Hello, Joe."}.getConcordance() == "hello\t{1:1}\njoe\t{1:1}\n");
}

TEST_CASE("Multiple Sentences") {
  CHECK(ConcordanceParser{std::istringstream{".\n.\n.\n.\n."}}.getConcordance() == "");
  CHECK(ConcordanceParser{"Hello.\nHello, hello."}.getConcordance() == "hello\t{3:1,2,2}\n");
  CHECK(ConcordanceParser{"Hello.\nHello, Joe."}.getConcordance() == "hello\t{2:1,2}\njoe\t{1:2}\n");
  CHECK(ConcordanceParser{"Hello.\nHello.\n Hello, Joe."}.getConcordance() == "hello\t{3:1,2,3}\njoe\t{1:3}\n");
}

TEST_CASE("From File") {
  std::ifstream file("../../files/smallPoem.txt", std::ios::in);
  CHECK(ConcordanceParser{std::move(file)}.getConcordance() == "and\t{1:4}\n"
                                                               "are\t{3:1,2,4}\n"
                                                               "blue\t{1:2}\n"
                                                               "heart\t{1:3}\n"
                                                               "is\t{1:3}\n"
                                                               "my\t{1:3}\n"
                                                               "red\t{2:1,3}\n"
                                                               "roses\t{1:1}\n"
                                                               "so\t{1:4}\n"
                                                               "violets\t{1:2}\n"
                                                               "you\t{1:4}\n");
}