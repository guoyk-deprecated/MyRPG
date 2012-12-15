#include "Rendable.h";

void Rendable::InitQuad(HTEXTURE otexture,float otxy1,float otxy2,float otwh1,float otwh2,bool doupdate){//载入材质
	texture=otexture;
	TW=hge->Texture_GetWidth(otexture,true);
	TH=hge->Texture_GetHeight(otexture,true);
	txy[0]=otxy1;
	txy[1]=otxy2;
	twh[0]=otwh1;
	twh[1]=otwh2;
	if(doupdate)UpdateQuad(Texture);
}
void Rendable::InitQuad(float oxy1,float oxy2,float owh1,float owh2,bool doupdate){                 //载入位置和宽高
	xy[0]=oxy1;
	xy[1]=oxy2;
	wh[0]=owh1;
	wh[1]=owh2;
	if(doupdate)UpdateQuad(Position);
}
void Rendable::InitQuad(DWORD oblendmode,float oz1,float oz2,DWORD ocol1,DWORD ocol2,bool doupdate){//载入高级渲染模式
	blendmode=oblendmode;
	z[0]=oz1;
	z[1]=oz2;
	col[0]=ocol1;
	col[1]=ocol2;
	if(doupdate)UpdateQuad(Rend);
}
void Rendable::InitQuad(float oz,bool doupdate){//载入低级渲染模式
	blendmode=BLEND_DEFAULT;
	z[0]=oz;
	z[1]=oz;
	col[0]=COL_DEFAULT;
	col[1]=COL_DEFAULT;
	UpdateQuad(Rend);
}

float Rendable::Getcx(void){  //得到其中心的x坐标
	return xy[0]+(wh[0]/2);  //Yeah~~
}

float Rendable::Getcy(void){  //得到中心的y坐标
	return xy[1]+(wh[1]/2); //何其凶残
}
void Rendable::Setcxy(float oxy1,float oxy2,bool doupdate){//移动中心位置
	xy[0]=oxy1-wh[0];
	xy[1]=oxy2-wh[1];     //何其凶残
	if(doupdate)UpdateQuad(Position);
}

void Rendable::UpdateQuad(UpdateMode mode){   //使用某种模式更新渲染元，替代原来的FLush函数
	switch(mode){
	case Position:
		quad->v[0].x=xy[0];
		quad->v[0].y=xy[1];
	    quad->v[1].x=xy[0]+wh[0];
	    quad->v[1].y=xy[1];
		quad->v[2].x=xy[0]+wh[0];
		quad->v[2].y=xy[1]+wh[1];
		quad->v[3].x=xy[0];
		quad->v[3].y=xy[1]+wh[1];
		break;
	case Texture:
		quad->tex=texture;
		quad->v[0].tx=txy[0]/TW;
		quad->v[0].ty=txy[1]/TH;
		quad->v[1].tx=(txy[0]+twh[0])/TW;
		quad->v[1].ty=txy[1]/TH;
		quad->v[2].tx=(txy[0]+twh[0])/TW;
		quad->v[2].ty=(txy[1]+twh[1])/TH;
		quad->v[3].tx=txy[0]/TW;
		quad->v[3].ty=(txy[1]+twh[1])/TH;
		break;
	case Rend:
		quad->blend=blendmode;
		quad->v[0].col=col[0];
		quad->v[0].z=z[0];
		quad->v[1].col=col[0];
		quad->v[1].z=z[0];
		quad->v[2].col=col[1];
		quad->v[2].z=z[1];
		quad->v[3].col=col[1];
		quad->v[3].z=z[1];
		break;
	}
	
}

Rendable::Rendable(void){
	quad=new hgeQuad();
}

Rendable::~Rendable(void)
{
}
