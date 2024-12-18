set -e
g++ p.cpp -o e
g++ gen.cpp -o gen
for((i = 10; ; ++i)); do
    ./gen $i > in
    ./e < in
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat in
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer