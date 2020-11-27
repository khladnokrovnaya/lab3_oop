#include "remove.h"

Remove::Remove(const std::string& text_, size_t position_) : BaseOperation (text_, position_) { }

void Remove::doOperation(std::string &text_) const {
    text_.erase(pos, text.size());
}

void Remove::undoOperation(std::string &text_) const {
    text_.insert(pos, text);
}
