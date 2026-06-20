#include "../include/InvertedIndex.h"
#include "../include/Tokenizer.h"

#include <unordered_set>

using namespace std;

void InvertedIndex::buildIndex(
    const vector<Document>& documents
)
{
    totalDocuments = documents.size();

    Tokenizer tokenizer;

    for(const auto& document : documents)
    {
        vector<string> words =
            tokenizer.tokenize(document.content);

        unordered_set<string> uniqueWords;

        for(const string& word : words)
        {
            index[word][document.id]++;
            uniqueWords.insert(word);
        }

        for(const string& word : uniqueWords)
        {
            documentFrequency[word]++;
        }
    }
}

const unordered_map<
    string,
    unordered_map<int,int>
>& InvertedIndex::getIndex() const
{
    return index;
}

const unordered_map<
    string,
    int
>& InvertedIndex::getDocumentFrequency() const
{
    return documentFrequency;
}

int InvertedIndex::getTotalDocuments() const
{
    return totalDocuments;
}