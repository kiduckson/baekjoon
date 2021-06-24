#include <stdio.h>
int N, cnt = 0;
int visit[50], visit1[50], visit2[50];
void func(int k) {
  if(k == N) {
    cnt++;
    return;
  }
  for(int i = 0; i < N; i++) {
    if(visit[i] || visit1[i + k] || visit2[k - i + N - 1])
      continue;
    visit[i] = 1;
    visit1[i + k] = 1;
    visit2[k - i + N - 1] = 1;
    func(k + 1);
    visit[i] = 0;
    visit1[i + k] = 0;
    visit2[k - i + N - 1] = 0;
  }
}
int main() {
  N = 6;
  func(0);
  printf("%d\n", cnt);
  return 0;
}
