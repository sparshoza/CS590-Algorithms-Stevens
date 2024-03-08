import re
import os

case1 =[]
m = [50000, 100000, 250000, 500000, 1000000, 2500000, 5000000]

sum1 = 0
final= []
current_directory = os.getcwd()
final_directory = os.path.join(current_directory, 'RBT-inverse-extracted')
if not os.path.exists(final_directory):
   os.makedirs(final_directory)
for i in m:
    filename2 = 'RBT-inverse-'+ str(i) +'.txt'
    with open(filename2) as f:
        lines = f.read()
    x = re.findall(r"\(sort\): (\w+)+ms real",lines)
    case1 = re.findall(r"Case 1: (\d+)",lines)
    case2 = re.findall(r"Case 2: (\d+)",lines)
    case3 = re.findall(r"Case 3: (\d+)",lines)
    Lrotate = re.findall(r"Left Rotate: (\d+)",lines)
    Rrotate = re.findall(r"Right Rotate: (\d+)",lines)
    Duplicates = re.findall(r"Duplicates: (\d+)",lines)
    
    x = list(map(lambda y:int(y),x))
    case1 = list(map(lambda y:int(y),case1))
    case2 = list(map(lambda y:int(y),case2))
    case3 = list(map(lambda y:int(y),case3))
    Lrotate = list(map(lambda y:int(y),Lrotate))
    Rrotate = list(map(lambda y:int(y),Rrotate))
    Duplicates = list(map(lambda y:int(y),Duplicates))
    final.append(sum(x)/len(x))
    final.append(sum(case1)/len(case1))
    final.append(sum(case2)/len(case2))
    final.append(sum(case3)/len(case3))
    final.append(sum(Lrotate)/len(Lrotate))
    final.append(sum(Rrotate)/len(Rrotate))
    final.append(sum(Duplicates)/len(Duplicates))
    
    
    filename = 'RBT-inverse'+ str(i) +'-extracted.txt'
    with open('RBT-inverse-extracted/'+filename, 'w') as z:
        z.write(f'Sort : {final[0]}\n')
        z.write(f'case1 : {final[1]}\n')
        z.write(f'case2 : {final[2]}\n')
        z.write(f'case3 : {final[3]}\n')
        z.write(f'Left rotate : {final[4]}\n')
        z.write(f'Right rotate : {final[5]}\n')
        z.write(f'Duplicates : {final[6]}\n')
    
    final = []