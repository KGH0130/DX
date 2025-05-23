#pragma once
#include "Engine_Enum.h"
#include "Engine_Macro.h"

BEGIN(Engine)
class IClone;

class ENGINE_DLL PrototypeManager
{
public:
	~PrototypeManager();

public:
	void Register_Prototype(PROTO_TYPE Type, const std::string& Name, IClone* Clone);

	IClone* Clone(PROTO_TYPE Type, const std::string& Name, const void* Args = nullptr);

public:
	void Clear();

private:
	std::array<std::unordered_map<std::string, IClone*>, static_cast<size_t>(PROTO_TYPE::IDX)> m_ProtoMap;

	std::vector<IClone*> m_Clones;
};
END