def find_min_number(n):
    dp = [ [None]*11 for _ in range(n+1) ]  # dp[pos][mod11] = minimal number as string
    dp[0][0] = ''
    digits = ['3','6']

    for pos in range(1, n+1):
        for d in range(11):
            if dp[pos-1][d] is not None:
                for x in digits:
                    if pos == n and x != '6':
                        continue  # Last digit must be '6'
                    if pos % 2 == 1:  # odd position
                        new_d = (d + int(x)) % 11
                    else:
                        new_d = (d - int(x) + 11) %11
                    potential_num = dp[pos -1][d] + x
                    if dp[pos][new_d] is None or potential_num < dp[pos][new_d]:
                        dp[pos][new_d] = potential_num

    if dp[n][0]:
        return dp[n][0]
    else:
        return "-1"

# Read input for n
n = int(input())
for _ in range(n):
	a = int(input())
	result = find_min_number(a)
	print(result)