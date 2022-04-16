

def mapping(arr):
    a = arr.split(" ")
    return [a[0],a[1].strip()]

f = open("note.txt","r")
a = f.readlines()
result = map(mapping,a)
result = list(result)

print(result)
score = 0
for i in range(len(result)):
    # print(type(int(result[i][1])))
    score += int(result[i][1])*((int(result[i][0][:-1]))/100)*0.9375
    # print(score)

mid_score = (200/300)*20
final_score = (230/300)*20

print(f'midterm = {mid_score}/20\nfinal = {final_score}/20\nhomework = {score}/60\ntotal = {mid_score + final_score + score}')
    