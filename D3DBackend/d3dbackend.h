#pragma once
#include"../KrateRender/graphicsbackend.h"



namespace Krate
{
	namespace KrateRender
	{
		namespace D3DWrapper
		{
			namespace Core
			{
				class D3DContext;
			}


			class D3DBackend : public GraphicsBackend
			{
				D3DWrapper::Core::D3DContext context;
			public:
				D3DBackend(const ViewPort& viewPort):GraphicsBackend(viewPort)
				{

				}

				virtual bool Initialize() override;
			};
		}
	}
}