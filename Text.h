#pragma once
#include <string>
#include <iostream>
#include "Stack.h"
#include "itextoperation.h"

class Text {
public:
    Text() = default;
    Text(const std::string &newtext);
    ~Text() = default;

    void remove(size_t position_, size_t length_);
    void insert(const std::string& text_, size_t position_);
    void replace(const std::string& new_, size_t position_, size_t length_);
    void undo();
    void redo();
    void save(const std::string &filename);
    void load(const std::string &filename);
    const std::string& GetText() const;

private:
    std::string text;
    Stack <ITextOperation> undoStack;
    Stack <ITextOperation> redoStack;
    void applyOperation(ITextOperation* operation_);
};

