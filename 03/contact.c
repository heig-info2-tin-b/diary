#include <stdio.h>

typedef struct contact {
    char first_name[128];
    char last_name[128];
    int age;
    int icq;
    char phone[30];
} Contact;
    
void display_contact(const Contact *c) {
    printf("Name: %s %s\n", c->first_name, c->last_name);
    printf("Age: %d\n", c->age);
    printf("ICQ: %d\n", c->icq);
    printf("Phone: %s\n", c->phone);
    printf("-------------------------\n");
}

int main() {
    Contact contacts[10] = {
        {"Yves", "Chevallier", 44, 13492763, "+41791234567"},
        {"Alice", "Smith", 30, 98765432, "+1234567890"},
        {"Bob", "Johnson", 25, 56789012, "+1987654321"},
        {"Charlie", "Brown", 35, 34567890, "+1123456789"},
        {"David", "Wilson", 28, 23456789, "+1098765432"},
        {"Eve", "Davis", 22, 12345678, "+1012345678"},
        {"Frank", "Miller", 40, 87654321, "+1023456789"},
        {"Grace", "Taylor", 27, 76543210, "+1034567890"},
        {"Hannah", "Anderson", 32, 65432109, "+1045678901"},
        {"Ivan", "Thomas", 29, 54321098, "+1056789012"}
    };

    for (int i = 0; i < 10; i++) {
        display_contact(contacts[i]);
    }
}