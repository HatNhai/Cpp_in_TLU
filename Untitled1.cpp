#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTRIBUTES 100

// H�m ki?m tra xem candidate c� l� thu?c t�nh kh�ng c?n thi?t hay kh�ng
int is_superfluous(char candidate[MAX_ATTRIBUTES][MAX_ATTRIBUTES], int candidate_size, char X[MAX_ATTRIBUTES], char F[MAX_ATTRIBUTES][MAX_ATTRIBUTES], int F_size) {
    int i, j;

    for (i = 0; i < candidate_size; ++i) {
        // Lo?i b? m?t thu?c t�nh v� ki?m tra xem t?p c�n l?i c� th? t?o ra du?c b?ng F kh�ng
        int is_reduced_candidate_equal_X = 1;
        for (j = 0; j < candidate_size; ++j) {
            if (j != i && strchr(X, candidate[j][0]) == NULL) {
                is_reduced_candidate_equal_X = 0;
                break;
            }
        }

        if (is_reduced_candidate_equal_X) {
            int is_reduced_candidate_in_F = 0;
            for (j = 0; j < F_size; ++j) {
                if (strcmp(candidate[j], X) == 0) {
                    is_reduced_candidate_in_F = 1;
                    break;
                }
            }

            if (!is_reduced_candidate_in_F) {
                return 0;
            }
        }
    }

    return 1;
}

// H�m t�m t?p h?p X+
void find_closure(char X[MAX_ATTRIBUTES], char F[MAX_ATTRIBUTES][MAX_ATTRIBUTES], int F_size, char X_plus[MAX_ATTRIBUTES]) {
    strcpy(X_plus, X);  // B?t d?u v?i t?p h?p X

    while (1) {
        int found_new_attribute = 0;

        // L?p qua m?i thu?c t�nh trong t?p X
        for (int i = 0; i < strlen(X); ++i) {
            // Ki?m tra xem thu?c t�nh c� th? du?c th�m v�o X+ hay kh�ng
            char attribute[2] = {X[i], '\0'};
            if (strchr(X_plus, attribute[0]) == NULL && is_superfluous(X_plus, strlen(X_plus), X, F, F_size)) {
                strcat(X_plus, attribute);
                found_new_attribute = 1;
            }
        }

        // N?u kh�ng c� thu?c t�nh m?i n�o du?c th�m v�o, k?t th�c v�ng l?p
        if (!found_new_attribute) {
            break;
        }
    }
}

int main() {
    char X[MAX_ATTRIBUTES];
    char F[MAX_ATTRIBUTES][MAX_ATTRIBUTES];
    char X_plus[MAX_ATTRIBUTES];

    // Nh?p t?p thu?c t�nh X
    printf("Nhap tap thuoc tinh X: ");
    scanf("%s", X);

    // Nh?p t?p ph? thu?c h�m F
    int F_size;
    printf("Nhap so luong phu thuoc ham F: ");
    scanf("%d", &F_size);

    for (int i = 0; i < F_size; ++i) {
        printf("Nhap phu thuoc ham F thu %d: ", i + 1);
        scanf("%s", F[i]);
    }

    // T�m t?p h?p X+
    find_closure(X, F, F_size, X_plus);

    // In k?t qu?
    printf("Tap X+ tren F la: %s\n", X_plus);

    return 0;
}

