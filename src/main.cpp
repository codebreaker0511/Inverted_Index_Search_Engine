#include "../include/DocumentLoader.h"
#include "../include/InvertedIndex.h"
#include "../include/SearchEngine.h"

#include <iostream>

using namespace std;

int main()
{
    string folderPath;

    cout << "Enter folder path: ";
    getline(cin, folderPath);

    DocumentLoader loader;

    vector<Document> documents =
        loader.loadDocuments(folderPath);

    InvertedIndex index;

    index.buildIndex(documents);

    SearchEngine engine(documents);

    cout << "\nIndexed "
         << documents.size()
         << " documents.\n";

    while(true)
    {
        string query;

        cout << "\nSearch > ";

        getline(cin, query);

        if(query == "exit")
        {
            break;
        }

        auto results =
            engine.search(
                query,
                index
            );

        if(results.empty())
        {
            cout << "No results found.\n";
            continue;
        }

        cout << "\nResults:\n\n";

        for(const auto& result :
            results)
        {
            cout
                << result.first.filename
                << " | Score: "
                << result.second
                << endl;
        }
    }

    return 0;
}