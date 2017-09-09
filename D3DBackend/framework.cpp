#include"framework.h"

using namespace Krate::KrateRender;
using namespace Krate::KrateRender::D3DWrapper::Core;


//Descriptor Heaps
Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> D3DDataStructures::rtvHeap;
Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> D3DDataStructures::dsvHeap;

//Descriptor sizes
std::size_t D3DDataStructures::cbvDescriptorSize;
std::size_t D3DDataStructures::dsvDescriptorSize;
std::size_t D3DDataStructures::rtvDescriptorSize;

//D3DResources
Microsoft::WRL::ComPtr<ID3D12Resource> D3DDataStructures::swapChainBuffers[2];
Microsoft::WRL::ComPtr<ID3D12Resource> D3DDataStructures::depthStencilBuffer;



bool D3DContext::Initialize(const ViewPort& viewPort)
{
	HRESULT result;

	result = CreateDXGIFactory1(__uuidof(dxgiFactory.Get()), &dxgiFactory);
	
	if (FAILED(result))
	{
		return false;
	}

	result = D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, __uuidof(device.Get()), &device);


	if (FAILED(result))
	{
		Microsoft::WRL::ComPtr<IDXGIAdapter> warp;

		dxgiFactory->EnumWarpAdapter(__uuidof(warp.Get()), &warp);

		result = D3D12CreateDevice(warp.Get(), D3D_FEATURE_LEVEL_11_0, __uuidof(device), &device);

		if (FAILED(result))
		{
			return false;
		}
	}

	D3D12_COMMAND_QUEUE_DESC qDesc{};
	qDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
	qDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;

	result = device->CreateCommandQueue(&qDesc,__uuidof(cmdQueue.Get()),&cmdQueue);

	if (FAILED(result))
	{
		return false;
	}

	result = device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, __uuidof(cmdListAlloc.Get()), &cmdListAlloc);

	if (FAILED(result))
	{
		return false;
	}

	result = device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, cmdListAlloc.Get(), nullptr, __uuidof(cmdList.Get()), &cmdList);

	if (FAILED(result))
	{
		return false;
	}


	DXGI_SWAP_CHAIN_DESC swapDesc;

	swapDesc.BufferCount = 2;
	swapDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapDesc.BufferDesc.Height = viewPort.Height;
	swapDesc.BufferDesc.Width = viewPort.Width;
	swapDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapDesc.BufferDesc.RefreshRate.Numerator = viewPort.RefreshRate;
	swapDesc.BufferDesc.RefreshRate.Denominator = 1;

	swapDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	swapDesc.OutputWindow = static_cast<HWND>(viewPort.WindowHandle);

	swapDesc.SampleDesc.Count = 1;
	swapDesc.SampleDesc.Quality = 0;

	swapDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapDesc.Windowed = true;
	//result = dxgiFactory->CreateSwapChain()l
}
