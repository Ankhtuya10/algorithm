def assignBikes(students, bikes):
    # Priority queue-ийг зай, оюутан болон дугуйны индексуудыг хадгалахын тулд ашиглана
    pq = []

    # Бүх оюутан болон дугуйны хоорондын Манхэттений зайг тооцоолно
    for i in range(len(students)):
        for j in range(len(bikes)):
            # Манхэттений зай тооцоолох (зай = |x1 - x2| + |y1 - y2|)
            distance = abs(students[i][0] - bikes[j][0]) + abs(students[i][1] - bikes[j][1])
            pq.append([distance, i, j])  # Зай, оюутан индекс, дугуй индексийг хадгална

    # Priority queue-г зай, оюутан индекс болон дугуй индексээр эрэмбэлнэ
    # Тиймээс эхлээд зайгаар, дараа нь оюутан болон дугуйн индексуудыг харьцуулж эрэмбэлнэ
    pq.sort(key=lambda x: (x[0], x[1], x[2]))

    # Оюутан болон дугуй хуваарилагдсан эсэхийг хянах массив
    assigned_students = [False] * len(students)
    assigned_bikes = [False] * len(bikes)

    # Дугуй хуваарилалтын үр дүнг хадгалах массив
    result = [-1] * len(students)

    # Priority queue-г боловсруулна
    for entry in pq:
        distance, student_idx, bike_idx = entry

        # Хэрэв оюутан болон дугуй аль аль нь хуваарилагдаагүй бол
        # дугуйг оюутанд хуваарилна
        if not assigned_students[student_idx] and not assigned_bikes[bike_idx]:
            result[student_idx] = bike_idx
            assigned_students[student_idx] = True  # Оюутан хуваарилагдсан гэж тэмдэглэнэ
            assigned_bikes[bike_idx] = True  # Дугуй хуваарилагдсан гэж тэмдэглэнэ

    # Хуваарилалтыг буцаана
    return result

# Жишээ ашиглалт:
students = [[0, 0], [1, 1]]
bikes = [[0, 1], [4, 3], [2, 1]]

result = assignBikes(students, bikes)
print(result)  # Гаралт: [0, 2]
