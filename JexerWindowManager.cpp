////
//// Author : DX, 2018/6/26
////
//
//#include "JexerWindowManager.h"
//
//namespace Jexer
//{
//
//	WindowManager* WindowManager::m_sgWndMgr = 0;
//
//	WindowManager::WindowManager()
//	{
//		m_sgWndFty = WindowFactory::New();
//	}
//
//	WindowManager::~WindowManager()
//	{
//		
//	}
//
//	WindowManager* WindowManager::New()
//	{
//		if (!m_sgWndMgr)
//		{
//			m_sgWndMgr = new WindowManager();
//		}
//
//		return m_sgWndMgr;
//	}
//
//	void WindowManager::Delete()
//	{
//		DELETE_ROW_POINTER(m_sgWndMgr);
//	}
//
//	void WindowManager::ParseWindowConfiger(const Configer& configer)
//	{
//		
//	}
//
//	void WindowManager::KeepRenderLoop(RenderManager& renderMgr)
//	{
//		// Loop until the window is closed
//		while (!glfwWindowShouldClose(m_curWnd.GetHandle()))
//		{
//			// RenderManager begins rendering here
//
//			// Swap front and back buffers
//			glfwSwapBuffers(m_curWnd.GetHandle());
//
//			// Poll for and process events
//			glfwPollEvents();
//		}
//	}
//
//} // namespace Jexer