#improved insertion sort with sorted
for n in 50000 100000 250000 500000 1000000 2500000 5000000
do
mkdir -p RBT-sorted
for i in {1..10}
do
./hw3 $n 1 1 >>RBT-sorted/RBT-sorted-$n.txt
echo 'done with sort'
done
done




