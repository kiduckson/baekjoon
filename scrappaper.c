n = 2;
m = 2;



// ###################################
// ###################################
// TODO 1번째 실행때
dst(엘리먼트 인덱스 및 카운트=0);

// ! 시작할떄
vst = {0, 0, 0, 0, 0, 0, 0, 0, 0} // 간지 안간지
rst = {0, 0, 0, 0, 0, 0, 0, 0, 0} // 실제 정답

for (int i = 1; i <= n; i++){ // 1 2를 룹쓰루
	if(vst[1] == 0)
		vst[1] = true // 여기서 간거 표시
		rst[인덱스(0임)] = 1 // 안갔던거니까 처번쨰거에 1넣음
		dsf(인덱스 + 1) // 여기서
}

// ###################################
// ###################################
// TODO 2번째 실행때
dst(엘리먼트 인덱스 및 카운트=1);

// ! 시작할떄
vst = {0, 1, 0, 0, 0, 0, 0, 0, 0} // 간지 안간지
rst = {1, 0, 0, 0, 0, 0, 0, 0, 0} // 실제 정답

// 이번에는 i -> 2
for (int i = 1; i <= n; i++){ // 1 2를 룹쓰루
	if(vst[1] == 0) false
	if(vst[2] == 0) true
		vst[2] = true // 여기서 간거 표시
		rst[인덱스(1임)] = 2
		dsf(인덱스 + 1) // 여기서
}