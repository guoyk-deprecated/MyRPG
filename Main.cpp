#include "HGEHeaders.h";
#include <windows.h>;
#include<process.h>;
#include "Rendable.h";
#include "Movable.h";
#include "RenderGroup.h";


RenderGroup rendergroup;
int currkey;                //��ǰ���µ�Key:ֻ����FrameFunc�޸�

HTEXTURE role;              //��Դָ��
HTEXTURE map;

Rendable *map1;
Movable *role1;
hgeQuad *quad;

bool FrameFunc1(){     //HGE��Input���ֻ��Frame����Ч,(����)������switch(hge->getkey)��Ч�ʵ��¡�
	if(hge->Input_GetKeyState(HGEK_UP))role1->TryMove(3,true);
	if(hge->Input_GetKeyState(HGEK_DOWN))role1->TryMove(0,true);
	if(hge->Input_GetKeyState(HGEK_LEFT))role1->TryMove(1,true);
	if(hge->Input_GetKeyState(HGEK_RIGHT))role1->TryMove(2,true);
	return false;
}

bool EmptyFrameFunc(){ //����һ���յ�FrameFuncΪ�˺�Ūhge��Ҫ��hge���˳��ˡ�
	return false;
}

bool RenderFunc(){
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	rendergroup.Render();
	hge->Gfx_EndScene();
	return false;
}
////////////////////////////////���Ǻ��Ŀ����̵߳���ں������Ժ����Ҫ���������ڴ���//////////////////////////
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
	hge->System_SetState(HGE_TITLE, "������1");
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_FPS,60);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(!(hge->System_Initiate())){
		MessageBox(NULL, "�޷���ʼ��", "�ؼ�����", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		hge->System_Shutdown();
		hge->Release();
		return false;
	}
	//��Դ�ļ���ʼ���׶�//////////////////////////////////
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
	/////////////////////////////////////////////////////�¿����Ŀ����߳�////////////////////
	HANDLE hThread;
    unsigned int threadID;
	hThread = (HANDLE)_beginthreadex(NULL, 0, &CtrlThread, NULL, 0, &threadID);//��ʱû����Ҫ�޸���Щ����
	/////////////////////////////////////////////////////////////////////////////////////////
	hge->System_Start();
	hge->System_Shutdown();
	hge->Release();
	return true;
}