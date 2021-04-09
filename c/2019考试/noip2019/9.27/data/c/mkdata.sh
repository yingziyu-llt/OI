./data 15 >c1.in
time ./c <c1.in >c1.out
cat c1.out
sleep 1
./data 15 >c2.in
time ./c <c2.in >c2.out
cat c2.out
sleep 1
./data 15 >c3.in
time ./c <c3.in >c3.out
cat c3.out
sleep 1
./data 10000 >c4.in
time ./c <c4.in >c4.out
cat c4.out
sleep 1
./data 10000 >c5.in
time ./c <c5.in >c5.out
cat c5.out
sleep 1
./data 10000 >c6.in
time ./c <c6.in >c6.out
cat c6.out
sleep 1
./data 10000 >c7.in
time ./c <c7.in >c7.out
cat c7.out
sleep 1
./data 10000 >c8.in
time ./c <c8.in >c8.out
cat c8.out
sleep 1
./data 10000 >c9.in
time ./c <c9.in >c9.out
cat c9.out
sleep 1
./data 10000 >c10.in
time ./c <c10.in >c10.out
cat c10.out
