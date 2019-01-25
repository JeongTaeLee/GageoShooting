#pragma once

template <class T>
class singleton
{
private:
	static T * instance;

public:
	static T & GetInst()
	{
		if (!instance)
			instance = new T;

		return *instance;
	}

	static void ReleaseInst()
	{
		if (instance)
			delete instance;

		instance = nullptr;
	}
};

template <class T>
T * singleton<T>::instance = nullptr;