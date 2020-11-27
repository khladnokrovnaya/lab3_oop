#ifndef BASEOPERATION_H
#define BASEOPERATION_H
#pragma once
#include "itextoperation.h"

class BaseOperation : public ITextOperation
{
public:
    BaseOperation();
    BaseOperation(const std::string& text, size_t pos);

protected:
    std::string text;
    size_t pos{0};

};

#endif // BASEOPERATION_H
