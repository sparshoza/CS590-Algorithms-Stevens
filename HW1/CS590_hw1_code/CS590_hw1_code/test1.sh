#default insertion with sorted
for n in 10 25 50
do
for m in 10000 25000 50000 100000 250000 500000 1000000 2500000
do
mkdir -p default-insertion-sorted
for i in {1..10}
do
timeout 5m ./hw1 $m $n 0 1 >>default-insertion-sorted/default-insertion-sorted-$m-$n.txt
echo 'done with sort'
done
done
done