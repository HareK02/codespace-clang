#include <stdio.h>

typedef struct {
		int id;
		char name[30];
		char reason[50];
} PersonCard;

void Gate(PersonCard *personCard) {
	printf("IDを入力してください: ");
	scanf("%d", &personCard->id);
	printf("氏名を入力してください: ");
	scanf("%s", personCard->name);
	printf("入構理由を入力してください: ");
	scanf("%s", personCard->reason);
}

void Disp(PersonCard *personCard) {
	printf("ID: %d\n", personCard->id);
	printf("Name: %s\n", personCard->name);
	printf("Reason: %s\n", personCard->reason);
}

int main(void) {
	PersonCard personCard;
	Gate(&personCard);
	Disp(&personCard);
	return 0;
}
