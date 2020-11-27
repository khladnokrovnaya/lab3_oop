#ifndef INSERT_H
#define INSERT_H
#include "baseoperation.h"


class Insert : public BaseOperation {
public:
    Insert(const std::string& text_, size_t position_);
    void doOperation(std::string& text_) const override;
    void undoOperation(std::string& text_) const override;
};

#endif // INSERT_H
