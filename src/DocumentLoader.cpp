#include "../include/DocumentLoader.h"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

vector<Document> DocumentLoader::loadDocuments(const string& folderPath)
{
    vector<Document> documents;

    int documentId = 1;

    try
    {
        for (const auto& entry : fs::directory_iterator(folderPath))
        {
            if (!entry.is_regular_file())
            {
                continue;
            }

            if (entry.path().extension() != ".txt")
            {
                continue;
            }

            ifstream inputFile(entry.path());

            if (!inputFile.is_open())
            {
                cerr << "Failed to open file: "
                     << entry.path()
                     << endl;

                continue;
            }

            stringstream buffer;
            buffer << inputFile.rdbuf();

            Document doc;

            doc.id = documentId++;
            doc.filename = entry.path().filename().string();
            doc.content = buffer.str();

            documents.push_back(doc);

            inputFile.close();
        }
    }
    catch (const exception& e)
    {
        cerr << "Error loading documents: "
             << e.what()
             << endl;
    }

    return documents;
}