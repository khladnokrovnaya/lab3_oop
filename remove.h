#ifndef REMOVE_H
#define REMOVE_H
#include "baseoperation.h"

class Remove : public BaseOperation {
public:
    Remove(const std::string& text_, size_t position_);
    void doOperation(std::string& text_) const override;
    void undoOperation(std::string& text_) const override;
};

#endif // REMOVE_H
