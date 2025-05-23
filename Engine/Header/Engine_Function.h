#pragma once

namespace Engine
{
template<typename T>
void SAFE_DELETE(T& Point)
{
	delete Point;
	Point = nullptr;
}

template<typename T>
void SAFE_DELETE_VEC(std::vector<T*>& Vec)
{
	for(auto& var : Vec)
	{
		delete var;
		var = nullptr;
	}
	Vec.clear();
}

}