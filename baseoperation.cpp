#include "baseoperation.h"

BaseOperation::BaseOperation()
{
   text = "";
   pos = 0;
}

BaseOperation::BaseOperation(const std::string& text_, size_t position_)
{
  text = text_;
  pos = position_;
}
