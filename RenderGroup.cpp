#include "RenderGroup.h"



void RenderGroup::Render(){
	for(int i=0;i<20;i++){
		if(!(renders[i]==0))renders[i]->Render();
	}
}

bool RenderGroup::AddRender(Rendable *orender){
	for(int i=0;i<20;i++)
	{
		if(renders[i]==0){
			renders[i]=orender;
			return true;
		}
	}
	return false;
}

bool RenderGroup::RemoveRender(Rendable *orender){
	for(int i=0;i<20;i++)
	{
		if(renders[i]==orender){
			renders[i]=0;
			return true;
		}
	}
	return false;
}

RenderGroup::RenderGroup(int osize)
{
	for(int i=0;i<20;i++){
		renders[i]=0;
	}
}
RenderGroup::~RenderGroup(void)
{
}
