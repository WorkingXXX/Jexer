//
// Author : DX, 2018/6/28
//

#ifndef JEXER_MACRO_H
#define JEXER_MACRO_H

namespace Jexer
{

// Macro of the code snippt to delete a row pointer
#define DELETE_ROW_POINTER(ptr)\
if(ptr)\
{\
	delete ptr;\
	ptr = 0;\
}


} // namespace Jexer


#endif // JEXER_MACRO_H