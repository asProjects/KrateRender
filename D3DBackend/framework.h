#pragma once
#include"utility.h"
#include"../KrateRender/viewportdef.h"


namespace Krate
{
	namespace KrateRender
	{
		namespace D3DWrapper
		{
			namespace Core
			{
				class D3DContext;

				//static class containing references to descriptor data 
				class D3DDataStructures
				{
					//Descriptor Heaps
					static Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
					static Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

					//Descriptor sizes
					static std::size_t cbvDescriptorSize;
					static std::size_t dsvDescriptorSize;
					static std::size_t rtvDescriptorSize;

					//D3DResources
					static Microsoft::WRL::ComPtr<ID3D12Resource> swapChainBuffers[2];
					static Microsoft::WRL::ComPtr<ID3D12Resource> depthStencilBuffer;

					friend class D3DContext;
				};


				class D3DContext
				{
					Microsoft::WRL::ComPtr<IDXGIFactory4> dxgiFactory;
					Microsoft::WRL::ComPtr<ID3D12Device> device;
					Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;


					//Command Objects
					Microsoft::WRL::ComPtr<ID3D12CommandQueue> cmdQueue;
					Microsoft::WRL::ComPtr<ID3D12CommandAllocator> cmdListAlloc;
					Microsoft::WRL::ComPtr<ID3D12CommandList> cmdList;

					//ViewPort Objects
					D3D12_VIEWPORT viewPort;
					D3D12_RECT scissorRect;

					//For Synchronization
					Microsoft::WRL::ComPtr<ID3D12Fence> fence;

				public:

					D3DContext()
					{

					}

					bool Initialize(const ViewPort& viewPort);

					D3DContext(const D3DContext& rhs) = delete;
					D3DContext& operator=(const D3DContext& rhs) = delete;
				};
			}
		}
		
	}
}




