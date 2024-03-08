#default insertion with inverse
for m in 100000 #250000 500000 1000000 2500000
do
for n in 25
do
mkdir -p default-insertion-inverse
for i in {1..10}
do
timeout 5m ./hw1 $m $n 0 -1 >>default-insertion-inverse/default-insertion-inverse-$m-$n.txt
echo 'done with sort' $m
done
done
done