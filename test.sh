quiet=0
check=0
sred=0

if [ "$#" -lt 3 ] || [ "$#" -gt 4 ]
then
	printf "\nusage: test.sh [-full] arg1 arg2 arg3\n"
	printf "       arg1  - start number (random value from .. ).\n"
	printf "       arg2  - finish number ( .. random value to).\n"
	printf "       arg3  - how many times run a test.\n"
	printf "       -full - push_swap tests, checker tests, leaks tests, author file test.\n\n"

	exit
fi

if [ "$1" = "-full" ]
then
    check=1
    from=$2
    to=$3
    count=$4
else
    from=$1
    to=$2
    count=$3
fi

let "dif = $to - $from + 1"

i=0
sp=( Loading. lOading.. loAding... loaDing.... loadIng..... loadiNg...... loadinG....... DONE)
echo ' '
for i in "${sp[@]}\n"
do
    printf "\r\t\t\t\t\033[K\033[32m$i\033[m"
    sleep 0.2
done


if [ $check -eq 1 ]
then
printf "\n\t\t\t 🤹🏻‍♀️  CHECKER TEST 🤹🏻‍♀️\n"
printf "\t\t\t -------------------\n"
printf "Error management:\n"
printf "test 1: "
if [ "$(printf '' | ./checker kek 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (non numeric parameter) (instr: none)"
else
echo "KO  - ./checker (non numeric parameter) (instr: none)"
fi
printf "test 2: "
if [ "$(printf '' | ./checker 1 2 3 4 5 6 7 8 1 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (duplicate numeric parameter) (instr: none)"
else
echo "KO  - ./checker (duplicate numeric parameter) (instr: none)"
fi
printf "test 3: "
if [ "$(printf '' | ./checker 2147483648 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker MAX_INT+1(2147483648) (instr: none)"
else
echo "KO  - ./checker MAX_INT+1(2147483648) (instr: none)"
fi
printf "test 4: "
if [ "$(printf '' | ./checker -2147483649 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker MIN_INT-1(2147483649) (instr: none)"
else
echo "KO  - ./checker MIN_INT-1(2147483649) (instr: none)"
fi
printf "test 5: "
if [ "$(printf '' | ./checker | wc -l)" -eq 0 ]
then
echo "OK  - ./checker none (instr: none)"
else
echo "KO  - ./checker none (instr: none)"
fi
printf "test 6: "
if [ "$(printf 'kek\n' | ./checker 4 1 2 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (action doesn't exist) (instr: none)"
else
echo "KO  - ./checker (action doesn't exist) (instr: none)"
fi
printf "test 7: "
if [ "$(printf 'ra  \n' | ./checker 4 1 2 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (action with two space after) (instr: none)"
else
echo "KO  - ./checker (action with two space after) (instr: none)"
fi
printf "test 8: "
if [ "$(printf '  ra\n' | ./checker 4 1 2 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (action with two space before) (instr: none)"
else
echo "KO  - ./checker (action with two space before) (instr: none)"
fi
printf "test 9: "
if [ "$(printf '\n' | ./checker - 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (only minus sign as parameter) (instr: none)"
else
echo "KO  - ./checker (only minus sign as parameter) (instr: none)"
fi
printf "test 10: "
if [ "$(printf '\n' | ./checker + 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (only plus sign as parameter) (instr: none)"
else
echo "KO  - ./checker (only plus sign as parameter) (instr: none)"
fi
printf "test 11: "
if [ "$(printf '\n' | ./checker -0 0 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (duplicate zeros) (instr: none)"
else
echo "KO  - ./checker (duplicate zeros) (instr: none)"
fi
printf "test 12: "
if [ "$(printf '\n' | ./checker 18446744073709551616 2>&1 | grep "Error" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker (int64_t double overloaded (to zero)) (instr: none)"
else
echo "KO  - ./checker (int64_t double overloaded (to zero)) (instr: none)"
fi

printf "\nFalse tests:\n"
printf "test 1: "
if [ "$(printf "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5  | grep "KO" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker 0 9 1 8 2 7 3 6 4 5 (instr: sa pb rrr)"
else
echo "KO  - ./checker 0 9 1 8 2 7 3 6 4 5 (instr: sa pb rrr)"
fi
printf "test 2: "
if [ "$(printf "pb\nra\nsa\npa\nrb\nrrb\nrra\n" | ./checker 4 1 6 2 7 3 | grep "KO" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker 4 1 6 2 7 3 (instr: pb ra sa pa rb rrb rra)"
else
echo "KO  - ./checker 4 1 6 2 7 3 (instr: pb ra sa pa rb rrb rra)"
fi

printf "\nRight tests:\n"
printf "test 1: "
if [ "$(printf '' | ./checker 0 1 2 | grep "OK" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker 0 1 2 (instr: none)"
else
echo "KO  - ./checker 0 1 2 (instr: none)"
fi
printf "test 2: "
if [ "$(printf "pb\nra\npb\nra\nsa\nra\npa\npa\n" | ./checker 0 9 1 8 2 | grep "OK" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker 0 9 1 8 2 (instr: pb ra pb ra sa ra pa pa)"
else
echo "KO  - ./checker 0 9 1 8 2 (instr: pb ra pb ra sa ra pa pa)"
fi

printf "\nRandom tests:\n"
printf "test 1: "
if [ "$(printf "pb\npb\n" | ./checker 1 2 3 4 5 | grep "KO" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker 1 2 3 4 5 (instr: pb pb)"
else
echo "KO  - ./checker 1 2 3 4 5 (instr: pb pb)"
fi
printf "test 2: "
if [ "$(printf "ra\nra\nrra\nrra\n" | ./checker 1 2 3 4 5 | grep "OK" | wc -l)" -eq 1 ]
then
echo "OK  - ./checker 1 2 3 4 5 (instr: ra ra rra rra)"
else
echo "KO  - ./checker 1 2 3 4 5 (instr: ra ra rra rra)"
fi

printf "\n\t\t\t 🤹🏻‍♀️  PUSH_SWAP TEST 🤹🏻‍♀️\n"
    printf "\t\t         --------------------\n"
echo "Identity test:"
printf "test 1: "
if [ "$(./push_swap 42 | wc -l)" -eq 0 ]
then
echo "OK  - ./push_swap 42 (should display nothing)"
else
echo "KO  - ./push_swap 42 (should display nothing)"
fi
printf "test 2: "
if [ "$(./push_swap 0 1 2 3 | wc -l)" -eq 0 ]
then
echo "OK  - ./push_swap 0 1 2 3 (should display nothing)"
else
echo "KO  - ./push_swap 0 1 2 3 (should display nothing)"
fi
printf "test 3: "
if [ "$(./push_swap 0 1 2 3 4 5 6 7 8 9 | wc -l)" -eq 0 ]
then
printf "OK  - ./push_swap 0 1 2 3 4 5 6 7 8 9 (should display nothing)\n"
else
printf "KO  - ./push_swap 0 1 2 3 4 5 6 7 8 9 (should display nothing)\n"
fi
fi

if [ $check -eq 1 ]
then
	printf "\n\t\t       🤹🏻‍♀️  PUSH_SWAP LEAK TEST 🤹🏻‍♀️\n"
    printf "\t\t       -------------------------\n"
	ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"`
	leak=$(valgrind ./push_swap $ARG 2>&1 | grep "definitely lost" | cut -d ':' -f2 | cut -d ' ' -f2 | sed 's/,//' | wc -l)
    heap=$(valgrind ./push_swap $ARG 2>&1 | grep "heap usage" | cut -d ':' -f2 | cut -d ' ' -f2 | sed 's/,//'| wc -l)

	if [ "$heap" -gt 0 ]
	then
	   if [ "$leak" -gt 0 ]
	   then
            printf "Leaks: \033[31m$leak\033[m byte(s)   KO   \033[33mUse: valgrind --leak-check=full ./push_swap <VALUES> to find all!\033[m\n"
	   else
	       printf "Leaks: \033[32m0\033[m bytes   Ok\n"
	   fi
	else 
	   printf "Leaks: \033[31mvalgrind is unable, check your Makefile or SDL/MLX compilers, or run it as a Daemon.\033[m    ⚠️"
	fi
	/bin/rm -rf push_swap.dSYM
fi

printf "\n💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠"
printf "\n\t\t\t 🤹🏻‍♀️  RANDOM VALUES TEST 🤹🏻‍♀️ \n"

let "max = 0"
let "min = 1500000000"
for ((i = 0; i < $count; i++))
do
ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"` ;res=$(./push_swap $ARG | wc -l)
trie=$(./push_swap $ARG | ./checker_linux $ARG)
printf "sorted = $trie\n"
if [ $res -gt $max ]
then
    let "max = $res"
fi
if [ $res -lt $min ]
then
    let "min = $res"
fi
if [ $dif -eq 100 ]
then
    if [ $res -gt 1500 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   0️⃣  ❕  5️⃣  ❗️\n"
        let "sred += $res"
    elif [ $res -gt 1300 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   1️⃣  ❕  5️⃣     OK\n"
        let "sred += $res"
    elif [ $res -gt 1100 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   2️⃣  ❕  5️⃣     OK  OK\n"
        let "sred += $res"
    elif [ $res -gt 900 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   3️⃣  ❕  5️⃣     OK  OK  OK\n"
        let "sred += $res"
    elif [ $res -gt 700 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   4️⃣  ❕  5️⃣     OK  OK  OK  OK\n"
        let "sred += $res"
    elif [ $res -gt 0 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   5️⃣  ❕  5️⃣     OK  OK  OK  OK  OK\n"
        let "sred += $res"
    fi
    elif [ $dif -eq 500 ]
    then
        if [ $res -gt 11500 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   0️⃣  ❕  5️⃣  ❗️\n"
        let "sred += $res"
    elif [ $res -gt 10000 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   1️⃣  ❕  5️⃣     OK\n"
        let "sred += $res"
    elif [ $res -gt 8500 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   2️⃣  ❕  5️⃣     OK  OK\n"
        let "sred += $res"
    elif [ $res -gt 7000 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   3️⃣  ❕  5️⃣     OK  OK  OK\n"
        let "sred += $res"
    elif [ $res -gt 5500 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   4️⃣  ❕  5️⃣     OK  OK  OK  OK\n"
        let "sred += $res"
    elif [ $res -gt 0 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m   5️⃣  ❕  5️⃣     OK  OK  OK  OK  OK\n"
        let "sred += $res"
    fi
elif [ $dif -eq 5 ]
then
    if [ $res -gt 12 ]
    then
        printf "Test result on $from..$to randoms: \033[36m$res\033[m    KO\n"
    else
        printf "Test result on $from..$to randoms: \033[36m$res\033[m    OK\n"
    fi
else
    printf "Test result on $from..$to randoms: \033[36m$res\033[m"
fi
done


let "koef = $sred / $count"
if [ $dif -eq 100 ]
    then
        printf "\nmax = $max\tmin = $min\n"
    if [ $koef -gt 1300 ]
    then
    printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  0️⃣     ❗️"
    elif [ $koef -gt 1300 ]
    then
    printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  1️⃣     OK"
    elif [ $koef -gt 1100 ]
    then
    printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  2️⃣     OK  OK"
    elif [ $koef -gt 900 ]
    then
    printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  3️⃣     OK  OK  OK"
    elif [ $koef -gt 700 ]
    then
    printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  4️⃣      OK  OK  OK  OK"
    elif [ $koef -gt 0 ]
    then
    printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  5️⃣      OK  OK  OK  OK  OK"
    fi
elif [ $dif -eq 500 ]
    then
        printf "\nmax = $max\tmin = $min\n"
        if [ $koef -gt 11500 ]
        then
        printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  0️⃣     ❗️"
        elif [ $koef -gt 10000 ]
        then
        printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  1️⃣     OK"
        elif [ $koef -gt 8500 ]
        then
        printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  2️⃣     OK  OK"
        elif [ $koef -gt 7000 ]
        then
        printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  3️⃣     OK  OK  OK"
        elif [ $koef -gt 5500 ]
        then
        printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  4️⃣      OK  OK  OK  OK"
        elif [ $koef -gt 0 ]
        then
        printf "\nMiddle value: \033[33m$koef\033[m   Grade is :  5️⃣      OK  OK  OK  OK  OK"
        fi
fi

printf "\n💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠 💠\n"
