# Inverted Index Search Engine

A C++ search engine that performs efficient document retrieval using an inverted index and TF-IDF based ranking. The system preprocesses a collection of text documents, builds an index mapping terms to documents, and supports ranked keyword search through an interactive command-line interface.

## Features

* Document ingestion from a user-specified directory
* Text preprocessing and tokenization
* Inverted index construction.
* TF-IDF based document ranking
* Interactive query processing
* Case-insensitive search
* Frequency-aware relevance scoring
* Modular and extensible architecture

## Architecture

```text
Documents
    ↓
Document Loader
    ↓
Tokenizer
    ↓
Inverted Index
    ↓
TF-IDF Ranking Engine
    ↓
Search Results
```

### Core Components

#### DocumentLoader

Loads text documents from a directory and stores them in memory as structured document objects.

#### Tokenizer

Processes raw text by:

* Converting text to lowercase
* Removing punctuation and special characters
* Splitting text into searchable tokens

#### InvertedIndex

Builds and maintains the primary search data structure:

```text
Word
  →
(Document ID, Frequency)
```

Example:

```text
competitive → (Doc1, 2), (Doc3, 1)
programming → (Doc1, 3)
```

#### SearchEngine

Processes user queries, retrieves candidate documents from the inverted index, computes TF-IDF relevance scores, and returns ranked results.

## Data Structures

### Document Representation

```cpp
struct Document {
    int id;
    std::string filename;
    std::string content;
};
```

### Inverted Index

```cpp
std::unordered_map<
    std::string,
    std::unordered_map<int, int>
>
```

Stores term frequencies for every document containing a given word.

## Ranking Method

Documents are ranked using TF-IDF (Term Frequency–Inverse Document Frequency).

### Term Frequency (TF)

Measures how frequently a term appears within a document.

### Inverse Document Frequency (IDF)

Measures how informative a term is across the document collection.

```text
IDF = log(1 + N / DF)
```

Where:

* N = total number of documents
* DF = number of documents containing the term

### Final Score

```text
Score = Σ (TF × IDF)
```

Documents with higher scores are ranked above less relevant documents.

## Project Structure

```text
Inverted-Index-Search-Engine/
│
├── include/
│   ├── Document.h
│   ├── DocumentLoader.h
│   ├── InvertedIndex.h
│   ├── SearchEngine.h
│   └── Tokenizer.h
│
├── src/
│   ├── DocumentLoader.cpp
│   ├── InvertedIndex.cpp
│   ├── SearchEngine.cpp
│   ├── Tokenizer.cpp
│   └── main.cpp
│
├── data/
├── tests/
└── README.md
```

## How to Run

### 1. Compile

```bash
g++ -std=c++17 src/main.cpp src/DocumentLoader.cpp src/Tokenizer.cpp src/InvertedIndex.cpp src/SearchEngine.cpp -o search_engine
```

### 2. Run the Executable

```bash
./search_engine
```

### 3. Enter Document Directory

Example:

```text
Enter folder path: data
```

The engine will load and index all `.txt` files present in the specified directory.

### 4. Search

Example:

```text
Search > competitive programming
```

### Sample Output

```text
Results:

cp.txt | Score: 3.42
notes.txt | Score: 1.87
```

### Exit

```text
Search > exit
```

## Example Query

Query:

```text
competitive programming
```

Output:

```text
cp.txt | Score: 3.42
notes.txt | Score: 1.87
```
