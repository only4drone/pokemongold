#pragma once
#define TILESIZE 32	//Ÿ�� ������ 32X32

#define TILEX 20	//���� Ÿ�� ����
#define TILEY 20	//���� Ÿ�� ����

//Ÿ�� �԰� 20 X 32 ������ϱ� -> �� ������� 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//Ÿ�� �� ���� 20�� ���� 9��
#define SAMPLETILEX 20
#define SAMPLETILEY 9

//�̳ѹ����� �ص� ������ �������� �޸� �Ƴ��ٰ� ���� ���
//��Ʈ�ʵ�� �� �� �غ��ڽ��� (������ �� �̳ѹ� �ᵵ ������)

#define ATTR_UNMOVE 0x00000001	//������ Ÿ��
#define ATTR_SWAMP	0x00000002	//������
#define ATTR_POISON	0x00000004	//������
#define ATTR_FROZEN	0x00000008	//��������


//����
enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

//������Ʈ
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2, OBJ_NONE
};

enum POS
{
	//1P���� ���(������ ���) 1P ��ũ ������ ��ġ
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
};

//Ÿ�� ����ü (Ÿ�� �������� ����ִ�)
struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;
	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
};

//Ÿ�� ��
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};
