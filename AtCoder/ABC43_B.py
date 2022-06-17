s = input()
final_str = ""
backspace_cnt = 0

for i in range(len(s) - 1, -1, -1):
    if s[i] == 'B':
        backspace_cnt += 1
    else:
        if backspace_cnt == 0:
            final_str = s[i] + final_str
        else:
            backspace_cnt -= 1

print(final_str)
