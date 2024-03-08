# merge sort with inverse
for n in 10 25 50 
do
for m in 10000 25000 50000 100000 250000 500000 1000000 2500000
do
mkdir -p merge-inverse
for i in {1..10}
do
timeout 5m ./hw1 $m $n 1 -1 >>merge-inverse/merge-inverse-$m-$n.txt
echo 'done with sort' $m $n
done
done
done



