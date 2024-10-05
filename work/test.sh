set -e
g++ b.cpp -o e
g++ gen.cpp -o gen
g++ checker.cpp -o checker
for((i = 5; ; ++i)); do
    ./gen $i > in
    ./e < in > myAnswer
    ./checker < in > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat in
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer