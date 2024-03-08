#default insertion with random
for m in 10000 25000 50000 100000 #250000 500000 1000000 2500000
do
for n in 10 25 50 
do

mkdir -p default-insertion-random
for i in {1..10}
do
timeout 5m ./hw1 $m $n 0 0 >>default-insertion-random/default-insertion-random-$m-$n.txt
echo 'done with sort'
done
done
done