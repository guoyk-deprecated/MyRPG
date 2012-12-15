#include "HGEHeaders.h";
#include <windows.h>;
#include<process.h>;
#include "Rendable.h";
#include "Movable.h";
#include "RenderGroup.h";


RenderGroup rendergroup;
int currkey;                //当前按下的Key:只能由FrameFunc修改

HTEXTURE role;              //资源指针
HTEXTURE map;

Rendable *map1;
Movable *role1;
hgeQuad *quad;

bool FrameFunc1(){     //HGE的Input检测只在Frame间有效,(警告)不能用switch(hge->getkey)，效率底下。
	if(hge->Input_GetKeyState(HGEK_UP))role1->TryMove(3,true);
	if(hge->Input_GetKeyState(HGEK_DOWN))role1->TryMove(0,true);
	if(hge->Input_GetKeyState(HGEK_LEFT))role1->TryMove(1,true);
	if(hge->Input_GetKeyState(HGEK_RIGHT))role1->TryMove(2,true);
	return false;
}

bool EmptyFrameFunc(){ //这是一个空的FrameFunc为了糊弄hge，要不hge就退出了。
	return false;
}

bool RenderFunc(){
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	rendergroup.Render();
	hge->Gfx_EndScene();
	return false;
}
////////////////////////////////这是核心控制线程的入口函数，以后的主要工作就在于此了//////////////////////////
unsigned _stdcall CtrlThread(void*){
		Sleep(2000);
		hge->System_SetState(HGE_FRAMEFUNC,FrameFunc1);
		return 0;
}
///////////////////////////////////////////////////////////////////////


int static WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	hge->System_SetState(HGE_FRAMEFUNC,EmptyFrameFunc);
	hge->System_SetState(HGE_ZBUFFER,true);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "测试用1");
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_FPS,60);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(!(hge->System_Initiate())){
		MessageBox(NULL, "无法初始化", "关键错误", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		hge->System_Shutdown();
		hge->Release();
		return false;
	}
	//资源文件初始化阶段//////////////////////////////////
	role=hge->Texture_Load("role.png");
	map=hge->Texture_Load("map.png");
	map1=new Rendable();
	role1=new Movable();
	map1->InitQuad(map,0.0f,0.0f,800.0f,600.0f,true);
	map1->InitQuad(0.0f,0.0f,800.0f,600.0f,true);
	map1->InitQuad(0.9f,true);
	role1->InitQuad(role,0.0f,0.0f,32.0f,48.0f,true);
	role1->InitQuad(100.0f,100.0f,32.0f,48.0f,true);
	role1->InitQuad(0.8f,true);
	role1->speed=2.0f;
	rendergroup.AddRender(role1);
	rendergroup.AddRender(map1);
	/////////////////////////////////////////////////////新开核心控制线程////////////////////
	HANDLE hThread;
    unsigned int threadID;
	hThread = (HANDLE)_beginthreadex(NULL, 0, &CtrlThread, NULL, 0, &threadID);//暂时没有需要修改这些参数
	/////////////////////////////////////////////////////////////////////////////////////////
	hge->System_Start();
	hge->System_Shutdown();
	hge->Release();
	return true;
}