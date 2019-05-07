//
// Created by Jean-Michel Carter on 2019-05-06.
//

#include "ConcordanceParser.h"
#include <sstream>
#include <algorithm>

ConcordanceParser::ConcordanceParser(std::istream&& input) {
  int lineNumber{0};
  std::string line;
  while (std::getline(input, line)) {
    parseLine(++lineNumber, line);
  }
}

ConcordanceParser::ConcordanceParser(const std::string& input) : ConcordanceParser(std::istringstream{input}) {}


std::string ConcordanceParser::getConcordance() const {
  std::stringstream result{};

  for (const auto& data : concordanceMap) {
    result << data.first << "\t{" << data.second.size() << ":";

    result << *data.second.begin();
    for (auto it = std::next(data.second.begin()); it != data.second.end(); ++it) {
      result << "," << *it;
    }
    result << "}\n";
  }

  return result.str();
}

void ConcordanceParser::parseLine(int lineNumber, const std::string& line) {
  std::istringstream iss{line};
  std::string word;
  while (iss >> word) {
    removePunctuation(word);
    if (!word.empty()) {
      tolowercase(word);

      concordanceMap[word].push_back(lineNumber);
    }
  }
}
void ConcordanceParser::tolowercase(std::string &word) const {
  std::transform(word.begin(), word.end(), word.begin(), ::tolower);
}
void ConcordanceParser::removePunctuation(std::string & word) const {
  word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
}