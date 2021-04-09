./data 10 10 >b1.in
time ./b <b1.in >b1.out
cat b1.out
sleep 1
./data 10 10 >b2.in
time ./b <b2.in >b2.out
cat b2.out
sleep 1
./data 10 1000 >b3.in
time ./b <b3.in >b3.out
cat b3.out
sleep 1
./data 10 1000 >b4.in
time ./b <b4.in >b4.out
cat b4.out
sleep 1
./data 10 1000 >b5.in
time ./b <b5.in >b5.out
cat b5.out
sleep 1
./data 100 100000 >b6.in
time ./b <b6.in >b6.out
cat b6.out
sleep 1
./data 100 100000 >b7.in
time ./b <b7.in >b7.out
cat b7.out
sleep 1
./data 100 100000 >b8.in
time ./b <b8.in >b8.out
cat b8.out
sleep 1
./data 100 100000 >b9.in
time ./b <b9.in >b9.out
cat b9.out
sleep 1
./data 100 100000 >b10.in
time ./b <b10.in >b10.out
cat b10.out
