#improved insertion with inverse
for m in 500000 #1000000 2500000
do
for n in 50 
do

mkdir -p improved-insertion-inverse
for i in {1..5}
do
timeout 5m ./hw1 $m $n -1 -1 >>improved-insertion-inverse/improved-insertion-inverse-$m-$n.txt
echo 'done with sort' $m $n
done
done
done