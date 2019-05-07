//
// Created by Jean-Michel Carter on 2019-05-06.
//

#ifndef CONCORDANCES_CONCORDANCEPARSER_H
#define CONCORDANCES_CONCORDANCEPARSER_H

#include <string>
#include <map>
#include <vector>

class ConcordanceParser {
public:
  explicit ConcordanceParser(std::istream&& input);
  explicit ConcordanceParser(const std::string& input);


  std::string getConcordance() const;

private:

  std::map<std::string, std::vector<int>> concordanceMap; // [word, lineOccurances]

  void parseLine(int lineNumber, const std::string& line);
  void removePunctuation(std::string & word) const;
  void tolowercase(std::string &word) const;
};

#endif // CONCORDANCES_CONCORDANCEPARSER_H
