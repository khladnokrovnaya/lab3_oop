#ifndef REPLACE_H
#define REPLACE_H
#include "baseoperation.h"

class Replace : public BaseOperation {
public:
    Replace(const std::string& old_, const std::string& new_, size_t pos_);
    void doOperation(std::string& text_) const override;
    void undoOperation(std::string& text_) const override;

private:
    std::string newText;
};

#endif // REPLACE_H
