from StudentRecord import StudentRecord
import sys

val = sys.argv[ len(sys.argv) - 1]

def main() :
    with open(val, "r") as ins:
         array = []
         m=0
         sum=0
         for line in ins:
             student = StudentRecord()
             student.input(line)
             array.append(student)
             m=m+1
             sum = sum + student.score()
    
    average = sum/m
    print 'The average is', average         



if __name__ == "__main__" :
    main()
