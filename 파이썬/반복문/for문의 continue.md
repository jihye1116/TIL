```
marks = [90, 25, 67, 45, 80]
number = 0
for mark in marks:
	number = number +1
	if mark < 60: 
		continue
	print(f"{number}학생 축하*합니다. {mark}점으로 합격입니다.")
```
출력 :
1학생 축하합니다. 90점으로 합격입니다.
3학생 축하합니다. 67점으로 합격입니다.
5학생 축하합니다. 80점으로 합격입니다.