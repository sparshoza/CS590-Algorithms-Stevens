import re
import os

list1 =[]
m = [50000, 100000, 250000]
# 500000, 1000000, 2500000]

sum1 = 0
final = []
current_directory = os.getcwd()
final_directory = os.path.join(current_directory, 'BST-sorted-extracted')
if not os.path.exists(final_directory):
   os.makedirs(final_directory)
for i in m:
    filename2 = 'BST-sorted-'+ str(i) +'.txt'
    with open(filename2) as f:
        lines = f.read()
    x = re.findall(r"\(sort\): (\w+)+ms real",lines)
    Duplicates = re.findall(r"Duplicates: (\d+)",lines)
    
    x = list(map(lambda y:int(y),x))
    Duplicates = list(map(lambda y:int(y),Duplicates))
    final.append(sum(x)/len(x))
    final.append(sum(Duplicates)/len(Duplicates))
    
    
    filename = 'BST-sorted'+ str(i) +'-extracted.txt'
    with open('BST-sorted-extracted/'+filename, 'w') as z:
        z.write(f'Sort : {final[0]}\n')
        z.write(f'Duplicates : {final[1]}\n')
    
    final = []