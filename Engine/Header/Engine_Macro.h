#pragma once

namespace Engine
{
#define BEGIN(NS) namespace NS {
#define END }

#define PURE = 0
#define DECLARE_SINGLETON(CLASS) \
public: \
CLASS(const CLASS&) = delete; \
CLASS& operator=(const CLASS&) = delete \
CLASS(const CLASS&&) = default; \
CLASS& operator=(const CLASS&&) = delete \
public: \
static CLASS& GetInstance() const noexcept \
{ \
	static CALSS instance; \
	return instance; \
}

#ifdef ENGINE_EXPORTS
#define ENGINE_DLL __declspec(dllexport)
#else
#define ENGINE_DLL __declspec(dllimport)
#endif // ENGINE_EXPORTS
}

using namespace Engine;