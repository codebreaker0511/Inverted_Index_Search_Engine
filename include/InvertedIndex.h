#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <unordered_map>
#include <vector>
#include <string>

#include "Document.h"

class InvertedIndex
{
private:

    std::unordered_map<
        std::string,
        std::unordered_map<int, int>
    > index;

    std::unordered_map<std::string, int> documentFrequency;

    int totalDocuments = 0;

public:

    void buildIndex(
        const std::vector<Document>& documents
    );

    const std::unordered_map<
        std::string,
        std::unordered_map<int, int>
    >& getIndex() const;

    const std::unordered_map<
        std::string,
        int
    >& getDocumentFrequency() const;

    int getTotalDocuments() const;
};

#endif