#include "../include/SearchEngine.h"
#include "../include/Tokenizer.h"

#include <algorithm>
#include <cmath>

using namespace std;

SearchEngine::SearchEngine(
    const vector<Document>& docs
)
{
    for(const auto& doc : docs)
    {
        documents[doc.id] = doc;
    }
}

vector<pair<Document,double>>
SearchEngine::search(
    const string& query,
    const InvertedIndex& invertedIndex
)
{
    Tokenizer tokenizer;

    vector<string> queryWords =
        tokenizer.tokenize(query);

    unordered_map<int,double> scores;

    const auto& index =
        invertedIndex.getIndex();

    const auto& documentFrequency =
        invertedIndex.getDocumentFrequency();

    int totalDocuments =
        invertedIndex.getTotalDocuments();

    for(const string& word : queryWords)
    {
        auto indexIt = index.find(word);

        if(indexIt == index.end())
        {
            continue;
        }

        int df =
            documentFrequency.at(word);

        double idf =
            log(
                1.0 +
                (double)totalDocuments / df
            );

        for(const auto& posting :
            indexIt->second)
        {
            int docId = posting.first;
            int tf = posting.second;

            scores[docId]
                += tf * idf;
        }
    }

    vector<pair<Document,double>> results;

    for(const auto& score : scores)
    {
        results.push_back(
            {
                documents[score.first],
                score.second
            }
        );
    }

    sort(
        results.begin(),
        results.end(),
        [](const auto& a,
           const auto& b)
        {
            return a.second > b.second;
        }
    );

    return results;
}