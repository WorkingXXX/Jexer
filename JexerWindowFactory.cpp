////
//// Author : DX, 2018/6/25
////
//
//#include "WindowFactory.h"
//
//namespace Jexer
//{
//	WindowFactory* WindowFactory::m_sgWndFty = 0;
//
//	WindowFactory::WindowFactory()
//	{
//		m_initState = static_cast<bool>(glfwInit());
//	}
//
//	WindowFactory::~WindowFactory()
//	{
//
//	}
//
//	WindowFactory* WindowFactory::New()
//	{
//		if (!m_sgWndFty)
//		{
//			m_sgWndFty = new WindowFactory();
//		}
//
//		return m_sgWndFty;
//	}
//
//	void WindowFactory::Delete()
//	{
//		DELETE_ROW_POINTER(m_sgWndFty);
//	}
//	
//	bool WindowFactory::CreateWindow(int w, int h, std::string title)
//	{
//		Window window(w, h, title);
//
//		if (window.IsCreated())
//		{
//			// Create the window's OpenGL context
//			glfwMakeContextCurrent(window.GetHandle());
//			
//			return true;
//		}
//
//		return false;
//	}
//
//} // namespace Jexer