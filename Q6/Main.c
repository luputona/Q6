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
		printf("������ �̸��� �Է��ϼ��� : ");
		scanf_s("%s", &_pMonsterInfo[i].name,sizeof(_pMonsterInfo[i].name));
		printf("HP�� �Է� �ϼ��� : ");
		scanf_s("%d",&_pMonsterInfo[i].nHp);
		printf("MP�� �Է� �ϼ��� : ");
		scanf_s("%d", &_pMonsterInfo[i].nMp);
		printf("���ݷ��� �Է� �ϼ��� : ");
		scanf_s("%d", &_pMonsterInfo[i].nDamage);
		printf("������ �Է� �ϼ��� : ");
		scanf_s("%d", &_pMonsterInfo[i].nDefence);
		printf("��ų���� �Է��ϼ��� : ");
		scanf_s("%s", &_pMonsterInfo[i].skillName,sizeof(_pMonsterInfo[i].skillName));
		printf("\n");
	}	
}

void PrintMonsterInfo(int _monsterCnt, MonsterInfo *_pMonsterInfo)
{
	int i;

	for (i = 0; i < _monsterCnt; i++)
	{
		printf("%d��° ������ ����\n", i + 1 );
		printf("�̸� : %s\n", _pMonsterInfo[i].name);
		printf("HP : %d\n", _pMonsterInfo[i].nHp );
		printf("MP : %d\n", _pMonsterInfo[i].nMp );
		printf("���ݷ� : %d\n", _pMonsterInfo[i].nDamage );
		printf("���� : %d\n", _pMonsterInfo[i].nDefence );
		printf("��ų�� : %s\n", _pMonsterInfo[i].skillName );
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

	printf("�Է��� ������ ���ڸ� �Է� �ϼ��� : ");
	scanf_s("%d", &monsterCnt);

	MonsterInfo *pMonsterInfo = Initialize(monsterCnt);

	InputInfo(monsterCnt, pMonsterInfo);
	PrintMonsterInfo(monsterCnt, pMonsterInfo);
	Release(pMonsterInfo);
}
