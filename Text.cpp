#pragma once
#include "Text.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "remove.h"
#include "replace.h"
#include "insert.h"


Text::Text(const std::string &newtext) :
    text(newtext)
{}


void Text::save(const std::string &filename) {
    try{
        std::ofstream file(filename);
        file << text << '\n';
    } catch (std::exception& e) {
        std::cout << e.what();
    }
}

void Text::remove(size_t position_, size_t length_) {
    if ((position_ + length_ > text.size()) || (length_ == 0)) {
        std::cerr << "Invalid remove\n";
        return;
    }
    redoStack.clear();
    Remove* o = new Remove(text.substr(position_, length_), position_);
    applyOperation(o);
}

void Text::insert(const std::string &text_, size_t position_) {
    if ((position_ > text.size()) || text_.empty()) {
        std::cerr << "Invalid insert\n";
        return;
    }
    redoStack.clear();
    Insert* o = new Insert (text_, position_);
    applyOperation(o);
}

void Text::replace(const std::string &new_, size_t position_, size_t length_) {
    if ((position_ + length_ > text.size()) || new_.empty()) {
        std::cerr << "Invalid replace\n";
        return;
    }
    redoStack.clear();
    Replace *o = new Replace(text.substr(position_, length_), new_, position_);
    applyOperation(o);
}

void Text::undo() {
    if (undoStack.empty()) {
        std::cerr << "Unable to undo\n";
        return;
    }
    auto o = undoStack.Top()-> value;
    undoStack.Pop();
    o ->undoOperation(text);
    redoStack.Push(o);
}

void Text::redo() {
    if (redoStack.empty()) {
        std::cerr << "Unable to redo\n";
        return;
    }
    auto o = redoStack.Top()->value;
    redoStack.Pop();
    o->doOperation(text);
    undoStack.Push(o);
}


void Text::applyOperation(ITextOperation* operation_) {
    operation_->doOperation(text);
    undoStack.Push(operation_);
}

const std::string& Text::GetText() const
{
    return text;
}
