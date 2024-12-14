def assignBikes(students, bikes):
    pq = []
    for i in range(len(students)):
        for j in range(len(bikes)):
            distance = abs(students[i][0] - bikes[j][0]) + abs(students[i][1] - bikes[j][1])
            pq.append([distance, i, j])  

    pq.sort(key=lambda x: (x[0], x[1], x[2]))

    assigned_students = [False] * len(students)
    assigned_bikes = [False] * len(bikes)

    result = [-1] * len(students)

    for entry in pq:
        distance, student_idx, bike_idx = entry

        if not assigned_students[student_idx] and not assigned_bikes[bike_idx]:
            result[student_idx] = bike_idx
            assigned_students[student_idx] = True  
            assigned_bikes[bike_idx] = True  
    return result

students = [[0, 0], [1, 1]]
bikes = [[0, 1], [4, 3], [2, 1]]

result = assignBikes(students, bikes)
print(result) 