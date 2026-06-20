#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <vector>
#include <string>
#include <unordered_map>

#include "Document.h"
#include "InvertedIndex.h"

class SearchEngine
{
private:

    std::unordered_map<int, Document> documents;

public:

    SearchEngine(
        const std::vector<Document>& docs
    );

    std::vector<
        std::pair<Document, double>
    > search(
        const std::string& query,
        const InvertedIndex& index
    );
};

#endif