#include "insert.h"

Insert::Insert(const std::string& text_, size_t position_)
    : BaseOperation(text_, position_) { }

void Insert::doOperation(std::string &text_) const {
    text_.insert(pos, text);
}

void Insert::undoOperation(std::string &text_) const {
    text_.erase(pos, text.size());
}
