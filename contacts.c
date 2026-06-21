#include<stdio.h>

typedef enum {
	FAMILY,
	FRIEND,
	COLLEAGUE
} ContactType;

typedef struct{
	char *contactName;
	char *phoneNumber;
	ContactType contactType;
} Contact;

const char* contactType(ContactType cType){
	switch(cType){
		case FAMILY: return "Семья";
		case FRIEND: return "Друн";
		case COLLEAGUE: return "Коллега";
		default: return "Неизвестный";
	}
}

void getContact(Contact *contact){
	printf("Contact name: %s\nContact number: %s\nContact type: %s\n", contact->contactName, contact->phoneNumber, contactType(contact->contactType));
}

void compareContact(Contact *a, Contact *b){
	if(a->contactType == b->contactType){
		printf("Один тип");
	}
	else{
		printf("Разный тип");
	}
}

void changeNumber(Contact *c, char* newNumber){
	c->phoneNumber = newNumber;
}

int main(void){
	
	Contact contactFriend = {"ГлебZ", "+79963128869", FRIEND};
	Contact contactFriend2 = {"Сатана 666", "+79960256469", FRIEND};
	getContact(&contactFriend);
	changeNumber(&contactFriend, "+79141488667");
	getContact(&contactFriend);
	compareContact(&contactFriend, &contactFriend2);
	return 0;
}
