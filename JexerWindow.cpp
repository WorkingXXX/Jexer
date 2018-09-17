//
// Author : DX, 2018/6/25
//

#include "JexerWindow.h"

namespace Jexer
{

	JexerWindow::JexerWindow(int w, int h, std::string title)
		:m_winptr(0)
	{
		if (!(m_winptr = glfwCreateWindow(w, h, title.c_str(), 0, 0)))
		{
			printf("Failed to Create Window\n");
		}
	}

	JexerWindow::~JexerWindow()
	{
		DestroyWindow();
	}

	int JexerWindow::GetPosX() const
	{
		int x, y;
		glfwGetWindowPos(m_winptr, &x, &y);
		return x;
	}

	void JexerWindow::SetPosX(int x)
	{
		const int y = GetPosY();
		glfwSetWindowPos(m_winptr, x, y);
	}

	int JexerWindow::GetPosY() const
	{
		int y, x;
		glfwGetWindowPos(m_winptr, &x, &y);
		return y;
	}

	void JexerWindow::SetPosY(int y)
	{
		const int x = GetPosX();
		glfwSetWindowPos(m_winptr, x, y);
	}

	VtrInt2 JexerWindow::GetPos() const
	{
		VtrInt2 pos(0, 0);
		glfwGetWindowPos(m_winptr, &(pos.x), &(pos.y));
		return pos;
	}

	void JexerWindow::SetPos(VtrInt2 pos)
	{
		glfwSetWindowPos(m_winptr, pos.x, pos.y);
	}

	int JexerWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(m_winptr, &width, &height);
		return width;
	}

	void JexerWindow::SetWidth(int width)
	{
		const int height = GetHeight();
		glfwSetWindowSize(m_winptr, width, height);
	}

	int JexerWindow::GetHeight() const
	{
		int height, width;
		glfwGetWindowSize(m_winptr, &width, &height);
		return height;
	}

	void JexerWindow::SetHeight(int height)
	{
		const int width = GetWidth();
		glfwSetWindowSize(m_winptr, width, height);
	}

	VtrInt2 JexerWindow::GetSize() const
	{
		VtrInt2 size(0, 0);
		glfwGetWindowSize(m_winptr, &(size.x), &(size.y));
		return size;
	}

	void JexerWindow::SetSize(VtrInt2 size)
	{
		glfwSetWindowSize(m_winptr, size.x, size.y);
	}

	STLStr JexerWindow::GetTitle() const
	{
		return m_title;
	}

	void JexerWindow::SetTitle(const STLStr& title)
	{
		m_title = title;
		glfwSetWindowTitle(m_winptr, m_title.c_str());
	}

	void JexerWindow::DestroyWindow()
	{
		if (m_winptr)
		{
			glfwDestroyWindow(m_winptr);
			m_winptr = 0;
		}
	}


} // namespace Jexer