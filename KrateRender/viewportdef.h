#pragma once
#include<cstddef>

namespace Krate
{
	namespace KrateRender
	{
		struct ViewPort
		{
			std::size_t Height;
			std::size_t Width;
			std::size_t RefreshRate;

			std::size_t BufferSize;

			void* WindowHandle;
		};
	}
}