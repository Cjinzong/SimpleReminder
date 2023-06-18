#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void remind(int hours, int minutes) {
    time_t now;
    struct tm *currentTime;
    time(&now);
    currentTime = localtime(&now);

    int currentHour = currentTime->tm_hour;
    int currentMinute = currentTime->tm_min;

    int remainingSeconds = ((hours * 60 + minutes) - (currentHour * 60 + currentMinute)) * 60;

    printf("定时提醒设置成功！将在 %d 小时 %d 分钟后提醒。\n", hours, minutes);

    sleep(remainingSeconds);

    printf("时间到！请注意您的提醒事项。\n");
}

int main() {
    int hours, minutes;

    printf("欢迎使用定时提醒程序！\n");

    printf("请输入提醒的小时数：");
    scanf("%d", &hours);

    printf("请输入提醒的分钟数：");
    scanf("%d", &minutes);

    remind(hours, minutes);

    return 0;
}
