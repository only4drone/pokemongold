#pragma once
#include "gameNode.h"


//포켓몬 타입
enum class TYPE
{
	NONE,	//없음
	NOMAL,	//노말
	FIRE,	//불
	WATER,	//물
	GRASS,	//풀
	ELECTR,	//전기
	ICE,	//얼음
	FIGHT,	//격투
	POISON,	//독
	GROUND,	//땅
	FLYING,	//비행
	PSYCHC,	//초능력
	BUG,	//벌레
	ROCK,	//바위
	GHOST,	//유령
	DRAGON,	//드래곤
	DARK,	//악
	STEEL,	//강철
	FAIRY	//요정
};

// 포켓몬 데이터
//struct tagPOKETMON
//{
//	string name;							// 이름
//	string gender;							// 성별
//	bool isGender;							// 성별 체크
//	int index;								// 인덱스 번호
//	int level;								// 포켓몬 현재 레벨
//	int	evolutionLevel;						// 진화 단계
//
//	int iconNumX;							// 미니 포켓몬 이미지 아이콘 좌표 X
//	int iconNumY;							// 미니 포켓몬 이미지 아이콘 좌표 Y
//
//	int type1; 								// 포켓몬 타입1	
//	int type2;								// 포켓몬 타입2
//
//	int	attack;								// 1레벨 초기 공격
//	int	defense;							// 1레벨 초기 방어	
//	int specialAttack;						// 1레벨 초기 특수공격
//	int	specialDefense;						// 1레벨 초기 특수방어
//	int	speed;								// 1레벨 초기 스피드
//	int	currentHP;							// 1레벨 초기 현재 체력
//	int	maxHP;								// 1레벨 초기 최대 체력
//
//	float levelAttack;						// 레벨당 증가하는 공격
//	float levelDefense;						// 레벨당 증가하는 방어	
//	float levelSpecialAttack;				// 레벨당 증가하는 특수공격
//	float levelSpecialDefense;				// 레벨당 증가하는 특수방어
//	float levelSpeed;						// 레벨당 증가하는 스피드
//	float levelHP;							// 레벨당 증가하는 체력
//
//	int sumAttack;							// 최종 공격
//	int sumDefense;							// 최종 방어
//	int sumSpecialAttack;					// 최종 특수공격
//	int sumSpecialDefense;					// 최종 특수방어
//	int sumSpeed;							// 최종 스피드
//	int sumMaxHP;							// 최종 체력
//	
//
//	float currentExp;						// 현재 경험치(현재 얻은 총 경험치, level값 만큼 빼서 나머지 양 보여주기)
//	float maxExp;							// 최대 경험치(현재 레벨의 최대 경험치 값 표시)
//
//	float totalEXP;							// 토탈 경험치
//
//	int	skill[4];							// 스킬1 인덱스 
//
//
//	int skillPP[4];							// 스킬1 남은 PP
//	
//
//	int item;								// 보유 중인 아이템 인덱스
//};



class poketmon : public gameNode
{
protected:
	tagPOKETMON_PLAYER _poketmon;





public:
	poketmon();
	~poketmon();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수

	void attackAI();

	void genderSettings();					//젠더 함수
	void potketmonEXP();					//경험치
	void ability();							//레벨당 능력 계산 함수

	tagPOKETMON_PLAYER getTagPoketmon() { return _poketmon; }	//포켓몬구조체 겟터?
	
	

};