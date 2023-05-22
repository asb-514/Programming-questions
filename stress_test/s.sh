    g++-12 -o gen gen.cpp
    g++-12 -o a e.cpp
    g++-12 -o brute brute_force.cpp

for((i = 2; ; ++i)); do
    echo $i
     ./gen $i > int
     ./a < int >  out1
     ./brute < int > out2
     diff -w out1 out2 || break
     # diff -w <(./a < int) <(./brute < int) || break
done
