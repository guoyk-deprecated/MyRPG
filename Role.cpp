#include "Role.h"

Role::Role(HTEXTURE texture,Map *mapo){      
	*map=*mapo;
	quad.blend=BLEND_ALPHABLEND|BLEND_COLORADD|BLEND_ZWRITE;
	quad.tex=texture;
}

//�����൱ǰ�Ĳ�����quad�������¹���(ִ�д����Ż���)
void Role::FlushQuad()                  
{
	float time=hge->Timer_GetTime();
	float row,col;
	row=direction;
	col=isongoing?((int)(time*9))%4:0;//ʹ��(ʱ��*ϵ��)��4ȡ��ʵ��֡���ı仯

	if(effect){
	quad.v[0].z=z1;quad.v[0].col=(int)(0xFF*visibility)*0x1000000;
	quad.v[1].z=z1;quad.v[1].col=(int)(0xFF*visibility)*0x1000000;
	quad.v[2].z=z2;quad.v[2].col=(int)(0xFF*visibility)*0x1000000;
	quad.v[3].z=z2;quad.v[3].col=(int)(0xFF*visibility)*0x1000000;
	}
	quad.v[0].tx=col/4    ;quad.v[0].ty=row/4;
	quad.v[1].tx=(col+1)/4;quad.v[1].ty=row/4;
	quad.v[2].tx=(col+1)/4;quad.v[2].ty=(row+1)/4;
	quad.v[3].tx=col/4    ;quad.v[3].ty=(row+1)/4;
	
	quad.v[0].x=x-16;quad.v[0].y=y-24;
	quad.v[1].x=x+16;quad.v[1].y=y-24;
	quad.v[2].x=x+16;quad.v[2].y=y+24;
	quad.v[3].x=x-16;quad.v[3].y=y+24;

}

Role::Role(void)
{
}


Role::~Role(void)
{
}
