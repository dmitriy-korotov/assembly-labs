for (( a = 1; a < 10000; a++ ))
do
echo "Что-то в падлу компилить..."
done
exit
gcc task3.s -lm
./a.out