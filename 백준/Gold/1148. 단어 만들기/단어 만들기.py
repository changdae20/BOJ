words = []
puzzles = []

word = input()

while word!="-":
    words.append(word)
    word = input()

puzzle = input()

while puzzle!="#":
    puzzles.append(puzzle)
    puzzle = input()



for i in range(0,len(puzzles)): # puzzles[i] : i번째 퍼즐
    ans = {}
    for j in range(0,len(puzzles[i])): # j번째 문자가 중간에 오는 문자가 됨
        if puzzles[i][j] not in ans.keys():
            is_break = False
            count = 0
            for k in range(0,len(words)): # word마다 조건 만족하는지 계산
                puzzle = list(puzzles[i])
                word = list(words[k])
                try:
                    word.remove(puzzle[j])
                    del puzzle[j]
                    while len(word)>0:
                        puzzle.remove(word[0])
                        del word[0]
                    #print(puzzles[i],"가운데 문자 : ",puzzles[i][j],"word : ",words[k])
                    count += 1
                except ValueError:
                    pass
            ans[puzzles[i][j]] = count
    ans = sorted(ans.items(), key = (lambda x:x[1]))
    min_val = ans[0][1]
    min = []
    for j in range(0,len(ans)):
        if(ans[j][1]==min_val): min.append(ans[j][0])
        else:break
    max_val = ans[len(ans)-1][1]
    max = []
    for j in range(len(ans)-1,-1,-1):
        if(ans[j][1]==max_val): max.append(ans[j][0])
        else:break
    min.sort()
    max.sort()
    
    print(''.join(min),min_val,''.join(max),max_val)
            
        