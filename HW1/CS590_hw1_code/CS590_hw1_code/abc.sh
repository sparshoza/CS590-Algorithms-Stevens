int m = [1000 2500 5000 10000 25000 50000 100000 250000]
int n = 10 25 50
improved = -1
default = 0
random = 0
sorted = 1
inverse = -1

for 
./hw1 1000 10 -1 0 >>improvedinserstion-sort-mode.txt

for n in 10 25 50 
do
for m in 1000 #2500 5000 10000 25000 50000 100000 250000
do
./hw1 m n -1 1
done
done