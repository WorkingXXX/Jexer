////
//// Author : DX, 2018/6/26
////
//
//#ifndef WINDOW_FACTORY_H
//#define WINDOW_FACTORY_H
//
//#include <vector>
//
//#include "JexerWindow.h"
//#include <Common\JexerMacro.h>
//
//namespace Jexer
//{
//	class WindowFactory
//	{
//	public:
//
//		static WindowFactory* New();
//
//		void Delete();
//
//		bool CreateWindow(int w, int h, std::string title = "");
//
//		bool IsWindowEnvInited() const
//		{
//			return m_initState;
//		}
//
//	protected:
//
//		WindowFactory();
//
//		~WindowFactory();
//
//	private:
//		static WindowFactory* m_sgWndFty;
//		bool m_initState;
//	};
//
//} // namespace Jexer
//
//#endif // WINDOW_FACTORY_H
