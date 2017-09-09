#include<Windows.h>
#include<string>
#include"../KrateRender/render_main.h"

using namespace std;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto num = getRenderNum();
	wstring st = L"The number is";

	st += num;

	MessageBox(nullptr, st.c_str(), L"Hello", MB_OK);

	return 0;
}