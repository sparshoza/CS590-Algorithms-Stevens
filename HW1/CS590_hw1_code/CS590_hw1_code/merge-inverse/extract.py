import re
import os

list1 =[]
m = [10000, 25000, 50000, 100000, 250000, 500000, 1000000, 2500000]
n = [10,25,50]

sum = 0
current_directory = os.getcwd()
final_directory = os.path.join(current_directory, 'merge-inverse-extracted')
if not os.path.exists(final_directory):
   os.makedirs(final_directory)
for i in m:
    for j in n:
        filename2 = 'merge-inverse-'+ str(i) +'-'+ str(j) + '.txt'
        with open(filename2) as f:
            lines = f.readlines()
        for k in lines:
            x = re.search(r"\(sort\): (\w+)+ms real",k)
            if x!=None:
                list1.append(x.group(1))
        for l in list1:
            sum = sum + int(l)
        avg = sum/len(list1)

        filename = 'merge-inverse-'+ str(i) +'-'+ str(j) +'-extracted.txt'
        with open('merge-inverse-extracted/'+filename, 'w') as z:
            for p in list1:
                z.write(p)
                z.write('\n')
            z.write(str(avg))
        sum = 0
        list1 = []