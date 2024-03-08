import re
import os

list1 =[]
m = [5000000]

sum1 = 0
final = []
current_directory = os.getcwd()
final_directory = os.path.join(current_directory, 'BST-random-extracted')
if not os.path.exists(final_directory):
   os.makedirs(final_directory)
for i in m:
    filename2 = 'BST-random-'+ str(i) +'.txt'
    with open(filename2) as f:
        lines = f.read()
    x = re.findall(r"\(sort\): (\w+)+ms real",lines)
    Duplicates = re.findall(r"Duplicates: (\d+)",lines)
    
    x = list(map(lambda y:int(y),x))
    Duplicates = list(map(lambda y:int(y),Duplicates))
    final.append(sum(x)/len(x))
    final.append(sum(Duplicates)/len(Duplicates))
    
    
    filename = 'BST-random'+ str(i) +'-extracted.txt'
    with open('BST-random-extracted/'+filename, 'w') as z:
        z.write(f'Sort : {final[0]}\n')
        z.write(f'Duplicates : {final[1]}\n')
    
    final = []