#pragma once
#include"HGEHeaders.h";
#define COL_DEFAULT 0xFF000000     //默认顶点颜色
#define BLEND_DEFAULT (BLEND_COLORADD | BLEND_ALPHABLEND | BLEND_ZWRITE)  //默认渲染模式

enum UpdateMode{     //以何种方式更新渲染元 枚举
	Position =0,
	Texture =1,
	Rend=2
};

//Rendable是只一个可以进行渲染的部件，封装了(一级缓存)结构和一个hgeQuad，可以先不把数据写入渲染元，便于程序初期的(大规模载入)。
//Rendable可以实现hgeQuad的全要素缓存(以一种方便的方法)和直接访问。本类将quad分为三部分分别初始化和封装(材质，位置，渲染模式)。
//在缓存过程中，将四个定点简化为两个向量，一个是左上角，一个是宽高。因此Rendable的材质和实际定位均以（左上角为准）
class Rendable
{
public:
	hgeQuad *quad;//渲染元
	
	HTEXTURE texture;//材质文件句柄

	float TW;        //材质文件宽度
	float TH;        //材质文件高度

	float xy[2];     //渲染元的左上位置
	float txy[2];    //渲染元材质截取部分的左上位置

	float wh[2];     //渲染元的宽和高
	float twh[2];    //材质截取部分的宽和高

	float z[2];     //渲染元上下两部分的的Z值
	DWORD col[2];   //上下定点渲染颜色
	DWORD blendmode; //渲染模式

	
    //////////////////////////////////////////////////////////
	void InitQuad(HTEXTURE otexture,float otxy1,float otxy2,float otwh1,float otwh2,bool doupdate=false); //载入材质，可选立即生效
	void InitQuad(float oxy1,float oxy2,float owh1,float owh2,bool doupdate=false);                     //载入位置和大小，可选立即生效
	void InitQuad(DWORD oblendmode,float oz1,float oz2,DWORD ocol1,DWORD ocol2,bool doupdate=false);    //载入高级渲染模式，可选立即生效
	void InitQuad(float oz,bool doupdate=false);                                      //载入低级渲染模式，可选立即生效

	float Getcx(void);                                        //获得当前quad的中心x位置
	float Getcy(void);                                        //Get the y position
	void Setcxy(float oxy1,float oxy2,bool doupdate=false);             //set the xy position

	void UpdateQuad(UpdateMode mode);   //按照给定的模式更新Quad
	void UpdateQuad(void){UpdateQuad(Position);UpdateQuad(Texture);UpdateQuad(Rend);}//无参数则全部更新

	void Render(void){hge->Gfx_RenderQuad(quad);}//对HGE的GFX_RenderQuad进行封装

	Rendable(void);
	~Rendable(void);
};

