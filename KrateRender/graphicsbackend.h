#pragma once
#include"viewportdef.h"

namespace Krate
{
	namespace KrateRender
	{
		class GraphicsBackend
		{
		protected:
			ViewPort viewPort;
		public:
			GraphicsBackend(const ViewPort& v):viewPort(v)
			{

			}

			virtual bool Initialize() = 0;
		};
	}
}