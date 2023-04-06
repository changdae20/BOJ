def LCS(X_,Y_):
    LCS_array = [[0]*(len(Y_)+1) for x in range(len(X_)+1)]
    for x_idx in range(len(X_)+1):
        for y_idx in range(len(Y_)+1):
            if x_idx==0 or y_idx==0:
                LCS_array[x_idx][y_idx]=0
            elif X_[x_idx-1]==Y_[y_idx-1]:
                LCS_array[x_idx][y_idx] = LCS_array[x_idx-1][y_idx-1]+1
            else:
                LCS_array[x_idx][y_idx] = max(LCS_array[x_idx-1][y_idx],LCS_array[x_idx][y_idx-1])

    return LCS_array[len(X_)][len(Y_)]

a = input()
b = input()
print(LCS(a,b))