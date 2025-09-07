#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  Corpus ret;
  auto its = find_all(source.begin(), source.end(), isspace);
    std::transform(
        its.begin(), its.end() - 1,
        its.begin() + 1,
        std::inserter(ret, ret.end()),
        [&](auto it1, auto it2) {
            return Token(source, it1, it2);
        });
    std::erase_if(ret, [](const Token& t)
                  { return t.content.empty(); });
  return ret;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    namespace rv = std::ranges::views;

    auto result_view = source
        | rv::filter([&](const Token& t) {
            return !dictionary.contains(t.content);
        })
        | rv::transform([&](const Token& token) {
            auto suggestion_view = dictionary
                | rv::filter([&](const std::string& word) {
                    return levenshtein(token.content, word) == 1;
                });

            std::set<std::string> suggestions(suggestion_view.begin(), suggestion_view.end());
            return Misspelling{token, suggestions};
        })
        | rv::filter([](const Misspelling& m) {
            return !m.suggestions.empty();
        });

    return std::set<Misspelling>(result_view.begin(), result_view.end());
}
/* Helper methods */

#include "utils.cpp"