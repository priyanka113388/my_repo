
#include <stdio.h>
#include <string.h>

void xorDiv(char *data, const char *divisor, char *rem) {
    int len = strlen(divisor), i, j;
    char temp[100];

    strncpy(temp, data, len);
    temp[len] = '\0';

    for (i = 0; i <= strlen(data) - len; i++) {
        if (temp[0] == '1') {
            for (j = 0; j < len; j++)
                temp[j] = (temp[j] == divisor[j]) ? '0' : '1';
        }
        if (i + len < strlen(data)) {
            memmove(temp, temp + 1, len - 1);
            temp[len - 1] = data[i + len];
            temp[len] = '\0';
        }
    }
    strcpy(rem, temp);
}

int main() {
    char gen[] = "1100000001011", data[100], recv[100], crc[30], temp[150];

    printf("Enter transferred data: ");
    scanf("%s", data);
    printf("Enter received data: ");
    scanf("%s", recv);

    strcpy(temp, data);
    strcat(temp, "000000000000");

    printf("\nDividing: %s ) %s (\n", gen, temp);
    xorDiv(temp, gen, crc);
    printf("CRC is: %s\n", crc);

    strcat(data, crc);
    printf("\nDividing received data: %s ) %s (\n", gen, data);

    xorDiv(data, gen, crc);
    printf("Remainder after division: %s\n", crc);

    if (strchr(crc, '1') == NULL)
        printf("\nData transferred correctly\n");
    else
        printf("\nData transferred incorrectly\n");

    return 0;
}