#ifndef DOCUMENTLOADER_H
#define DOCUMENTLOADER_H

#include <vector>
#include <string>
#include "Document.h"

class DocumentLoader {
public:
    std::vector<Document> loadDocuments(const std::string& folderPath);
};

#endif