#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", n);

    *arr = (int *)malloc((*n) * sizeof(int));

    printf("Nhap %d phan tu:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", (*arr) + i);
    }
}

void hienThiMang(int *arr, int n) {
    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int tinhDoDaiMang(int *arr, int n) {
    return n;
}

int tinhTongMang(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int timMax(int *arr, int n) {
    int max = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int *arr = NULL; 
    int n = 0;    
    int luaChon;

    do {
        printf("\nMENU:\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                if (arr != NULL){
                	hienThiMang(arr, n);
				}else{
					printf("Mang chua duoc nhap.\n");
				}break;
            case 3:
                printf("Do dai cua mang: %d\n", tinhDoDaiMang(arr, n));
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", tinhTongMang(arr, n));
                break;
            case 5:
                if (arr != NULL) {
                    printf("Phan tu lon nhat trong mang: %d\n", timMax(arr, n));
                } else {
                    printf("Mang chua duoc nhap.\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 6);

    free(arr);
    return 0;
}

