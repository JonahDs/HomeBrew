#pragma once
namespace HomeBrew {
	template<class T>
	class Singleton {
	public:
		static T* GetInstance() {
			if (p_instance == nullptr)
				p_instance = new T();
			return p_instance;
		}
		static void DestroyInstance() {
			if (p_instance != nullptr)
				delete p_instance;
		}
	private:
		static T* p_instance;
	};

	template<class T>
	T* Singleton<T>::p_instance = nullptr;
}