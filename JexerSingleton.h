//
// Author : DX, 2018/9/10
//

#pragma once

#ifndef JEXER_SINGLETON_H
#define JEXER_SINGLETON_H

namespace Jexer
{
	/**
		������ģ���࣬���е����඼��Ҫ�̳и���
	*/
	template<typename T>
	class JexerSingleton
	{
	private:

		// ��������ÿ������캯���͸�ֵ�����

		JexerSingleton(const JexerSingleton<T>&);

		JexerSingleton operator=(const JexerSingleton<T>&);

	protected:

		static T* ms_singleton;

	public:

		JexerSingleton()
		{
			ms_singleton = static_cast<T*>(this);
		}

		~JexerSingleton()
		{
			ms_singleton = 0;
		}

		T GetSingleton()
		{
			return *ms_singleton;
		}

		T* GetSingletonPtr()
		{
			return ms_singleton;
		}

	};


}

#endif // JEXER_SINGLETON_H