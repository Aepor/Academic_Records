k = {}
k['Katte'] = 3
k['Kathy'] = 4
k['Lette'] = 5
k['Evan'] = 1
k["John"] = 5
print(k)
del(k['Lette'])
k['Lette'] = 4
print(k)

k.update({   # 기존 key가 똑같은 이름으로 있다면 덮어씀, 순서는 안바뀜 John이 먼저 존재했기 때문
    "John" : 3,
    "Turing" : 4
})
print(k)


names = ["Denise", "Katy", "John", "Ana"]
scores = ["A", "A", "A+", "B"]

grades = dict(zip(names, scores)) #zip()을 이용한 합성도 가능

print(grades)

users = {  #이중 dictionary를 활용한 유저정보 저장
    "user001": {"name": "Kim", "level": 10},
    "user002": {"name": "Lee", "level": 20}
}

print(users["user002"]["level"])