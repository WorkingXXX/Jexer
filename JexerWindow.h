//
// Author : DX, 2018/6/25
//

#ifndef WINDOW_H
#define WINDOW_H

#include "JexerResource.h"
#include "JexerMath.h"
#include "JexerPrerequisites.h"

#include <GLFW\glfw3.h>
#include <string>
#include <memory>


namespace Jexer
{

	typedef GLFWwindow* WinPtr;

	class JexerWindow : JexerResource
	{
	public:

		JexerWindow(int w = 0, int h = 0, std::string title = "");

		~JexerWindow();

		/**
			����λ�û�ȡ�����ú���
		*/

		int GetPosX() const;
		void SetPosX(int x);
		int GetPosY() const;
		void SetPosY(int y);
		VtrInt2 GetPos() const;
		void SetPos(VtrInt2 pos);

		/**
			���ڴ�С��ȡ�����ú���
		*/

		int GetWidth() const;
		void SetWidth(int width);
		int GetHeight() const;
		void SetHeight(int height);
		VtrInt2 GetSize() const;
		void SetSize(VtrInt2 size);

		/**
			���ڱ����ȡ�����ú���
		*/

		STLStr GetTitle() const;
		void SetTitle(const STLStr& title);

		// �жϴ����Ƿ��Ѿ�����
		bool IsCreated() const
		{
			return m_winptr != 0;
		}

		// ��ȡ���ھ��
		WinPtr GetHandle()
		{
			return m_winptr;
		}

		// ���ٴ���
		void DestroyWindow();

	protected:

	private:
		STLStr m_title;
		WinPtr m_winptr;
	};


} // namespace Jexer

#endif // WINDOW_H