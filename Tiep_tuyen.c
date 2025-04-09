#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double derivative1(double (*f)(double), double x) { /// Hàm Lượng Giác
    double delta = 0.00000001;  // Đây là giá trị delta nhỏ
    return (f(x + delta) - f(x)) / delta;
}

double my_sin(double x) {
    return sin(x);
}

double my_cos(double x) {
    return cos(x);
}

double my_tan(double x){
    return tan(x);
}

double calculate1(char* func, double x) {
    char trigFunc[4];
    double multiplier;
    int rev; 
    // Sử dụng sscanf để phân tách chuỗi
    sscanf(func, "%d%3s%lf",&rev, trigFunc, &multiplier);

    if (strcmp(trigFunc, "sin") == 0) {
        return derivative1(my_sin, multiplier * x) * multiplier * rev;
    } 
    else if (strcmp(trigFunc, "cos") == 0){
        return derivative1(my_cos, multiplier * x) * multiplier * rev;
    }
    else if (strcmp(trigFunc, "tan") == 0) {
        return derivative1(my_tan, multiplier * x) * multiplier * rev;
    }
    return 0;
}


double calculate2(char* func, double x) {
    double a;
    int n;
    // Sử dụng sscanf để phân tách chuỗi
    sscanf(func, "%lfx^%d", &a, &n);
    return a * n * pow(x,n-1);
}

double PTDT1(char* func, double x) {
    char trigFunc[4];
    double multiplier;
    int rev; 
    // Sử dụng sscanf để phân tách chuỗi
    sscanf(func, "%d%3s%lf",&rev, trigFunc, &multiplier);

    if (strcmp(trigFunc, "sin") == 0) {
        return my_sin(x * multiplier) * rev;
    } 
    else if (strcmp(trigFunc, "cos") == 0){
        return my_cos(x * multiplier) * rev;
    }
    else if (strcmp(trigFunc, "tan") == 0) {
        return my_tan(x * multiplier) * rev;
    }
    return 0;
}

double PTDT2(char* func, double x) {
    double a;
    int n;
    // Sử dụng sscanf để phân tách chuỗi
    sscanf(func, "%lfx^%d", &a, &n);
    return a * pow(x,n); 
}

double calculate_expression4(char* str3, double x) {
    double result = 0;
    // Sử dụng strtok để tách chuỗi
    char *token = strtok(str3, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            token = strtok(NULL, " ");
            result += PTDT2(token, x);
        } 
        else if (strcmp(token, "-") == 0) {
            token = strtok(NULL, " ");
            result -= PTDT2(token, x);
        } 
        else if (strcmp(token, "*") == 0) {
            token = strtok(NULL, " ");
            result *= PTDT2(token, x);
        }
        else if (strcmp(token, "/") == 0) {
            token = strtok(NULL, " ");
            result /= PTDT2(token, x);
        }
        else {
            result += PTDT2(token, x);
        }
        token = strtok(NULL, " ");
    }
    return result;
}

double calculate_expression3(char* str2, double x) {
    double result = 0;
    // Sử dụng strtok để tách chuỗi
    char *token = strtok(str2, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            token = strtok(NULL, " ");
            result += PTDT1(token, x);
        } 
        else if (strcmp(token, "-") == 0) {
            token = strtok(NULL, " ");
            result -= PTDT1(token, x);
        } 
        else if (strcmp(token, "*") == 0) {
            token = strtok(NULL, " ");
            result *= PTDT1(token, x);
        }
        else if (strcmp(token, "/") == 0) {
            token = strtok(NULL, " ");
            result /= PTDT1(token, x);
        }
        else {
            result += PTDT1(token, x);
        }
        token = strtok(NULL, " ");
    }
    return result;
}


double calculate_expression1(char* str, double x) {
    double result = 0;
    // Sử dụng strtok để tách chuỗi
    char *token = strtok(str, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            token = strtok(NULL, " ");
            result += calculate1(token, x);
        } 
        else if (strcmp(token, "-") == 0) {
            token = strtok(NULL, " ");
            result -= calculate1(token, x);
        } 
        else if (strcmp(token, "*") == 0) {
            token = strtok(NULL, " ");
            result *= calculate1(token, x);
        }
        else if (strcmp(token, "/") == 0) {
            token = strtok(NULL, " ");
            result /= calculate1(token, x);
        }
        else {
            result += calculate1(token, x);
        }
        token = strtok(NULL, " ");
    }
    return result;
}

double calculate_expression2(char* str, double x) {
    double result = 0;
    // Sử dụng strtok để tách chuỗi
    char *token = strtok(str, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            token = strtok(NULL, " ");
            result += calculate2(token, x);
        } 
        else if (strcmp(token, "-") == 0) {
            token = strtok(NULL, " ");
            result -= calculate2(token, x);
        } 
        else if (strcmp(token, "*") == 0) {
            token = strtok(NULL, " ");
            result *= calculate2(token, x);
        }
        else if (strcmp(token, "/") == 0) {
            token = strtok(NULL, " ");
            result /= calculate2(token, x);
        }
        else {
            result += calculate2(token, x);
        }
        token = strtok(NULL, " ");
    }
    return result;
}

double logup(char* str, double x) {
    double result = 0;
    char *saveptr1;
    char *token = strtok_r(str, "_", &saveptr1);
    while (token != NULL) {
        if (isdigit(token[0])) {
            // Xử lý hệ số
            double rev = atof(token);
            token = strtok_r(NULL, "_", &saveptr1);
            if (strcmp(token, "log") == 0) {
                // Xử lý log
                token = strtok_r(NULL, "_", &saveptr1);
                double base = atof(token);
                token = strtok_r(NULL, "_", &saveptr1);
                double up = atof(token);
                result += rev * up/(up*x*log(base));
            } else if (strcmp(token, "ln") == 0) {
                // Xử lý ln
                token = strtok_r(NULL, "_", &saveptr1);
                double up = atof(token);
                result += rev*up/(up*x);
            }
            else if (strcmp(token, "e^") == 0) {
                // Xử lý ln
                token = strtok_r(NULL, "_", &saveptr1);
                double up = atof(token);
                result += rev*up*exp(x*up); 
            }
            else if (strcmp(token, "x^") == 0) {
                // Xử lý ln
                token = strtok_r(NULL, "_", &saveptr1);
                double up = atof(token);
                result += rev*up*pow(x,up-1); 
            }
        }
        token = strtok_r(NULL, "_", &saveptr1);
    }
    return result;
}

double logup2(char* str4, double x) {
    double result = 0;
    char *saveptr3;
    char *token = strtok_r(str4, "_", &saveptr3);
    while (token != NULL) {
        if (isdigit(token[0])) {
            // Xử lý hệ số
            double rev = atof(token);
            token = strtok_r(NULL, "_", &saveptr3);
            if (strcmp(token, "log") == 0) {
                // Xử lý log
                token = strtok_r(NULL, "_", &saveptr3);
                double base = atof(token);
                token = strtok_r(NULL, "_", &saveptr3);
                double up = atof(token);
                result += rev * log10(up*x)/log10(base); 
            } else if (strcmp(token, "ln") == 0) {
                // Xử lý ln
                token = strtok_r(NULL, "_", &saveptr3);
                double up = atof(token);
                result += rev* log(up*x); 
            }
            else if (strcmp(token, "e^") == 0) {
                // Xử lý ln
                token = strtok_r(NULL, "_", &saveptr3);
                double up = atof(token);
                result += rev*exp(x*up); 
            }
            else if (strcmp(token, "x^") == 0) {
                // Xử lý ln
                token = strtok_r(NULL, "_", &saveptr3);
                double up = atof(token);
                result += rev*pow(x,up); 
            }
        }
        token = strtok_r(NULL, "_", &saveptr3);
    }
    return result;
}

double calculate_expression5(char* str, double x) {
    double result = 0;
    char *saveptr2;
    char *token = strtok_r(str, " ", &saveptr2);
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            token = strtok_r(NULL, " ", &saveptr2);
            result += logup(token, x);
        } 
        else if (strcmp(token, "-") == 0) {
            token = strtok_r(NULL, " ", &saveptr2);
            result -= logup(token, x);
        } 
        else if (strcmp(token, "*") == 0) {
            token = strtok_r(NULL, " ", &saveptr2);
            result *= logup(token, x);
        }
        else if (strcmp(token, "/") == 0) {
            token = strtok_r(NULL, " ", &saveptr2);
            result /= logup(token, x);
        }
        else {
            result += logup(token, x);
        }
        token = strtok_r(NULL, " ", &saveptr2);
    }
    return result;
}

double calculate_expression6(char* str4, double x) {
    double result = 0;
    char *saveptr3;
    char *token = strtok_r(str4, " ", &saveptr3);
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            token = strtok_r(NULL, " ", &saveptr3);
            result += logup2(token, x);
        } 
        else if (strcmp(token, "-") == 0) {
            token = strtok_r(NULL, " ", &saveptr3);
            result -= logup2(token, x);
        } 
        else if (strcmp(token, "*") == 0) {
            token = strtok_r(NULL, " ", &saveptr3);
            result *= logup2(token, x);
        }
        else if (strcmp(token, "/") == 0) {
            token = strtok_r(NULL, " ", &saveptr3);
            result /= logup2(token, x);
        }
        else {
            result += logup2(token, x);
        }
        token = strtok_r(NULL, " ", &saveptr3);
    }
    return result;
}


int main() {
    int choice;
    double result;
    double y2;
    double y3;
    double y4; 
    printf("\033[1;32mVui Long Nhap Lua Chon Ma Ban Muon\033[0m\n");
    do {
        printf("\033[1;33m1: Ham Luong Giac Dang Sin Cos Tan :\033[0m\n");
        printf("\033[1;33m2: Ham Da Thuc Bac N : \033[0m\n");
        printf("\033[1;33m3: Ham Log Ln E^x : \033[0m\n");
        printf("\033[1;33m**Lua Chon Cua Ban La** : \033[0m\n"); 
        scanf("%d", &choice);
        printf("\033[1;34m0 : Quit\033[0m\n"); 
        char str[50];
        double x;
        switch(choice){
            case 1:
                printf("\033[1;4;34mVui Long Nhap He So X :\033[0m\n"); 
                scanf("%lf", &x); 
                getchar(); 
                printf("\033[1;33m! Dinh Dang Nhap La Nhan Chia truoc Cong Tru Sau !\033[0m\n");
                printf("\033[1;33m! Vui Long Nhap Chuong trinh Theo Dinh Dang VD : 3sin1x + 2sin2x !\033[0m\n");
                printf("\033[1;33mVui Long Nhap Vao Phuong Trinh:\033[0m\n");
                fgets(str, 50, stdin);
                char str2[50]; 
                strcpy(str2,str); 
                result = calculate_expression1(str, x);
                y2 = calculate_expression3(str2,x);
                if(y2 >= 0){
                    printf("\033[1;36mResult : %lf * (x - %.0lf) + %lf\033[0m\n",result,x,y2);
                }
                else 
                printf("\033[1;36mResult : %lf * (x - %.0lf) %lf\033[0m\n",result,x,y2);
                break;
            case 2:
                printf("\033[1;4;34mVui Long Nhap He So X :\033[0m\n");
                scanf("%lf", &x); 
                getchar(); 
                printf("\033[1;33m! Dinh Dang Nhap La Nhan Chia truoc Cong Tru Sau !\033[0m\n");
                printf("\033[1;33m! Vui Long Nhap Chuong trinh Theo Dinh Dang VD : 2x^2 + 3x^1 !\033[0m\n");
                printf("\033[1;33mVui Long Nhap Vao Phuong Trinh:\033[0m\n");
                fgets(str, 50, stdin);
                char str3[50]; 
                strcpy(str3,str); 
                result = calculate_expression2(str, x);
                y3 = calculate_expression4(str3,x);
                if(y3 >= 0){
                    printf("\033[1;36mResult : %lf * (x - %.0lf) + %lf\033[0m\n",result,x,y3);
                }
                else 
                printf("\033[1;36mResult : %lf * (x - %.0lf) %lf\033[0m\n",result,x,y3);
                break;
            case 3:
                printf("\033[1;4;34mVui Long Nhap He So X :\033[0m\n");
                scanf("%lf", &x); 
                getchar(); 
                printf("\033[1;33m! Dinh Dang Nhap La Nhan Chia truoc Cong Tru Sau !\033[0m\n");
                printf("\033[1;33m! Vui Long Nhap Chuong trinh Theo Dinh Dang VD : 2_log_2_20x + 3_ln_3x + 4_e^_2x + 4_x^2 !\033[0m\n");
                printf("\033[1;33mVui Long Nhap Vao Phuong Trinh:\033[0m\n");
                fgets(str, 50, stdin);
                char str4[50]; 
                strcpy(str4,str); 
                result = calculate_expression5(str, x);
                y4 = calculate_expression6(str4,x);
                if(y4 >= 0){
                    printf("\033[1;36mResult : %lf * (x-%.0lf) + %lf\033[0m\n",result,x,y4);
                }
                else 
                printf("\033[1;36mResult : %lf * (x-%.0lf) %lf\033[0m\n",result,x,y4);
                break; 
            default:
                printf("\033[1;31mLua chon khong hop le. Vui long nhap lai.\033[0m\n");
                continue;
        }
    } while(choice != 0);
    return 0;
}
