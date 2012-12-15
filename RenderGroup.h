#pragma once
#include "Rendable.h";
class RenderGroup         //为一组rendable类提供封装，姑且认为不会同时存在相同的渲染元
{
public:
	Rendable *renders[20]; //提供一个大小为20的渲染器容器
	
	void Render();         //渲染所有的内部Render
	bool AddRender(Rendable *orendabale);
	bool RemoveRender(Rendable *orendable);
	RenderGroup(int osize=10);
	~RenderGroup(void);
};

