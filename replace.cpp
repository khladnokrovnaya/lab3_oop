#include "replace.h"


Replace::Replace(const std::string& old_,const std::string& new_, size_t pos_) : BaseOperation (old_, pos_) {
    newText = new_;
}

void Replace::doOperation(std::string &text_) const {
    text_.erase(pos, text.size());
    text_.insert(pos, newText);
}

void Replace::undoOperation(std::string &text_) const {
    text_.erase(pos, newText.size());
    text_.insert(pos, text);
}
