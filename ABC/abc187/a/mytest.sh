for i in 1 2 3
do
echo ====[sample$i]=====
echo output:
./a.out < ./test/sample-$i.in
echo ans:
cat ./test/sample-$i.out
echo ==================
done
