set -e
g++ k.cpp -o e
g++ gen.cpp -o gen
g++ p.cpp -o ch
for((i = 100; ; ++i)); do
    ./gen $i > in
    ./e < in > myAnswer
    ./ch < in > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat in
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer