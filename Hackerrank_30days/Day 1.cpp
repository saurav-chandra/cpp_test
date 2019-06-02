// IN c

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    int x;
    double y;
    char z[200];
    scanf("%d",&x);
    scanf("%lf ",&y);
    scanf("%[^\n]",z);
    printf("%d\n",i+x);
    printf("%.1lf\n",d+y);
    printf("%s%s",s,z);
    return 0;
}