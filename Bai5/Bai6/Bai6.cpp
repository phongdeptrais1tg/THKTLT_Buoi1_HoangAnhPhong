#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define CURRENT_YEAR 2021

void throw_error(int errcode) {
    printf("Error: %d\n", errcode);
}

void throw_error_str(const char* errcode) {
    printf("Error: %s\n", errcode);
}

int main() {
    char name[100];
    int day, month, year;
    char gender[10];

    // Nhập họ tên
    printf("Nhap ho ten: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Loại bỏ ký tự newline

    // Nhập ngày sinh
    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    if (scanf_s("%d/%d/%d", &day, &month, &year) != 3) {
        throw_error_str("Sai dinh dang ngay sinh.");
        return 1;
    }

    // Nhập giới tính
    printf("Nhap gioi tinh (nam/nu): ");
    scanf_s("%s", gender);

    // Chuyển đổi giới tính thành chữ thường để kiểm tra dễ dàng hơn
    for (int i = 0; gender[i]; i++) {
        gender[i] = tolower(gender[i]);
    }

    // Tính tuổi hiện tại
    int age = CURRENT_YEAR - year;

    // Kiểm tra tuổi có nằm trong khoảng tuổi lao động hay không
    if (age < 18 || (strcmp(gender, "nam") == 0 && age > 62) || (strcmp(gender, "nu") == 0 && age > 60)) {
        throw_error(101);
        return 1; // Kết thúc chương trình với mã lỗi 1
    }

    // Kiểm tra giới tính có hợp lệ hay không
    if (strcmp(gender, "nam") != 0 && strcmp(gender, "nu") != 0) {
        throw_error_str("errcode");
        return 1; // Kết thúc chương trình với mã lỗi 1
    }

    // Tính năm nghỉ hưu
    int retirement_age = (strcmp(gender, "nam") == 0) ? 62 : 60;
    int retirement_year = year + retirement_age;

    // In kết quả
    printf("%s, gioi tinh %s, sinh ngay %02d/%02d/%d. ", name, gender, day, month, year);
    printf("Hien tai (nam %d) %s da %d tuoi. ", CURRENT_YEAR, name, age);
    printf("Thoi gian %s duoc nghi huu la thang %02d/%d.\n", name, month, retirement_year);

    return 0; // Kết thúc chương trình thành công
}
