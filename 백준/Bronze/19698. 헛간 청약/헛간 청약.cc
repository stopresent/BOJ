#include <stdio.h>
int main() {
    int n, w, h, l;
    scanf("%d %d %d %d", &n, &w, &h, &l);
    int ans = (w / l) * (h / l);
    printf("%d", n < ans ? n : ans);
    return 0;
}