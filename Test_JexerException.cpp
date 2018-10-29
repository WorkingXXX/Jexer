

#include <iostream>

#include "JexerPrerequisites.h"
#include "JexerException.h"

using namespace std;
using namespace Jexer;

void TestFoo1()
{
	JEXER_THROW_EXCEPTION(JexerException<int>().AddErrorInfo(2).AddErrorInfo(5));
}

void TestFoo2()
{
	JEXER_THROW_EXCEPTION(JexerException<STLStr>().AddErrorInfo("asd"));
}

int main()
{
	try
	{
		TestFoo2();
	}
	catch (const JexerExceptionBase & e)
	{
		e.PrintErrorInfo();
	}
	system("pause");
}

