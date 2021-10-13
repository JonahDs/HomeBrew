#pragma once
#include <memory>

namespace {
	template<typename T>
	using sPtr = std::shared_ptr<T>();

	template<typename T>
	using uPtr = std::unique_ptr<T>();
}
