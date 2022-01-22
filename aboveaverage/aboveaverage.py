import sys

def aboveaverage():

    passedFirst = False

    for line in sys.stdin:
        if not passedFirst:
            passedFirst = True
            continue
        else:
            classData = line.split(" ")
            numStudents = int(classData[0])

            grades = [int(grade) for grade in classData[1:]]
            #grades = list(map(int,classData))

            total = sum(grades)
            
            avg = total/numStudents

            # Could use a binary search for this if I sorted the grades list

            numAboveAvg = 0

            for i in grades:
                if i > avg: numAboveAvg = numAboveAvg + 1

            print("%.3f" % (numAboveAvg / numStudents * 100) + "%")
            

aboveaverage()
