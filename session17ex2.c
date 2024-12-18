#include <stdio.h>
#include <stdlib.h>

int chucai(const char *str) {
    int count = 0;
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            count++;
        }
        str++;
    }
    return count;
}

int chuso(const char *str) {
    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        str++;
    }
    return count;
}

int kitu(const char *str) {
    int count = 0;
    while (*str) {
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9') || *str == ' ')) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char *str = NULL;
    int choice;
    size_t len = 0;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:{
                printf("Nhap chuoi: ");
                free(str);
                str = NULL;
                len = 0;
                char c;
                while ((c = getchar()) != '\n') {
                    str = realloc(str, len + 2);
                    str[len++] = c;             
                    str[len] = '\0';          
                }
                break;
            }
            case 2:
                if (str) {
                    printf("Chuoi vua nhap: %s\n", str);
                } else {
                    printf("Chuoi rong. Hay nhap chuoi truoc!\n");
                }
                break;
            case 3:
                if (str) {
                    printf("So luong chu cai: %d\n", chucai(str));
                } else {
                    printf("Chuoi rong. Hay nhap chuoi truoc!\n");
                }
                break;
            case 4:
                if (str) {
                    printf("So luong chu so: %d\n", chuso(str));
                } else {
                    printf("Chuoi rong. Hay nhap chuoi truoc!\n");
                }
                break;
            case 5:
                if (str) {
                    printf("So luong ky tu dac biet: %d\n", kitu(str));
                } else {
                    printf("Chuoi rong. Hay nhap chuoi truoc!\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 6);
    free(str);
    return 0;
}

