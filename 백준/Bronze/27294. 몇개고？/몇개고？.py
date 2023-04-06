a, b = map(int, input().split())

is_lunch = 12<=a and a<=16

if(b or (not is_lunch)):
    print("280")
else:
    print("320")
