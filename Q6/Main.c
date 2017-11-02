#include<stdio.h>
#include<stdlib.h>

#define MONSTER_COUNT 5

typedef struct monsterInfo
{	
	int nHp;
	int nMp;
	int nDamage;
	int nDefence;
	char name[30];
	char skillName[30];
	
}MonsterInfo;


MonsterInfo *Initialize(int _monsterCnt)
{
	int i;

	MonsterInfo *pTemp = malloc(sizeof(MonsterInfo) * _monsterCnt);
	return pTemp;
    /*
	for (i = 0; i < _monsterCnt; i++)
	{
		_pMonsterInfo[i] = (MonsterInfo*)malloc(sizeof(MonsterInfo) * _monsterCnt);
	}*/
}
void InputInfo(int _monsterCnt, MonsterInfo *_pMonsterInfo)
{
	int i = 0;
	
	for (i = 0; i < _monsterCnt; i++)
	{
		printf("몬스터의 이름을 입력하세요 : ");
		scanf_s("%s", &_pMonsterInfo[i].name,sizeof(_pMonsterInfo[i].name));
		printf("HP를 입력 하세요 : ");
		scanf_s("%d",&_pMonsterInfo[i].nHp);
		printf("MP를 입력 하세요 : ");
		scanf_s("%d", &_pMonsterInfo[i].nMp);
		printf("공격력을 입력 하세요 : ");
		scanf_s("%d", &_pMonsterInfo[i].nDamage);
		printf("방어력을 입력 하세요 : ");
		scanf_s("%d", &_pMonsterInfo[i].nDefence);
		printf("스킬명을 입력하세요 : ");
		scanf_s("%s", &_pMonsterInfo[i].skillName,sizeof(_pMonsterInfo[i].skillName));
		printf("\n");
	}	
}

void PrintMonsterInfo(int _monsterCnt, MonsterInfo *_pMonsterInfo)
{
	int i;

	for (i = 0; i < _monsterCnt; i++)
	{
		printf("%d번째 몬스터의 정보\n", i + 1 );
		printf("이름 : %s\n", _pMonsterInfo[i].name);
		printf("HP : %d\n", _pMonsterInfo[i].nHp );
		printf("MP : %d\n", _pMonsterInfo[i].nMp );
		printf("공격력 : %d\n", _pMonsterInfo[i].nDamage );
		printf("방어력 : %d\n", _pMonsterInfo[i].nDefence );
		printf("스킬명 : %s\n", _pMonsterInfo[i].skillName );
		printf("\n");
	}
}
void Release(MonsterInfo *_pMonsterInfo)
{	
	free(_pMonsterInfo);
}

void main()
{
	int monsterCnt = 0;

	printf("입력할 몬스터의 숫자를 입력 하세요 : ");
	scanf_s("%d", &monsterCnt);

	MonsterInfo *pMonsterInfo = Initialize(monsterCnt);

	InputInfo(monsterCnt, pMonsterInfo);
	PrintMonsterInfo(monsterCnt, pMonsterInfo);
	Release(pMonsterInfo);
}
