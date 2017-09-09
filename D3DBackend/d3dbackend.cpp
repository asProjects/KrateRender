#include"framework.h"
#include"d3dbackend.h"

using namespace Krate::KrateRender;
using namespace Krate::KrateRender::D3DWrapper;

//Core::D3DContext context;

bool D3DBackend::Initialize()
{
	context.Initialize(viewPort);
}

