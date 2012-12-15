#pragma once
#include"HGEHeaders.h";
#define COL_DEFAULT 0xFF000000     //Ĭ�϶�����ɫ
#define BLEND_DEFAULT (BLEND_COLORADD | BLEND_ALPHABLEND | BLEND_ZWRITE)  //Ĭ����Ⱦģʽ

enum UpdateMode{     //�Ժ��ַ�ʽ������ȾԪ ö��
	Position =0,
	Texture =1,
	Rend=2
};

//Rendable��ֻһ�����Խ�����Ⱦ�Ĳ�������װ��(һ������)�ṹ��һ��hgeQuad�������Ȳ�������д����ȾԪ�����ڳ�����ڵ�(���ģ����)��
//Rendable����ʵ��hgeQuad��ȫҪ�ػ���(��һ�ַ���ķ���)��ֱ�ӷ��ʡ����ཫquad��Ϊ�����ֱַ��ʼ���ͷ�װ(���ʣ�λ�ã���Ⱦģʽ)��
//�ڻ�������У����ĸ������Ϊ����������һ�������Ͻǣ�һ���ǿ�ߡ����Rendable�Ĳ��ʺ�ʵ�ʶ�λ���ԣ����Ͻ�Ϊ׼��
class Rendable
{
public:
	hgeQuad *quad;//��ȾԪ
	
	HTEXTURE texture;//�����ļ����

	float TW;        //�����ļ����
	float TH;        //�����ļ��߶�

	float xy[2];     //��ȾԪ������λ��
	float txy[2];    //��ȾԪ���ʽ�ȡ���ֵ�����λ��

	float wh[2];     //��ȾԪ�Ŀ�͸�
	float twh[2];    //���ʽ�ȡ���ֵĿ�͸�

	float z[2];     //��ȾԪ���������ֵĵ�Zֵ
	DWORD col[2];   //���¶�����Ⱦ��ɫ
	DWORD blendmode; //��Ⱦģʽ

	
    //////////////////////////////////////////////////////////
	void InitQuad(HTEXTURE otexture,float otxy1,float otxy2,float otwh1,float otwh2,bool doupdate=false); //������ʣ���ѡ������Ч
	void InitQuad(float oxy1,float oxy2,float owh1,float owh2,bool doupdate=false);                     //����λ�úʹ�С����ѡ������Ч
	void InitQuad(DWORD oblendmode,float oz1,float oz2,DWORD ocol1,DWORD ocol2,bool doupdate=false);    //����߼���Ⱦģʽ����ѡ������Ч
	void InitQuad(float oz,bool doupdate=false);                                      //����ͼ���Ⱦģʽ����ѡ������Ч

	float Getcx(void);                                        //��õ�ǰquad������xλ��
	float Getcy(void);                                        //Get the y position
	void Setcxy(float oxy1,float oxy2,bool doupdate=false);             //set the xy position

	void UpdateQuad(UpdateMode mode);   //���ո�����ģʽ����Quad
	void UpdateQuad(void){UpdateQuad(Position);UpdateQuad(Texture);UpdateQuad(Rend);}//�޲�����ȫ������

	void Render(void){hge->Gfx_RenderQuad(quad);}//��HGE��GFX_RenderQuad���з�װ

	Rendable(void);
	~Rendable(void);
};

