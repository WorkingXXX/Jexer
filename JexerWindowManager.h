////
//// Author : DX, 2018/6/26
////
//
//#ifndef WINDOW_MANAGER_H
//#define WINDOW_MANAGER_H
//
//#include <vector>
//
//#include "JexerWindowFactory.h"
//#include "JexerRenderManager.h"
//#include "JexerConfiger.h"
//#include "JexerMacro.h"
//
//namespace Jexer
//{
//	
//	class JexerWindowManager
//	{
//	public:
//		
//		static JexerWindowManager* New();
//
//		// WindowManager creates windows from settings got by
//		// parsing window configers
//
//		void Delete();
//
//		void ParseWindowConfiger(const Configer& configer);
//
//		void KeepRenderLoop(RenderManager& renderMgr);
//
//		WindowFactory* GetWindowFactory() const
//		{
//			return m_sgWndFty;
//		}
//
//		Window GetCurrentWindow()
//		{
//			return m_curWnd;
//		}
//
//	protected:
//
//		JexerWindowManager();
//
//		~JexerWindowManager();
//
//	private:
//		static WindowManager* m_sgWndMgr;
//		WindowFactory* m_sgWndFty;
//		std::vector<Window> m_wnds;
//		Window m_curWnd;
//	};
//
//
//} // namespace Jexer
//
//#endif // WINDOW_MANAGER_H