#pragma once
#include "Rendable.h";
class RenderGroup         //Ϊһ��rendable���ṩ��װ��������Ϊ����ͬʱ������ͬ����ȾԪ
{
public:
	Rendable *renders[20]; //�ṩһ����СΪ20����Ⱦ������
	
	void Render();         //��Ⱦ���е��ڲ�Render
	bool AddRender(Rendable *orendabale);
	bool RemoveRender(Rendable *orendable);
	RenderGroup(int osize=10);
	~RenderGroup(void);
};

